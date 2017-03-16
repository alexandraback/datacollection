#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <complex>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <complex>
#include <stdio.h>
#include <cstdlib>
#include <memory.h>
#include <ctime>
#include <stack>
#ifdef SAMMAX
#include <ctime>
clock_t beg;
#endif

const double pi = 3.1415926535897932384626433832795;
double EPS = 10e-6;
const int INF = 2000000000;

//#pragma comment(linker, "/stack:1500000000")
#define sz size()
#define mp make_pair
#define pb push_back
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define MEMS(a,b) memset(a,b,sizeof(a))
#define sqr(a) ((a)*(a))
#define HAS(a,b) ((a).find(b)!=(a).end())
#define MAX(a,b) ((a>=b)?a:b)
#define MIN(a,b) ((a<=b)?a:b)
#define ABS(a) ((a<0)?-(a):a)
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define FORD(i,a,b) for (int i=(a);i>(b);--i)
#define VVI vector < vector <int> >
#define VI vector <int>
#define LL long long
#define U unsigned
#define pnt pair <int,int>
LL gcd(LL a, LL b){if (a==0) return b;return gcd(b%a,a);}

using namespace std;

void ifd() 
{
#ifdef SAMMAX
	freopen("in.txt", "r", stdin); 
	freopen("out.txt", "w", stdout); 
	beg = clock();
#else
	//freopen("robots.in", "r", stdin); 
	//freopen("robots.out", "w", stdout);
#endif	
}
void tme()
{
#ifdef SAMMAX
	fprintf(stderr,"*** Total time: %.3lf ***\n",1.0*(clock()-beg)/CLOCKS_PER_SEC);
#endif
}

int T;
int r, n, m, k;
VI anss;
int main()  
{
    ifd();

	
	
	cin >> T >> r >> n >> m >> k;
	printf("Case #1:\n");
	srand(time(NULL));
	
	FOR(i, 0, r) {
		bool found = false;
		string ans;
		FOR(j, 0, k) {
			LL t;
			cin >> t;
		}
		FOR(i, 0, n)
				cout << (rand() % (m - 2)) + 2;
			cout << endl;
	}
	
	tme();
    return 0;
}
