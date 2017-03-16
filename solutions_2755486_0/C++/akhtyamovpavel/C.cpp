#include<cstdio>
#include<ctime>
#include<cmath>
#include<cctype>

#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<set>
#include<algorithm>
#include<utility>
#include<stack>
#include<queue>
using namespace std;
#define pb push_back
#define mp make_pair
#define FILEIN "C.in"
#define FILEOUT "C.txt"
int main(){
    freopen(FILEIN,"r",stdin);
    freopen(FILEOUT,"w",stdout);
    int t;
    cin>>t;
    for(int u=1;u<=t;++u){
        int N;
        cin>>N;
        int d[N],n[N],delta_d[N],w[N],e[N],s[N],delta_p[N],delta_s[N];
        for(int i=0;i<N;++i)
            cin>>d[i]>>n[i]>>w[i]>>e[i]>>s[i]>>delta_d[i]>>delta_p[i]>>delta_s[i];
        for(int i=0;i<N;++i){
            w[i]+=4000;
            e[i]+=4000;
        }
        int res=0;

        int stena[8000];
        for(int i=0;i<8000;++i)
            stena[i]=0;
        vector<pair<int,int> > day;
        for(int i=0;i<N;++i){
            for(int j=0;j<n[i];++j){
                day.pb(mp(d[i]+delta_d[i]*(j),i));
            }
        }

        sort(day.begin(),day.end());
        //for(int i=0;i<day.size();++i){
            //cout<<"d"<<day[i].first<<" "<<day[i].second<<endl;
        //}
        vector<pair<int,int> > zap;
        vector<int> strength;
        bool issuc=false;
        for(int i=w[day[0].second];i<e[day[0].second];++i){
            if(stena[i]<s[day[0].second])
                issuc=true;
        }
        if (issuc)
            res++;
        zap.push_back(mp(w[day[0].second],e[day[0].second]));
        strength.push_back(s[day[0].second]);
        w[day[0].second]+=delta_p[day[0].second];
        e[day[0].second]+=delta_p[day[0].second];
        s[day[0].second]+=delta_s[day[0].second];
        for(int i=1;i<day.size();++i){

            if(day[i].first>day[i-1].first){

                for(int j=0;j<zap.size();++j){
                    //cout<<"Z"<<zap[j].first<<zap[j].second<<endl;
                    for(int k=zap[j].first;k<zap[j].second;++k){
                        //cout<<"PROV";
                        //cout<<k<<" "<<stena[k]<<" "<<strength[j]<<endl;
                        if(stena[k]<strength[j])
                            stena[k]=strength[j];
                    }
                }

            zap.clear();
            strength.clear();
            }
            issuc=false;
            //cout<<w[day[i].second]<<" "<<e[day[i].second]<<" "<<s[day[i].second]<<endl;
            for(int j=w[day[i].second];j<e[day[i].second];++j){
                //cout<<"stena"<<j<<" "<<stena[j]<<" "<<s[day[i].second]<<endl;
                if(stena[j]<s[day[i].second])
                    issuc=true;
            }
            if (issuc)
                res++;
            zap.push_back(mp(w[day[i].second],e[day[i].second]));
            strength.push_back(s[day[i].second]);
            w[day[i].second]+=delta_p[day[i].second];
            e[day[i].second]+=delta_p[day[i].second];
            s[day[i].second]+=delta_s[day[i].second];
        }
        cout<<"Case #"<<u<<": "<<res<<endl;
    }
    return 0;
}
