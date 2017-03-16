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
#define sz size()
#define eps 1e-8

const int MOD(1000000007);
const int INF((1<<30)-1);
const int MAXN(10005);

int v[MAXN],idx[MAXN];

long long E,R;

set<PII>s1;
set<PII,greater<PII> >s2;

bool compare(int i,int j){
    return v[i]>v[j];
}

long long chkup(int x){

    if(s2.empty()) return E;

    if(s2.upper_bound(PII(x,0))==s2.end()) return E;

    PII num=*s2.upper_bound(PII(x,0));

    return min(E,num.Y+R*(x-num.X));
}

long long chklow(int x){

    if(s1.empty()) return 0;

    if(s1.upper_bound(PII(x,0))==s1.end()) return 0;

    PII num=*s1.upper_bound(PII(x,0));

    return max(0ll,num.Y-R*(num.X-x));
}

void solve(int t){

    int n;
    cin >> E >> R >> n;

    REP(i,n)
    {
        S("%d",&v[i]);
        idx[i]=i;
    }

    sort(idx,idx+n,compare);

    s1.clear();
    s2.clear();

    long long sum=0;

    REP(i,n)
    {
        int k=idx[i];

        long long x1=chkup(k),x2=chklow(k);

        sum=sum+(x1-x2)*v[k];

        s2.insert(PII(k,x2));
        s1.insert(PII(k,x1));
    }

    P("Case #%d: %I64d\n",t,sum);
}

int main(){

    freopen("1input.txt","r",stdin);
    freopen("1output.txt","w",stdout);

    int t;
    S("%d",&t);
    FOR(i,1,t)
     solve(i);

}
