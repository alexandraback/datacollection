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

vector <LL> good;
int t, all;
LL a, b;
bool pal(LL n) {
	int c[20], cnt = 0;
	LL k = n;
	while (k) {
		c[cnt++] = k % 10;
		k /= 10;
	}
	while (n) {
		if (c[--cnt] != n % 10)
			return false;
		n /= 10;
	}
	return true;
}
int find_left(LL k) {
	int low = 0, high = all - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (good[mid] == k)
			return mid;
		if (good[mid] > k)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return low;
}
int find_left_2(LL k) {
	int low = 0, high = all - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (good[mid] == k)
			return mid;
		if (good[mid] > k)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return high;
}


int main()  
{
    ifd();
	
	FOR(i, 1, 10000000 + 1) {
		LL t = 1LL * i * i;
		if (pal(i) && pal(t))
			good.push_back(t);
	}
	all = good.size();

	scanf("%d", &t);
	FOR(cs, 1, t + 1) {
		scanf("%lld %lld", &a, &b);
		printf("Case #%d: %d\n", cs, find_left_2(b) - find_left(a) + 1);
	}


	tme();
    return 0;
}
