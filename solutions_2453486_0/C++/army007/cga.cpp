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

#define maxn 10

char b[maxn][maxn];

bool comp(int i, int j, char c){
    return (b[i][j] == c || b[i][j] == 'T');
}

bool row(int i,char c){
//    if(b[i][0] == '.') return false;
    int j;
    fo(j,0,4){
        if(!comp(i,j,c)) return false;
    }
    return true;
}

bool col(int j, char c){
    int i;
    fo(i,0,4){
        if(!comp(i,j,c)) return false;
    }
    return true;
}

bool dig(char c){
    int i,j;
    bool f = true;
    fo(i,0,4){
        if(!comp(i,i,c)) { f = false; break; }
    }
    if(f) return true;
    f = true;
    for(i=0,j=3; j>= 0; i++,j--){
        if(!comp(i,j,c)) {f = false; break;}
    }

    return f;
}


int main()
{
	#ifdef localhost
	//freopen("G:\\test.in","r",stdin);
	freopen("G:\\A-small-attempt0.in","r",stdin);
	freopen("G:\\A-small-attempt0.out","w",stdout);
	#endif

	int t,i,j,kase = 0;

	bool x,filled, o;

	readn(t);

	while(t--){
        filled = true;
	    // input board
	    fo(i,0,4){
            fo(j,0,4){
                scanf(" \n%c", &b[i][j]);
                if(b[i][j]=='.') filled = false;
            }
	    }

        x = o = false;
        fo(i,0,4){
            x |= row(i,'X');
            o |= row(i,'O');
        }
        fo(j,0,4){
            x |= col(j,'X');
            o |= col(j,'O');
        }
        x |= dig('X');
        o |= dig('O');

        printf("Case #%d: ",++kase);

        if(x) { printf("X won\n"); continue; }
        if(o) { printf("O won\n"); continue; }
        if(!filled) { printf("Game has not completed\n"); continue; }
        printf("Draw\n");
	}


	return 0;
}

