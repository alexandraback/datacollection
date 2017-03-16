/*
 *Author:       Zhaofa Fang
 *Created time: 2014-05-04-00.27 Saturday
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
#include <stack>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
#define DEBUG(x) cout<< #x << ':' << x << endl
#define FOR(i,s,t) for(int i = (s);i <= (t);i++)
#define FORD(i,s,t) for(int i = (s);i >= (t);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define REPD(i,n) for(int i=(n-1);i>=0;i--)
#define PII pair<int,int>
#define PB push_back
#define ft first
#define sd second
#define lowbit(x) (x&(-x))
#define INF (1<<30)
#define eps (1e-8)

const int maxn = 10;
string str[maxn];
int n,m;
vector<int> vec[maxn];
int perm[10];

void init(){
    REP(i,maxn)vec[i].clear();
}
stack<int> S;

bool find(int pre,int cur){
    int sz = vec[pre].size();
    REP(j,sz){
        if(vec[pre][j] == cur){
            return true;
        }
    }
    return false;
}
bool check(){
    while(!S.empty())S.pop();
    S.push(perm[1]);
    FOR(i,2,n){
        int cur = perm[i];
        while(!S.empty() && !find(S.top(),cur)){
            S.pop();
        }
        if(!S.empty())S.push(cur);
        else return false;
    }
    return true;
}
void solve(){
    string ans = "";
    FOR(i,1,n)perm[i] = i;

    do{
        if(check()){
            string tmp = "";
            FOR(i,1,n)tmp += str[perm[i]];
            if(ans == "")ans = tmp;
            else if(ans > tmp)ans = tmp;
        }

    }while(next_permutation(perm+1,perm+n+1));
    cout<<ans<<endl;
}
int main(){
    freopen("C-small-attempt0.in","r",stdin);
    freopen("out","w",stdout);
    int T;
    cin>>T;
    FOR(cas,1,T){
        printf("Case #%d: ",cas);
        init();
        cin>>n>>m;
        FOR(i,1,n)cin>>str[i];
        REP(i,m){
            int u,v;
            cin>>u>>v;
            vec[u].PB(v);
            vec[v].PB(u);
        }
        solve();
    }
    return 0;
}
