#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define fs first
#define sd second
#define MP make_pair
#define PB push_back
#define FORE(it,c) for(typeof(c.begin())it=c.begin();it!=c.end();it++)
typedef pair<int,int> II;

const int maxN=1000+10;

int n,comp[maxN];
II a[maxN];
priority_queue<II,vector<II>,greater<II> > qu;
vector<int> l[maxN*2];
int current,completed;

void solve(){
    //init
    scanf("%d",&n);
    int u,v,played=0;
    while (!qu.empty()) qu.pop();
    for (int i=0;i<maxN*2;i++) l[i].clear();
    for (int i=1;i<=n;i++){
        scanf("%d%d",&a[i].sd,&a[i].fs);
    }
    sort(a+1,a+n+1,greater<II>());
    for (int i=1;i<=n;i++){
        qu.push(MP(a[i].sd,i));
        l[a[i].fs].PB(i);
    }
    current=u=0; completed=0;
    memset(comp,0,sizeof comp);
    II d;
    //solve
    //for (int i=1;i<=n;i++) printf("%d %d\n",a[i].sd,a[i].fs);
    while (u<=current){
        FORE (it,l[u]) if (comp[*it]<2){
            current+=2-comp[*it];
            comp[*it]=2;
            played++; completed++;
            //printf("solve %d:2=%d\n",*it,current);
        }
        //printf("u=%d,star=%d\n",u,current);
        if (completed==n) break;
        if (u==current){
            //*
            for (int i=1;i<=n;i++) if (comp[i]==0&&a[i].sd<=current){
                played++; current++;
                //printf("solve %d:1=%d\n",i,current);
                comp[i]=1;
                break;
            }
            //*/
            /*
            while(!qu.empty()){
                d=qu.top();
                if (d.fs>current) break;
                qu.pop();
                if (comp[d.sd]==0){
                    comp[d.sd]=1;
                    played++; current++;
                    printf("solve %d:1=%d\n",d.sd,current);
                    break;
                }
            }
            //*/
        }
        u++;
    }
    if (completed<n) printf("Too Bad\n");
    else printf("%d\n",played);
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t; scanf("%d",&t);
    for (int i=1;i<=t;i++){
        printf("Case #%d: ",i);
        solve();
    }
    return 0;
}
