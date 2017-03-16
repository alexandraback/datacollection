#include <iostream>
#include <map>
using namespace std;
typedef map<int,int> profile;
profile operator+(const profile& p1, const profile& p2){
    profile ret;
    for (profile::const_iterator it=p1.begin();it!=p1.end();++it)
        ret[it->first]+=it->second;
    for (profile::const_iterator it=p2.begin();it!=p2.end();++it)
        ret[it->first]+=it->second;
    return ret;
}
profile read_profile(int l){
    profile ret;
    while (l--){
        int key;cin>>key;
        ret[key]++;
    }
    return ret;
}
profile start;
int n;
profile p[200];
int t[200];
int dyn[1<<20];
int main(){
    int tnum;cin>>tnum;
    int tcou=0;
    while (tnum--){
        int k;
        cin>>k>>n;
        start = read_profile(k);
        for (int i=0;i<n;++i){
            int num;cin>>t[i]>>num;
            p[i]=read_profile(num);
        }
        for (int i=0;i<(1<<n);++i)
            dyn[i]=0;
        for (int mask=0;mask<(1<<n);++mask){
            profile cur=start;
            for (int i=0;i<n;++i)
                if ((mask&(1<<i))==0){
                    cur=cur+p[i];
                    --cur[t[i]];
                }
            bool bad=false;
            for (profile::iterator it=cur.begin();it!=cur.end();++it)
                if (it->second<0)
                    bad=true;
            if (bad)
                continue;
            if (mask==0){
                dyn[mask]=-1;
                continue;
            }
            for (int i=n-1;i>=0;--i)
                if ((mask&(1<<i)) && cur[t[i]]>0){
                    int lmask=mask^(1<<i);
                    if (dyn[lmask]!=0)
                        dyn[mask]=i+1;
                }
        }
        int mask=(1<<n)-1;
        cout<<"Case #"<<++tcou<<":";
        if (dyn[mask]==0){
            cout<<" IMPOSSIBLE"<<endl;
        }
        else{
            while (mask>0){
                cout<<' '<<dyn[mask];
                mask^=(1<<(dyn[mask]-1));
            }
            cout<<endl;
        }
    }
    return 0;
}
