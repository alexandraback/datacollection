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
#include <iterator>

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
bool readl(Long &n)	{ return scanf("%I64d",&n) == 1; }
bool readd(double &n){ return scanf("%lf",&n) == 1; }
bool reads(string &s){ s = ""; int n = scanf("%s",BUFFER); if(n == 1)s = BUFFER; return n == 1; }
bool readln(string &s){ char *valid = gets(BUFFER); if(valid)s = BUFFER; return ((bool)valid); }

const Long maxn = 10000000;
#define sq(n) ((n)*(n))

//bool visit[maxn];
bool ispalindrom(Long n){
    stringstream s;
    s << n;
    string ss = s.str();
    Long i,j;
    i = 0; j = sz(ss)-1;
    while(i<j){
        if(ss[i] != ss[j]) return false;
        i++; j--;
    }
    return true;
}

vector<Long> fs;

void sieve(){
    Long i;
//    CLR(visit,false);
//    Long r = sqrt(maxn);
    for(i=1;i<= maxn;i++){
        if(ispalindrom(i)&&ispalindrom(sq(i))) fs.pb(sq(i));
    }
}

//int cs[maxn];
//
//void gen(){
//    int i,c;
//    cs[0] = 0;
//    fo(i,1,maxn){
//        if(visit[i]){
//            cs[i] = cs[i-1]+1;
//        }
//        else cs[i] = cs[i-1];
//
//    }
//}

int main()
{
	#ifdef localhost
//	freopen("G:\\test.in","r",stdin);
	freopen("G:\\C-large-1.in","r",stdin);
	//freopen("G:\\test.out","w",stdout);
	freopen("G:\\C-large-1.out","w",stdout);
	#endif

	sieve();

	int t,kase = 0;
	Long a,b;
	readn(t);

//	printf("%d\n", sz(fs));
//    int i;
//    foo(i,0,fs){
//        printf("%I64d ", fs[i]);
//    }
//    printf("\n");

	while(t--){
        readl(a); readl(b);
//        Long aa = *lower_bound(li(fs),a), bb= *(upper_bound(li(fs),b)-1);
//        printf("%I64d %I64d\n", aa,bb);

        int dif =  upper_bound(li(fs),b)-lower_bound(li(fs),a);
        printf("Case #%d: %d\n", ++kase, dif);
	}


	return 0;
}

