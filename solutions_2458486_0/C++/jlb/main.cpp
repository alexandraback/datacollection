#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <iterator>
#include <algorithm>
#include <ctype.h>
#include <string.h>

using namespace std;

#define MAX 201
#define KEYMAX 400

struct KeyLow{
    KeyLow(int a=0,int b=-1):key(a),low(b){}
    int key,low;
    bool operator<(KeyLow t)const{
        return low<t.low;
    }
};

int graphMatrix[MAX][MAX];

void buildKeyTarget(vector<int> key2Box,vector<vector<int> >& keyTarget,vector<int> keyLowBound){
    vector<int> mask(300,0);
//    for(int i=0;i<KEYMAX;i++){
//        keyTarget[i]=vector<int>();
//    }
    keyTarget=vector<vector<int> >(KEYMAX);
    keyLowBound=vector<int>(KEYMAX,MAX);
    int key;
    for(int i=0;i<key2Box.size();i++){
        key=key2Box[i];
//        if(mask[key]==0){
//            mask[key]=1;
//            keyTarget[key]=vector<int>();
//        }
        keyTarget[key].push_back(i);
        keyLowBound[key]=min(keyLowBound[key],i);
    }
}

bool check(vector<int>& key2Box,vector<vector<int> >& keyTarget,
           vector<int> keys,vector<vector<int> > chestKeys,vector<int>& order){
    vector<int> keyNum(401,0),singleKeyNum(401,0),needNum(401,0);
    for(int i=0;i<keys.size();i++){
        keyNum[keys[i]]++;
    }
    for(int i=0;i<order.size();i++){
        if(order[i]==-1){
            vector<int> inKey=chestKeys[i];
            for(int j=0;j<inKey.size();j++){
                keyNum[inKey[j]]++;
            }
            needNum[key2Box[i]]++;
        }
    }
    for(int i=0;i<401;i++){
        if(needNum[i]>keyNum[i])return false;
    }
    for(int i=0;i<order.size();i++){
        if(order[i]==-1){
            int key=key2Box[i];
            vector<int> inKey=chestKeys[i];
            for(int j=0;j<inKey.size();j++){
                singleKeyNum[inKey[j]]++;
            }
            if(singleKeyNum[key]==keyNum[key]){
                return false;
            }
            for(int j=0;j<inKey.size();j++){
                singleKeyNum[inKey[j]]--;
            }
        }
    }
    return true;
}

void buildGraph(vector<int>& key2Box,vector<vector<int> >& keyTarget,
                vector<int> keys,vector<vector<int> > chestKeys,int chestNum){
    memset(graphMatrix,0,sizeof(graphMatrix));
    vector<int> target;
    int key;
    for(int i=0;i<keys.size();i++){
        key=keys[i];
        target=keyTarget[key];
        for(int j=0;j<target.size();j++){
            graphMatrix[0][target[j]]=1;
        }
    }
    for(int i=0;i<chestNum;i++){
        vector<int> cKey=chestKeys[i];
        for(int j=0;j<cKey.size();j++){
            key=cKey.at(j);
            if(key!=0){
                target=keyTarget[key];
                for(int k=0;k<target.size();k++){
                    graphMatrix[i][target[k]]=1;
                }
            }
        }
    }
}

bool findOrder(vector<int>& key2Box,vector<vector<int> >& keyTarget,
               vector<int> keys,vector<vector<int> > chestKeys,int chestNum,
               vector<int>& order,int start,int doneNum){
    if(doneNum==chestNum){
        return true;
    }
    if(keys.size()==0){
        return false;
    }
    if(!check(key2Box,keyTarget,keys,chestKeys,order)){
        return false;
    }
    //cout<<"--------------------------"<<endl;
    //cout<<"doneNum:\t"<<doneNum<<"\tStart:\t"<<start<<endl;
    //for(int i=0;i<order.size();i++){
    //    cout<<order.at(i)<<' ';
    //}
    //cout<<endl;
    int key;
    set<int> mayTarget;
    for(int i=0;i<keys.size();i++){
        key=keys[i];
        vector<int> target=keyTarget[key];
        for(int j=0;j<target.size();j++){
            if(order[target[j]]==-1){
                mayTarget.insert(target[j]);
            }
        }
    }
    set<int>::iterator iter;
    for(iter=mayTarget.begin();iter!=mayTarget.end();iter++){
        key=key2Box[*iter];
        vector<int> newKeys=keys;
        vector<int> newOrder=order;
        newOrder[*iter]=doneNum+1;
        vector<int> addonKey=chestKeys.at(*iter);
        newKeys.erase(find(newKeys.begin(),newKeys.end(),key));
        for(int i=0;i<addonKey.size();i++){
            newKeys.push_back(addonKey[i]);
        }
        if(findOrder(key2Box,keyTarget,newKeys,chestKeys,chestNum,newOrder,*iter,doneNum+1)){
            order=newOrder;
            return true;
        }
    }
    return false;
}

int main(int argc,char** argv){
    int caseNum;
    int keyNum,chestNum,buf;
    string line;
    stringstream ss;
    cin>>caseNum;
    for(int num=0;num<caseNum;num++){
        cin>>keyNum>>chestNum;
        vector<int> keys;
        vector<int> key2Box(chestNum),stateOrder(chestNum,-1);
        vector<vector<int> > chestKeys(chestNum);
        vector<vector<int> > keyTarget;
        vector<int> keyLowBound;
        vector<int> order(chestNum,-1);
        keys.clear();
        stringstream ss1;
        getline(cin,line);
        getline(cin,line);
        ss1<<line;
        while(ss1>>buf){
            keys.push_back(buf);
        }
        sort(keys.begin(),keys.end());
        for(int i=0;i<chestNum;i++){
            getline(cin,line);
            stringstream ss;
            ss<<line;
            ss>>key2Box[i];
			ss>>buf;
            while(ss>>buf){
                if(buf!=0)
                chestKeys.at(i).push_back(buf);
            }
        }
        buildKeyTarget(key2Box,keyTarget,keyLowBound);
//        buildGraph(key2Box,keyTarget,keys,chestKeys,chestNum);
        bool isOk;
        isOk=findOrder(key2Box,keyTarget,keys,chestKeys,chestNum,order,0,0);
        cout<<"Case #"<<num+1<<": ";
        if(isOk){
            vector<KeyLow> rOrder(order.size());
            for(int i=0;i<order.size();i++){
                rOrder[i]=KeyLow(i,order[i]);
            }
            sort(rOrder.begin(),rOrder.end());
            for(int i=0;i<order.size();i++){
                cout<<rOrder[i].key+1<<" ";
            }
            cout<<endl;
        }else{
            cout<<"IMPOSSIBLE"<<endl;
        }
    }
    return 0;
}
