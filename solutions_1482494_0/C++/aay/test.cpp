#include<iostream>
#include<vector>
#include<list>
#include<iomanip>

using namespace std;

class level{
    public:
        int first;
        int second;
        int mark;
        bool operator<(const level& o) const{
            return second<o.second;
        }
};

int main(){
    int N;
    cin>>N;
    for(int num=1;num<=N;++num){
        int round;
        cin>>round;
        list<level> levels;
        for(int i=0;i<round;++i){
            int t1,t2;
            cin>>t1>>t2;
            level l;
            l.first=t1;
            l.second=t2;
            l.mark=false;
            levels.push_back(l);
        }
        levels.sort();
        int stars=0,count=0;
        bool bad=false;
        list<level>::iterator iter;
        list<level>::reverse_iterator iter2;
        int next=0;
        for(iter=levels.begin();iter!=levels.end();){
            if(iter->second<=stars){
                if(iter->mark==false)
                    stars+=2;
                else 
                    stars+=1;
                iter=levels.erase(iter);
                ++count;
                continue;
            }else{
                next=iter->second;
            }
            int old=stars;
            for(iter2=levels.rbegin();iter2!=levels.rend();++iter2){
                if(iter2->first<=stars){
                    if(iter2->mark==false){
                        stars+=1;
                        iter2->mark=true;
                        ++count;
                    }
                }
                if(stars>=next)
                    break;
            }
            if(old==stars){
                bad=true;
                break;
            }
            iter=levels.begin();
        }
        if(bad==false)
            cout<<"Case #"<<num<<": "<<count<<endl;
        else 
            cout<<"Case #"<<num<<": Too Bad"<<endl;
    }
    return 0;
}
