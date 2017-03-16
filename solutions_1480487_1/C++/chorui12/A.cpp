#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;
 
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define inf (1<<29)
#define eps (1e-9)
#define pb push_back
#define all(a) a.begin(),a.end()
#define myabs(a) ((a)<0?(-(a)):(a))
#define i64 __int64
typedef pair<int,int> pii;
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int tc, cs = 1;
	cin >> tc;
	while( tc -- )
	{
		int a[ 300 ];
		int n;
		cin >> n;
		int i;
		double sm = 0;
		for(i = 0;i < n ; i ++ )
		{
			cin >> a[ i ];
			sm += a[ i ];
		}
		double ph = (sm * 2.) / (double)n;
		double G = sm;
		int cc = n;
		for(i = 0; i < n ; i ++ )
		{
			if( a[ i ] > ph + eps )
			{
				G = G - a[ i ];
				cc --;
			}
		}
		cout <<"Case #"<<cs++<<":";
		double tot = sm + G;
		double phn = tot / (double) cc;

		for(i = 0; i < n ; i ++ )
		{
			if( a[ i ] > ph + eps )
			{
				cout <<" "<< 0.0;
			}
			else
			{
				double res = (phn - (double)a[ i ])/sm;				
				cout <<" " << res*100;
			}
		}
		cout << endl;
	}
	return 0;
}