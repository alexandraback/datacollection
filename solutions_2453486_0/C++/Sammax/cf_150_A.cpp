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

int t, d[4][4];
string s;
bool check(int n) {
	int x_cnt, t_cnt;
	
	FOR(i, 0, 4) {
		x_cnt = t_cnt = 0;
		FOR(j, 0, 4) {
			x_cnt += d[i][j] == n;
			t_cnt += d[i][j] == 3;
		}
		if (x_cnt == 3 && t_cnt == 1 || x_cnt == 4)
			return true;
	}

	FOR(j, 0, 4) {
		x_cnt = t_cnt = 0;
		FOR(i, 0, 4) {
			x_cnt += d[i][j] == n;
			t_cnt += d[i][j] == 3;
		}
		if (x_cnt == 3 && t_cnt == 1 || x_cnt == 4)
			return true;
	}

	x_cnt = t_cnt = 0;
	x_cnt += (d[0][0] == n) + (d[1][1] == n) + (d[2][2] == n) + (d[3][3] == n);
	t_cnt += (d[0][0] == 3) + (d[1][1] == 3) + (d[2][2] == 3) + (d[3][3] == 3);
	if (x_cnt == 3 && t_cnt == 1 || x_cnt == 4)
			return true;

	x_cnt = t_cnt = 0;
	x_cnt += (d[0][3] == n) + (d[1][2] == n) + (d[2][1] == n) + (d[3][0] == n);
	t_cnt += (d[0][3] == 3) + (d[1][2] == 3) + (d[2][1] == 3) + (d[3][0] == 3);
	if (x_cnt == 3 && t_cnt == 1 || x_cnt == 4)
			return true;

	return false;
}
bool check_draw() {
	int cnt = 0;
	FOR(i, 0, 4)
		cnt += count(d[i], d[i] + 4, 0);
	return cnt == 0;
}
int main()  
{
    ifd();
	
	cin >> t;
	FOR(cs, 1, t + 1) {
		FOR(i, 0, 4) {
			cin >> s;
			FOR(j, 0, 4) {
				if (s[j] == '.')
					d[i][j] = 0;
				if (s[j] == 'O')
					d[i][j] = 2;
				if (s[j] == 'T')
					d[i][j] = 3;
				if (s[j] == 'X')
					d[i][j] = 1;
			}
		}
		printf("Case #%d: ", cs);
		if (check(1)) {
			printf("X won\n");
		} else if (check(2)) {
			printf("O won\n");
		} else if (check_draw()) {
			printf("Draw\n");
		} else {
			printf("Game has not completed\n");
		}
	}

	tme();
    return 0;
}
