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

int r,n,m,k;
int a[100];
bool OK;
bool check(int x){
    if(x==1)return false;
    REP(i,k){
        int tmp = a[i];
        int res = x;
        REP(j,n){
            if(tmp%(res%10)==0){
                tmp/=(res%10);
            }
            res/=10;
        }
        if(tmp!=1)return false;
    }
    return true;
}
void dfs(int cur,int res){
    if(OK)return;
    if(cur>=n){
        if(check(res)){
            OK = 1;
            printf("%d\n",res);
        }
        return;
    }
    FOR(i,2,m){
        dfs(cur+1,res*10+i);
    }
}
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	int T;
	cin>>T;
	FOR(cas,1,T){
        printf("Case #%d:\n",cas);
        cin>>r>>n>>m>>k;
        REP(i,k)scanf("%d",&a[i]);
        REP(j,r){
            OK = 0;
            dfs(0,0);
            if(!OK){
                REP(i,n)printf("2");
                puts("");
            }
        }
	}
	return 0;
}
