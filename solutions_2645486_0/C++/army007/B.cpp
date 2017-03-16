/**
*   @author     Sharif Ahmad
*   @date
*   @verdict
*   @category
*/

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <valarray>
#include <functional>

using namespace std;

#define fo(i,j,n) for(i=j;i<n;++i)
#define Fo(i,j,n) for(i=n-1;i>=j;--i)
#define foo(i,j,v) fo(i,j,sz(v))
#define Foo(i,j,v) Fo(i,j,sz(v))
#define li(v) v.begin(),v.end()
#define sz(v) ((int)v.size())
#define CLR(a,v) memset((a),(v),sizeof(a))
#define inf 1000000001
typedef long long Long;
//typedef __int64 Long;
#define pi (2*acos(0))
#define eps 1e-9

#define two(X) (1<<(X))
#define twoL(X) (((Long)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)

#define pb(x) push_back(x)
#define present(m,s) (m.find(s)!=m.end())


char BUFFER[100000 + 5];
bool readn(int &n)	{ return scanf("%d",&n) == 1; }
//bool readl(Long &n)	{ return scanf("%I64d",&n) == 1; }
bool readd(double &n){ return scanf("%lf",&n) == 1; }
bool reads(string &s){ s = ""; int n = scanf("%s",BUFFER); if(n == 1)s = BUFFER; return n == 1; }
bool readln(string &s){ char *valid = gets(BUFFER); if(valid)s = BUFFER; return ((bool)valid); }


#define maxn 15
int N,R,E;
int v[maxn];

int f(int i, int e){
    if(i<0){
        return 0;
    }
    int k,mx = -1;
    Fo(k,0,e+1){
        mx = max(mx,f(i-1,min(E,e+R-k)) + (k*v[i]));
    }
    return mx;
}


int main()
{
	#ifdef localhost
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);

//    freopen("input.txt", "r", stdin);
	#endif

	int t,kase = 0;
	int i;
	readn(t);
	while(t--){
        readn(E); readn(R); readn(N);
        fo(i,0,N){
            readn(v[i]);
        }
        int res = f(N-1,E);
        printf("Case #%d: %d\n", ++kase, res);
	}

	return 0;
}

