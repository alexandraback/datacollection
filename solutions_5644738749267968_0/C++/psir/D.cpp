#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdio>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define VI vector<int>

vector<double> x, y;

int f(int x1,int x2, int y1,int y2)
	{
	//cout << x1 << " " << x2 << " " << y1 << " " << y2 << endl;
	if ( x1 == x2 || y1 == y2 ) 
		return 0;
	if( x[x2-1] > y[y2-1] )
		return 1 + f(x1,x2-1,y1,y2-1);
	else 
		return f(x1,x2,y1,y2-1);
	}

int main()
	{
	int TC;
	cin >> TC;
	for( int tc = 1; tc < TC+1; ++tc )
		{
		int N;
		cin >> N;
		vector<double> a1(N),a2(N);
		FOR(i,0,N) cin >> a1[i];
		FOR(i,0,N) cin >> a2[i];
		sort(a1.begin(),a1.end());
		sort(a2.begin(),a2.end());
		x = a1; y = a2;	
		int result1 = f(0,N,0,N);
		x = a2; y = a1;
		int result2 = f(0,N,0,N);
		printf("Case #%d: %d %d\n",tc,result1,N-result2);
		}	
	return 0;
	}
