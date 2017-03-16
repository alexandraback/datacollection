#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <cstdlib>

//Hendri's Template
#define REP(i, n) for(int i = 0, _n = (n); i < _n; i++)
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define FOREACH(it,c) for (__typeof ((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define RESET(A,v) memset(A, v, sizeof(A))
#define DEBUG(x) cout << #x << " = " << x << endl;

#define MP make_pair
#define PB push_back
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

template<class T> inline T MIN(T a, T b){return a < b?a:b;}
template<class T> inline T MAX(T a, T b){return a > b?a:b;}

template<class T> inline void getInt(T& x)
{
	char c;
	int mul = 1;
	while((c = getchar()) != EOF)
	{
		if(c == '-')mul = -1;
		if(c >= '0' && c <= '9')
		{
			x = c-'0';
			break;
		}
	}
	if(c == EOF){x = EOF;return;}
	while(c = getchar())
	{
		if(c >= '0' && c <= '9')
		{
			x = (x<<1)+(x<<3)+(c-'0');
		}
		else break;
	}
	x *= mul;
}
//End of Hendri's Template

int tcase,N,X;
int score[210];

double ans(int x)
{
	double lo = 0;
	double hi = 1;
	vector<int> v;
	REP(i,N)if(i != x)v.PB(score[i]);
	sort(v.begin(),v.end());
	for(int i = 0; i < 300; i++)
	{
		double mid = (lo+hi)/2;
		double com = score[x] + X * mid;
		double left = 1 - mid;
		bool ok = false;
		REP(j, N-1)
		{
			double need = com - v[j];
			if(need < 0)continue;
			double vote = need / X;
			if(left - vote > 1e-9)
			{
				left -= vote;
			}
			else
			{
				ok = true;
				break;
			}
		}
		if(ok)hi = mid;
			else lo = mid;
	}
	return lo;
}

int main()
{
	getInt(tcase);
	FOR(t,1,tcase)
	{
		getInt(N);
		X = 0;
		REP(i,N)
		{
			cin >> score[i];
			X += score[i];
		}
		cout << "Case #" << t << ": " ;
		REP(i,N)
		{
			printf("%.6f",ans(i)*100);
			if(i != N-1)cout << " ";
		}
		cout << endl;
	}
	return 0;
}
