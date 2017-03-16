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

int a[20];


int get(int mask)
{
	int r = 0;
	REP(i, 20)
	{
		if(mask&(1<<i))
			r += a[i];
	}
	return r;
}
void print(int mask)
{
	REP(i, 20)
	{
		if(mask&(1<<i))
			cout<<a[i]<<" ";
	}
	cout<<endl;
}
void solTest(int T)
{
	int n;
	cin>>n;
	REP(i,n)
		cin>>a[i];

	map<int, int> m;
	cout<<"Case #"<<T<<":\n";
	FOR(mask,1,(1<<20))
	{
		int t = get(mask);
		if(m.find(t) != m.end())
		{
			print(m[t]);
			print(mask);
			return;
		}
		m[t] = mask;
	}
	cout<<"Impossible"<<endl;
}

int main(int argc, char** argv)
{	
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	REP(i,t)
		solTest(i+1);
	return 0;
}