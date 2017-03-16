//#pragma comment(linker, "/stack:1000000")

#include <ctime>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>

using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define RFOR(i, b, a) for(int i = b - 1; i >= a; --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)

#define MIN(A, B) ((A) < (B) ? (A) : (B))
#define MAX(A, B) ((A) > (B) ? (A) : (B))
#define ABS(A) ((A) < 0 ? (-(A)) : (A))
#define ALL(V) V.begin(), V.end()
#define SIZE(V) (int)V.size()
#define pb push_back
#define mp make_pair
#define EPS 1e-7
#define Pi 3.14159265358979
#define FILL(a,v) memset(a,v,sizeof(a))

typedef long long Long;
typedef unsigned long long ULong;
typedef unsigned int Uint;
typedef unsigned char Uchar;
typedef vector <int> VI;
typedef pair <int, int> PII;

double a[1000];
double res[1000];
int num[1000];
double oa[1000];
int n;

bool isOk(double w, int num)
{
	double q = a[num]+w;
	w = 1-w;
	REP(i,n)
		if(i != num)
			w -= max(0.0, q-a[i]);
	return w<0;
}

double bs(double i)
{
	double left = 0;
	double right = 1;
	while(right-left>1e-9)
	{
		double mid = (left+right)/2;
		if(isOk(mid, i))
			right = mid;
		else
			left = mid;
	}
	return left;
}

void solTest(int T)
{
	cin>>n;
	double X = 0;
	REP(i,n)
	{
		cin>>a[i];
		X += a[i];
	}

	REP(i,n)
	{
		a[i] /= X;		
	}

	double P =  0;
	REP(i,n)
	{
		res[i] = bs(i);		
	}
	printf("Case #%d:", T);
	REP(i,n)
		printf(" %.7lf", 100*res[i]);
	puts("");
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	REP(i,T)
		solTest(i+1);
	return 0;
}