/*
  ------------------------- Hachiikung ---------------------------------
  ---------------------- Worrachate Bosri ------------------------------
  ------ Faculty of Computer Engineering Chulalongkorn University ------
*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<set>
#include<map>
#include<string>
#include<utility>
using namespace std;
#define REP(i,FN) for(int i=0;i<FN;i++)
#define FOR(i,ST,FN) for(int i=ST;i<=FN;i++)
#define FORD(i,FN,ST) for(int i=FN;i>=ST;i--)
#define FORX(i,c) for(typeof(c.begin())i=c.begin();i!=c.end();i++)
#define pause system("pause")
#define S scanf
#define P printf
#define X first
#define Y second
#define pb push_back
#define PII pair<int,int>
#define mp make_pair
#define sz size()
#define eps 1e-8

const int MOD(1000000007);
const int INF((1<<30)-1);
const int MAXN();

map<pair<int,PII>,long long>dp;

long long K;

long long f(int i,long long a,long long b){

    if(a<0 || b<0) return 0;

    if(i==0) return 0;

    pair<int,PII> k = make_pair(i,PII((int)a,(int)b));

    if(dp.count(k)) return dp[k];

    long long num = (1<<(i-1));

    if((K&num) == 0)
    {
        dp[k] += f(i-1,min(a,num-1),min(b,num-1));
        dp[k] += f(i-1,min(a,num-1),b-num);
        dp[k] += f(i-1,a-num,min(b,num-1));

        long long c1 = max(0ll,a-num+1), c2 = max(0ll,b-num+1);
        dp[k] += c1*c2;
    }

    else
    {
        dp[k] += f(i-1,a-num,b-num);
    }

    return dp[k];
}

void solve(int test){

    long long a,b;
    cin >> a >> b >> K;

    K--;
    dp.clear();

    P("Case #%d: %I64d\n",test,(a*b)-f(30,a-1,b-1));
}

int main(){

    freopen("1input.txt","r",stdin);
    freopen("1output.txt","w",stdout);

    int t;
    S("%d",&t);
    FOR(i,1,t)
        solve(i);

}

