#include<iostream>
#include<vector>
#include<set>
#include<map>

using namespace std;

class mysum{
    public:
        mysum(){};
        mysum(int x){
            data.insert(x);
        };
        mysum(const mysum& o){
            data=o.data;
        }
        mysum add(int x){
            mysum tmp;
            tmp.data=data;
            tmp.data.insert(x);
            return tmp;
        }
        set<int> data;
};
int main(){
    int N;
    cin>>N;
    for(int num=1;num<=N;++num){
        int T;
        cin>>T;
        vector<int> data;
        for(int i=0;i<T;++i){
            int tmp;
            cin>>tmp;
            data.push_back(tmp);
        }
        map<int,mysum> count;
        for(int i=0;i<T;++i){
            mysum tmp(data[i]);
            count[data[i]]=tmp;
        }
        mysum s1,s2;
        bool end=false;
        for(int i=1;i<T;++i){
            map<int,mysum>::iterator iter;
            for(iter=count.begin();iter!=count.end();++iter){
                if(iter->second.data.size()==i){
                    for(int j=0;j<T;++j){
                        mysum tmp=iter->second.add(data[j]);
                        if(tmp.data.size()==i+1){
                            if(count.find(iter->first+data[j])==count.end()){
                                count[iter->first+data[j]]=tmp;
                            }else{
                                s1=tmp;
                                s2=count[iter->first+data[j]];
                                set<int> s3;
                                if(s1.data.size()==s2.data.size()){
                                    set_difference(s1.data.begin(),s1.data.end(),s2.data.begin(),s2.data.end(),inserter(s3,s3.begin()));
                                    if(s3.size()==0)
                                        continue;
                                }
                                end=true;
                                goto out;
                            }
                        }
                    }
                }
            }
        }
        out:
        cout<<"Case #"<<num<<":"<<endl;
        if(end){
            set<int>::iterator iter;
            for(iter=s1.data.begin();iter!=s1.data.end();++iter){
                    cout<<*iter<<' ';
            }
            cout<<endl;
            for(iter=s2.data.begin();iter!=s2.data.end();++iter){
                    cout<<*iter<<' ';
            }
            cout<<endl;
        }else{
            cout<<"Impossible"<<endl;

        }
    }
    return 0;
}
