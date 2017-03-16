#define _USE_MATH_DEFINES 
#define _CRT_SECURE_NO_DEPRECATE 
#include <iostream> 
#include <cstdio> 
#include <cstdlib> 
#include <vector> 
#include <sstream> 
#include <string> 
#include <map> 
#include <set> 
#include <algorithm> 
#include <cmath> 
#include <cstring> 
#include <queue>
using namespace std; 
#pragma comment(linker, "/STACK:256000000") 
#define mp make_pair 
#define pb push_back 
#define all(C) (C).begin(), (C).end() 
#define sz(C) (int)(C).size() 
#define PRIME 1103 
#define PRIME1 31415 
typedef long long int64; 
typedef unsigned long long uint64; 
typedef pair<int, int> pii; 
typedef vector<int> vi; 
typedef vector<vector<int> > vvi; 
//------------------------------------------------------------ 
const int N = 1000010;
const double pi = 3.1415926535897932384626433832795;
double EPS = 1e-9;
int n;

int solve()
{
	scanf("%d", &n);
	vector < pair <double, double> > dis; 
	for(int i = 0; i < n ;++i)
	{
		int d, h, m;
		scanf("%d %d %d", &d, &h, &m);
		double q = d * pi / 180;
		for(int j = 0; j < h; ++j)
		{
			dis.push_back(mp(q, 2 * pi / (j + m)));
		}
	}
	sort(dis.begin(), dis.end());
	int ans = dis.size();
	for(int i = 0; i < dis.size(); ++i)
	{
		double k = 2 * pi - dis[i].first;
		double t = k / dis[i].second;
		int ok = 0;
		for(int j = 0; j < dis.size(); ++j)
		{
			if (i == j)
				continue;
			double v = dis[j].first + dis[j].second * t;
			if (fabs(dis[j].first - dis[i].first) < EPS)
			{
				if (dis[j].second - dis[i].second > EPS)
				{
					if (v - 4 * pi > -EPS)
						ok++;
				}
				else
				{
					if (v - 2 * pi > -EPS)
						ok++;
				}
				continue;
			}

			if (dis[j].first > dis[i].first)
			{
				if (v - 4 * pi > -EPS)
					ok++;
			}
			else
			{
				if (v - 2 * pi > -EPS)
					ok++;
			}
		}
		ans = min(ok + i, ans);
	}
	return ans;
}
int main()
{
   // ios_base::sync_with_stdio(false);cin.tie(0);
	
#ifdef WIN32
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i)
	{
		printf("Case #%d: %d\n", i + 1, solve());
	}
	
}