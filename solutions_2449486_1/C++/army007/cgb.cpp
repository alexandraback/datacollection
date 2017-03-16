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

#define maxn 100+10

int n,m;
int b[maxn][maxn];
int r[] = { 0,1,0,-1 },
    c[] = { 1,0,-1,0 };

bool valid(int i, int j){
    if(i<0||j<0||i>=n||j>=m) return false;
    return true;
}

bool find(int i, int j, int d, int num){
    if(!valid(i,j)) return true;
    if(b[i][j]>num) return false;
    return find(i+r[d],j+c[d],d,num);
}

bool check(int i, int j){
    bool h,v;
    h = (find(i+r[0],j+c[0],0,b[i][j]) & find(i+r[2],j+c[2],2,b[i][j]));
    v = (find(i+r[1],j+c[1],1,b[i][j]) & find(i+r[3],j+c[3],3,b[i][j]));
    return (h|v);
}

bool total_check(){
    int i,j;
    fo(i,0,n){
        fo(j,0,m){
            if(!check(i,j)) return false;
        }
    }
    return true;
}

int main()
{
	#ifdef localhost
//	freopen("G:\\test.in","r",stdin);
	freopen("G:\\B-large.in","r",stdin);
	//freopen("G:\\test.out","w",stdout);
	freopen("G:\\B-large.out","w",stdout);
	#endif
    int t,kase = 0,i,j;

    readn(t);

    while(t--){
        readn(n); readn(m);
        fo(i,0,n){
            fo(j,0,m){
                readn(b[i][j]);
            }
        }
        printf("Case #%d: ",++kase );

        if(total_check()) printf("YES\n");
        else printf("NO\n");
    }

	return 0;
}

