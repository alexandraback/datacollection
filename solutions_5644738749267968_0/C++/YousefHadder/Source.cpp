#define _CRT_SECURE_NO_WARNINGS
#include <set>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <cstdio>
#include <vector>
#include <cctype>
#include <climits>
#include <ctime>
#include <sstream>
#include <cstdlib>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define fast ios_base::sync_with_stdio(false)

#define si(a) cin>>a
#define si2(a,b) cin>>a>>b
#define si3(a,b,c) cin>>a>>b>>c

#define read freopen("in.in","r",stdin)
#define write freopen("out.in","w",stdout)

#define rep(i,a,b) for(int i=a;i<b;++i)
#define rep_(i,a,b) for(int i=a;i>=b;--i)
#define wh(t) while(t--)

#define Set(a,b) memset(a,b,sizeof a)
#define Vset(a,b,c) a.resize(b,c)
#define clr(a) a.clear()
#define Sz(a) a.size()
#define Arrsz(a) sizeof a / sizeof a[0]
#define All(a) (a.begin(),a.end())
#define mp make_pair
#define mpp(a,b,c) mp(mp(a,b),c)

#define Bug puts("Bug")
#define Nl puts("");
#define Vi vector
#define pr pair
#define N (int)1e5
#define oo 2e6

#define isnum(a) (a>=48 && a<=57)
#define isS(a) (a>='a' && a<='z')
#define isU(a) (a>='A' && a<='Z')
#define toS(a) (isU(a)?a+32:a)
#define toU(a) (isS(a)?a-32:a)
#define toC(a) a&15

typedef long long lli;
typedef unsigned long long llu;
typedef Vi<int> vi;
typedef pr<int, int> pii;
typedef pr<pii, int> piii;
typedef map<int, int>::iterator Mit;
typedef set<lli>::iterator Sit;

int gcd(int a, int b){ return (a == 0) ? b : (b == 0) ? a : gcd(b, a%b); }
int lcm(int x, int y){ return x*y / gcd(x, y); }
int str_div(char *s, int n){ int y = 0, ln = strlen(s); rep(i, 0, ln)y = (y * 10 + (s[i] - 48)) % n; return y; }

double get(){
	double y, s = 1, i = 10;
	y = 0;
	char c = getchar();
	while (!isnum(c)){
		if (c == '-')s = -1; c = getchar();
	}
	while (isnum(c))y = y * 10 + (toC(c)), c = getchar();
	if (c != '.')return y*s;
	c = getchar();
	while (isnum(c))y = y + (toC(c)) / i, i = i * 10, c = getchar();
	return y*s;
}

int dx[] = { 2, 2, -2, -2, 1, -1, 1, -1 };
int dy[] = { 1, -1, 1, -1, 2, 2, -2, -2 };


double a[1000], b[1000], c[1000], e[1000];


int main()
{
	read; write;
	int t = get();
	while (t--)
	{

		static int cas = 1;
		printf("Case #%d: ", cas++);
		int n = get(), w = 0, d = 0;

		rep(i, 0, n){ a[i] = c[i] = get(); }
		rep(i, 0, n){ b[i] = e[i] = get(); }
		sort(a, a + n);
		sort(b, b + n);
		sort(c, c + n);
		sort(e, e + n);
		/*rep(i, 0, n){ cout << a[i] << " "; }
		Nl;
		rep(i, 0, n){ cout << b[i] << " "; }
		Nl;*/
		rep_(i, n - 1, 0)
		{
			double x = a[i], ans = oo;
			int pos = -1, p1 = -1;
			rep(j, 0, n)
			{
				if (b[j] > x){ pos = j; break; }
				if (b[j] != -1 && p1 != -1){ p1 = j; }
			}
			if (pos == -1){ w++;  if (p1 != -1)b[p1] = -1; }
			else b[pos] = -1;
		}
		int f;
		rep(i, 0, n)
		{
			f = 0;
			rep(j, 0, n)
			{
				if (c[i] > e[j]){  e[j] = oo;  f = 1; break; }
			}
			d += f;
		}

		printf("%d %d\n",d, w);
	}
}