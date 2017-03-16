#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define f first
#define s second
#define mp make_pair
int j,p,s,k;
int jp[15][15],ps[15][15],js[15][15],jps[15][15][15];
vector < pair < int , pair < int , int > > > v;
void solve(){
    int a,b,c,ms,mc;
    memset(jp,0,sizeof jp);
    memset(ps,0,sizeof ps);
    memset(js,0,sizeof js);
    memset(jps,0,sizeof jps);
    v.clear();
    for(a=1;a<=j;a++)
        for(b=1;b<=p;b++)
            if(jp[a][b]<k){
                ms=100000;
                mc=0;
                for(c=1;c<=s;c++)
                    if(js[a][c]<k && ps[b][c]<k && jps[a][b][c]==0 && js[a][c]+ps[b][c]<ms){
                        ms=js[a][c]+ps[b][c];
                        mc=c;
                    }
                if(mc){
                    v.push_back(mp(a,mp(b,mc)));
                    jp[a][b]++;
                    js[a][mc]++;
                    ps[b][mc]++;
                    jps[a][b][mc]=1;
                    b--;
                }
            }
}
void write(){
    int i;
    cout<<v.size()<<endl;
    for(i=0;i<v.size();i++)
        cout<<v[i].f<<" "<<v[i].s.f<<" "<<v[i].s.s<<endl;
}
int main(){
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
    int i,t;
    cin>>t;
    for(i=1;i<=t;i++){
        cin>>j>>p>>s>>k;
        cout<<"Case #"<<i<<": ";
        solve();
        write();
    }
    return 0;
}
