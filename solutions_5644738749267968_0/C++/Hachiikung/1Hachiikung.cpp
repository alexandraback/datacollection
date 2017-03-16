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
const int MAXN(1005);

int n;

double a[MAXN], b[MAXN];

set< double > bmin;
set< double , greater<double> > bmax;

bool good(int d){

    REP(i,n)
    {
        if(i+d >= n) break;
        if(b[i] > a[i+d]) return false;
    }

    return true;
}

int f1(){

    sort(a,a+n);
    sort(b,b+n);

    int d = 0, score = n;

    while(!good(d) && score>0)
    {
        d++;
        score--;
    }

    return score;
}

int f2(){

    sort(a,a+n,greater<double>());

    int score = 0;

    REP(i,n)
    {
        if(a[i] > *bmax.begin())
        {
            double num = *bmin.begin();
            score++;
            bmin.erase(num);
            bmax.erase(num);
        }
        else
        {
            double num = *bmin.upper_bound(a[i]);
            bmin.erase(num);
            bmax.erase(num);
        }
    }

    return score;
}

void solve(int test){

    S("%d",&n);
    REP(i,n)
        S("%lf",&a[i]);

    bmin.clear();
    bmax.clear();

    REP(i,n)
    {
        double x;
        S("%lf",&x);
        b[i] = x;
        bmin.insert(x);
        bmax.insert(x);
    }

    P("Case #%d: %d %d\n",test,f1(),f2());
}

int main(){

    freopen("1input.txt","r",stdin);
    freopen("1output.txt","w",stdout);

    int t;
    S("%d",&t);
    FOR(i,1,t)
        solve(i);

}

