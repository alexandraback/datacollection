#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1000;
int N,ans;
int d[maxn],n[maxn],w[maxn],e[maxn],s[maxn],deld[maxn],delp[maxn],dels[maxn];
struct T1{
    int w,e,s,day;
}att[1000000];
int wall[maxn];
int tot;
void init(){
    tot=0; ans=0;
    memset(wall,0,sizeof(wall));
    scanf("%d",&N);
    for (int i=1;i<=N;i++){
        scanf("%d%d%d%d%d%d%d%d",&d[i],&n[i],&w[i],&e[i],&s[i],&deld[i],&delp[i],&dels[i]);
        w[i]+=200; e[i]+=200;
        for (int j=0; j<n[i]; j++){
            int day=d[i]+j*deld[i];
            int ww=w[i]+j*delp[i];
            int ee=e[i]+j*delp[i];
            int ss=s[i]+j*dels[i];
            att[tot].day=day;
            att[tot].w=ww;
            att[tot].e=ee;
            att[tot].s=ss;
            //cout<<day<<' '<<ww<<' '<<ee<<' '<<ss<<endl;
            tot++;
        }
    }
}
bool cmp(T1 a,T1 b){
    if (a.day==b.day)
    return a.s<b.s;
    return a.day<b.day;
}
void run(){
    sort(att,att+tot,cmp);
    int s=0,t=0;
    for (int ti=0;ti<=7760600; ti++){
        if (t>=tot) break;
        if(ti!=att[s].day) continue;
        t=s;
        while (att[t].day==att[s].day) t++;
        for (int i=s; i<t;i++)
        for (int j=att[i].w; j<att[i].e; j++){
            if (att[i].s>wall[j]){
                ans++;
                break;
            }
        }
        for (int i=s; i<t; i++)
        for (int j=att[i].w; j<att[i].e; j++)
        wall[j]=max(wall[j],att[i].s);
        s=t;
    }
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T; cin>>T;
    for (int tt=1;tt<=T;tt++){
        printf("Case #%d: ",tt);
        init();
        run();
        cout<<ans<<endl;
    }
}
