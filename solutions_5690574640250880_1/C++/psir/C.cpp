#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdio>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define VI vector<int>

vector<string> transpose( const vector<string>& a )
	{
	int m  = a.size(); int n = a[0].size();
	vector<string> res(n);
	FOR(i,0,n)
		FOR(j,0,m)
			{
			res[i] += a[j][i];
			}
	return res;
	}

int moze(int x, int y, int m)
	{
	if ( x > y ) return moze(y,x,m);
	if ( m >= x && y > 2)  return moze(x,y-1,m-x);
	if ( x == 2 ) 
		{
			if ( m == 0 || m == x*y-1) return 1;
			else return 0;
		}
	if ( m <= y-2 ) return 1;
	if ( m == y-1 ) 
		{
		if ( y == 3 ) return 0;
		else return 1;
		}
	}

vector<string> construct(int x, int y, int m)
	{
	//cout << x << " " << y << " " << m << endl;
	if ( x > y ) return transpose(construct(y,x,m));
	if ( x == y && m >= 2*x - 1)
		{
		vector<string> res = construct(x-1,y-1,m-2*x+1);
		FOR(i,0,res.size()) res[i] += '*';
		res.resize(res.size()+1);
		FOR(j,0,res[0].size()) res.back() += '*';
		return res;
		}
	if ( m >= x )  
		{
		vector<string> res = construct(x,y-1,m-x);
		FOR(i,0,res.size()) res[i] += '*';
		return res;
		}
	if ( x == 1 ) 
		{
		vector<string> res(x);
				FOR(i,0,x)
					FOR(j,0,y) res[i] += '.';
				res[0][0] = 'c';
				return res;
		}
	if ( x == 2 ) 
		{
			if ( m == 0 ) 
				{
				vector<string> res(x);
				FOR(i,0,x)
					FOR(j,0,y) res[i] += '.';
				res[0][0] = 'c';
				return res;
				}
			else return vector<string>();
		}
	
	if ( m <= y-2 ) 
		{
		vector<string> res(x);
		FOR(i,0,x)
			FOR(j,0,y) res[i] += '.';
		res[0][0] = 'c';
		for(int j=0;j<m;++j) res[x-1][y-1-j] = '*';	
		return res;
		}
	if ( m == y-1 ) 
		{
		if ( y == 3 ) return vector<string>();
		vector<string> res(x);
		FOR(i,0,x)
			FOR(j,0,y) res[i] += '.';
		res[0][0] = 'c';
		for(int j=0;j<m-1;++j) res[x-1][y-1-j] = '*';	
		res[x-2][y-1] = '*';
		return res;
		}
	return vector<string>();
	}

int main()
	{
	int TC;
	cin >> TC;
	for( int tc = 1; tc < TC+1; ++tc )
		{
		int x, y, m;
		cin >> x >> y >> m;
		int ok = moze(x,y,m);
		//cout << x << " " << y << " "<< m << endl;
		//cout << tc << " " << ok << endl; 
		vector<string> s(x);
		if( ok ) s = construct(x,y,m);
		printf("Case #%d:\n",tc);
		//cout << x << " " << y << " "<< m << endl;
		if ( ok )
			{
			FOR(i, 0, s.size() )
				cout << s[i] << endl;
			}
		else 
			cout << "Impossible" << endl;
		}	
	return 0;
	}
