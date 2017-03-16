#include <set>
#include <bitset>
#include <queue>
#include <deque>
#include <set>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <cassert>

#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>

using namespace std;

// -------------------- Khai bao cac container --------------------
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <string> vs;

typedef long long int64; //NOTES:int64
typedef unsigned long long uint64; //NOTES:uint64
typedef unsigned uint;

const double pi = acos(-1.0); //NOTES:pi
const double eps = 1e-11; //NOTES:eps
const int MAXI = 0x7fffffff;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const char dz[] = "SENW";

// -------------------- Dinh nghia lai cac phep toan --------------------
#define forn(i,a,b)     for (int i=(a),_b=(b); i<_b; i++)
#define rforn(i,b,a)    for (int i=(b)-1,_a=(a); i>=_a; i--)
#define Reset(a,b)      memset((a),(b),sizeof(a))

#define endline         putchar('\n')
#define space           putchar(' ')
#define EXIT(x)         {cout << x;return 0;}

#define fi              first
#define se              second
#define pb              push_back
#define all(x)          (x).begin(),(x).end()
#define mp(X,Y)         make_pair(X,Y)
#define foreach(i, c)   for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c, x)   ((c).find(x) != (c).end())
#define sz(a)           a.size()

#define two(x)          (1 << (x))
#define two64(x)        (((int64)(1)) << (x))
#define S(x)            scanf("%d",&x);
#define input freopen("input.txt","r",stdin);
#define output freopen("output.txt","w",stdout);
#define deb(i,a,n) for(i=0;i<n;i++){cout<<a[i]<<" ";}
#define db(x,y)          printf("%d %d\n",x,y);
#define op(x)			 printf("%d\n",x);
char str[110],str1[110];
int main()
{
	// input;
	// output;
	int n,i,j,k,l,t,s,m,ts,c1,c2,d;
	S(t);
	for(ts=1;ts<=t;ts++){
		s=0;
		S(n);S(m);S(d);
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if((i&j)<d)
					s++;
			}
		}
		printf("Case #%d: %d\n",ts,s);
	}
	return (0);
}