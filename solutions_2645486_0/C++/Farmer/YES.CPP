/*
 *Author:       Zhaofa Fang
 *Created time: 2013-04-27-08.54
 *Language:     C++
 */
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

typedef long long ll;
#define DEBUG(x) cout<< #x << ':' << x << endl
#define FOR(i,s,t) for(int i = (s);i <= (t);i++)
#define FORD(i,s,t) for(int i = (s);i >= (t);i--)
#define REP(i,n) for(int i=0;i<n;i++)
#define REPD(i,n) for(int i=n-1;i>=0;i--)
#define PII pair<int,int>
#define PB push_back
#define MP make_pair
#define ft first
#define sd second
#define lowbit(x) (x&(-x))
#define INF (1<<30)

int v[10011];
int e,r,n,gain;
vector<int>tmp,tmp1;
void dfs(int cur,int tot,int nowe){
    if(cur>=n){
        gain = max(gain,tot);
        //DEBUG(gain);
        //EP(i,tmp.size())DEBUG(tmp[i]),DEBUG(tmp1[i]);
        return;
    }
    REP(i,nowe+1){
        //tmp.PB(i);tmp1.PB(v[cur]);
        dfs(cur+1,tot+i*v[cur],min(nowe-i+r,e));
        //tmp.pop_back();tmp1.pop_back();
    }
}
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	int T;
	cin>>T;
	FOR(cas,1,T){
        printf("Case #%d: ",cas);
        scanf("%d%d%d",&e,&r,&n);
        REP(i,n)scanf("%d",&v[i]);
        gain = 0;
        dfs(0,0,e);
        printf("%d\n",gain);
	}
	return 0;
}
