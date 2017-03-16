#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<iterator>
#include<algorithm>
#define f first
#define s second
using namespace std;

int deg[205],g[205][205],w[205][205],n,pa[205];
bool bi[205],bg[205][205];
priority_queue< pair<int,int> >q;

void find_path(int i){
   // printf("%d<-",i);
    if(i==1) return;
    w[i][pa[i]]++;
    w[pa[i]][i]--;
    if(bg[i][pa[i]]==0){ bg[i][pa[i]]=1; deg[i]++; g[i][deg[i]]=pa[i]; }
    find_path(pa[i]);
}

bool flow(){
    pair<int,int>p;
    int a,b,c;
    p.f=0;
    p.s=1;
    while(!q.empty()) q.pop();
    q.push(p);
    for(a=1;a<=n;a++){ pa[a]=0; bi[a]=0; }
    while(!q.empty()){
        p=q.top(); q.pop();
        b=p.s;
        if(b==n)  return true; 
        if(bi[b]) continue; bi[b]=1;
        for(a=1;a<=deg[b];a++){
            c=g[b][a];
            if(bi[c]==1 || w[b][c]==0) continue;
            p.f=1;
            p.s=c;
            pa[c]=b;
            q.push(p);
        }
    }
    return false;
}

int main(){
    /*freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);*/
    int a,b,c,d;
    scanf("%d",&c);
    while(c--){
        scanf("%d",&n);
        for(a=1;a<n;a++){
            scanf("%d",&deg[a]);
            for(b=1;b<=deg[a];b++){
                scanf("%d",&g[a][b]);
                bg[a][g[a][b]]=1;
                if(a==1 || g[a][b]==n) w[a][g[a][b]]=1;
                else w[a][g[a][b]]=n+5;
            }
        }
        d=0;
        while(1){
            if(flow()){ d++; find_path(n);  }
            else break;
        }
        for(a=1;a<=n;a++){
            for(b=1;b<=deg[a];b++) bg[a][g[a][b]]=0;
        }
        printf("%d\n",d);
    }
    return 0;
}
