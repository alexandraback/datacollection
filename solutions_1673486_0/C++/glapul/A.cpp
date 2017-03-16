
//Michał Glapa
#include<cstdio>
#include<set>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<cstdlib>
#include<time.h>
#include<stack>
#include<cmath>
#include<iostream>
#include<cstring>
using namespace std;
#define ret return
#define FOR(i,j,k) for(int i=j;i<k;i++)
#define FORD(i,j,k) for(int i=j;i>=k;i--)
#define ll long long
#define pii  pair<int, int>
#define vi vector<int >
#define pb push_back
#define mp make_pair
#define make(n) int n; scanf("%d",&n)
#define st first
#define nd second
#define INF 2000000001
#define VAR(i,n) __typeof(n) i = (n)
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();i++)
#define FORDEACH(i,c) for( VAR(i,(c).rbegin(),i!=(c).rend();i++)
#define REP(i,n) FOR(i,0,n)
#define ld long double
const long long INFLL = (ll)INF * (ll)INF;
const ld EPS = 10e-9;

#define MAXN

int main()
{
    make(t);
    FOR(w,1,t+1)
    {
        make(a); make(b);
        vector<double> p;
        p.pb(1);
        FOR(i,0,a)
        {
            double x;
            scanf("%lf",&x);
            p.pb(x);
        }
        double correct_chance = 1, result = 999999999;
        FOR(i,0,a+1)
        {
            correct_chance*=p[i];
            result = min(result,correct_chance*(a-i+b-i+1)+(1-correct_chance)*(a-i+b-i+1+b+1));
        }
        result = min(result, (double)(1+b+1));
        printf("Case #%d: %lf\n",w,result);
    }
}

