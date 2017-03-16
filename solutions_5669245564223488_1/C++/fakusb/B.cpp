#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <cstdlib>

using namespace std;

int T;
vector<int> res;

    #define M 1000000007

long long fac(int i){
    long long r = 1;
    while(i>0){
        r*=i;
        i--;
        r%=M;
    }
    return r;
}

long long  solve(){
    vector<string> cars;
    int N;
    scanf("%i\n",&N);
    for(int i=0;i<N;i++){
        cars.push_back("");
        getline(cin,cars[i],i<N-1?' ':'\n');
    }
    vector<int> single;
    vector<pair<int,int>> normal;
    vector<int> inMiddle;
    for(int i=0;i<cars.size();i++){
        int k=0;
        int char1 = cars[i][0];
        while(k+1<cars[i].size() && cars[i][k+1]==char1){
            k++;
        }
        if(k+1==cars[i].size()){
            single.emplace_back(char1-'a');
        }
        else{
            while(true){
                int char2 = cars[i][k+1];
                while(k+1<cars[i].size() && cars[i][k+1]==char2){
                    k++;
                }
                if(k+1==cars[i].size()){
                    normal.emplace_back(char1-'a',char2-'a');
                    break;
                }
                inMiddle.emplace_back(char2-'a');
            }
        }
    }
    sort(inMiddle.begin(),inMiddle.end());
    sort(single.begin(),single.end());
    vector<int> singleCount(26,0);
    vector<int> doubleStart(26,-1);
    vector<int> doubleEnd(26,-1);
    vector<bool> usedDouble(normal.size(),false);
    vector<bool> usedSingle(26,false);
    for(int i=0;i<single.size();i++){
        singleCount[single[i]]++;
    }
    for(int i=0;i<inMiddle.size();i++){
        if(i>0 && inMiddle[i-1]==inMiddle[i]){
            return 0;
        }
        if(binary_search(single.begin(),single.end(),inMiddle[i])){
            return 0;
        }
    }
    for(int i=0;i<normal.size();i++){
        int fst = normal[i].first;
        if(doubleStart[fst]!=-1)
            return 0;
        doubleStart[fst]=i;
        if(binary_search(inMiddle.begin(),inMiddle.end(),fst)){
            return 0;
        }
        int snd = normal[i].second;
        if(doubleEnd[snd]!=-1)
            return 0;
        doubleEnd[snd]=i;
        if(binary_search(inMiddle.begin(),inMiddle.end(),snd)){
            return 0;
        }
        if(fst==snd)
            return 0;
    }
    //inMiddle now is fully checked

    
    vector<long long> parts;
    for(int i=0;i<normal.size();i++){
        if(usedDouble[i])
            continue;
        long long r=1;
        int fst = normal[i].first;
        int snd = normal[i].second;
        usedDouble[i]=true;
        r*=fac(singleCount[fst]);
        if(usedSingle[fst]){
                r=0;
        }
        usedSingle[fst]=true;

        r*=fac(singleCount[snd]);
        if(usedSingle[snd]){
                r=0;
        }
        usedSingle[snd]=true;
        r%=M;
        while(doubleEnd[fst]!=-1 && r>0){
            int newFront = doubleEnd[fst];
            if(normal[newFront].second != fst){
                cout<<"PANIC"<<endl;
                exit(-1);
            }
            fst = normal[newFront].first;
            if(usedDouble[newFront]){
                r=0;
            }
            usedDouble[newFront]=true;
            r*=fac(singleCount[fst]);
            if(usedSingle[fst]){
                r=0;
            }
            usedSingle[fst]=true;
            r%=M;
        }
        while(doubleStart[snd]!=-1 && r>0){
            int newEnd = doubleStart[snd];
            if(normal[newEnd].first != snd){
                cout<<"PANIC2"<<endl;
                exit(-1);
            }
            snd = normal[newEnd].second;
            if(usedDouble[newEnd]){
                r=0;
            }
            usedDouble[newEnd]=true;
            r*=fac(singleCount[snd]);
            if(usedSingle[snd]){
                r=0;
            }
            usedSingle[snd]=true;
            r%=M;
        }
        r%=M;
        parts.emplace_back(r);
    }
    for(int i=0;i<26;i++){
        if(!usedSingle[i] && singleCount[i]>0)
            parts.emplace_back(fac(singleCount[i]));
    }
    long long  ret = 1;
    for(auto pa : parts){
        ret *=pa;
        ret %=M;
    }
    ret*=fac(parts.size());
    ret%=M;
    return ret;
}

int main(){
    cin>>T;
    res.resize(T+1);
    for(int t=1;t<=T;t++){
        res[t]=solve();
    }
    for(int t=1;t<=T;t++){

        cout<<"Case #"<<t<<": "<<res[t]<<endl;
    }
    return 0;
}