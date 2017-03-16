#include <iostream>
#include <cmath>
#include <deque>
#include <algorithm>
#include <map>
#include <cstdio>
#include <sstream>
#include <deque>
#include <vector>
#include <cstring>
#include <fstream>
#include <string>

using namespace std;

#define MAXN 12000
#define pi pair <int, int>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define sz(a) (int)(a.size())

vector < int > v;
int T, L, N, X, Y;
string S;


int main (int argc, char const* argv[])
{
    	ifstream cin ("B-small.in");
    	ofstream cout ("B-small.out");
	cin >> T;
	for (int t = 0; t < T; t += 1)
	{
		string ans;
		cin >> X >> Y;
		if( X > 0 )
		{
			for (int i = 0; i < X; i += 1)
			{
				ans += "WE";
			}
		}
		else
		{
			X = 0 - X;
			for (int i = 0; i < X; i += 1)
			{
				ans += "EW";
			}
		}
		if( Y > 0 )
		{
			for (int i = 0; i < Y; i += 1)
			{
				ans += "SN";
			}
		}
		else
		{
			Y = 0 - Y;
			for (int i = 0; i < Y; i += 1)
			{
				ans += "NS";
			}
		}
		cout << "Case #" << t+1 << ": " << ans <<'\n';
	}
	return 0;
}

