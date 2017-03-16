#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<string.h>
#include<cstring>
#include<stack>
#include<queue>
#include<cassert>
 
using namespace std;
 
#define LL long long int 
#define PII pair<int,int> 
#define PB push_back
#define MP make_pair
#define INF 1000000000
 
vector<PII> a,b;
LL tottimea,tottimeb;
int N, M;
map<pair<pair<int,int> ,pair<LL,LL > >,LL  >mp;
LL lcs(int x,int y,LL r,LL s){
        if(x == N || y == M)
                return 0;
        if(mp.count(MP(MP(x,y),MP(r,s)))!=0)
                return mp[MP(MP(x,y),MP(r,s))];
        LL ans=0;
        if(a[x].second==b[y].second && r>0 && s>0){
                LL mn = min(r, s);
                ans=max(ans,mn+lcs(x,y,r-mn,s-mn));
        } else ans=max(lcs(x,y+1,r,b[y+1].first),lcs(x+1,y,a[x+1].first,s));
        
        return mp[MP(MP(x,y),MP(r,s))]=ans;
}
int main(){
        LL i,t,x,y;
        int n,m,ts=1;
        scanf("%Ld",&t);
        while(t--){
                tottimea=tottimeb=0;
                a.clear();
                b.clear();
                mp.clear();
                scanf("%d %d",&n,&m);
                for(i=0;i<n;i++){
                        scanf("%Ld %Ld",&x,&y);
                        a.PB(MP(x,y));
                }
                for(i=0;i<m;i++){
                        scanf("%Ld %Ld",&x,&y);
                        b.PB(MP(x,y));
                }
                N = n, M = m;
                printf("Case #%d: %Ld\n",ts++,lcs(0,0,a[0].first,b[0].first));
        }
        return 0;
}

