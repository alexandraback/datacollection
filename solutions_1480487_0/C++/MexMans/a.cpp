#include<iostream>
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
#pragma comment(linker, "/STACK:16777216")
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define LL long long
#define bit __builtin_popcountll
using namespace std;
template<class T> inline T sqr(T x) { return x * x; }
typedef pair<int, int> pii;
const double eps = 1e-9;
const double pi = acos(-1.0);
int s[200];
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int T,n,x;
	cin>>T;
	for(int t = 1; t <= T; t++)
	{
		cin>>n;
		x = 0;
		for(int i = 0; i < n; i++)
		{
			cin>>s[i];
			x += s[i];
		}
		cout<<"Case #"<<t<<":";
		for(int i = 0; i < n; i++)
		{
			double l = 0.0;
			double r = 1.0;
			for(int it = 0; it < 200; it++)
			{
				double mid = (l + r) / 2.0;
				double value = s[i] + mid * x;
				double mm = 0.0;
				for(int j = 0; j < n; j++)
				{
					if (i == j) continue;
					if (value >= s[j]) mm += (value - s[j]) / x;
				}
				if (mm + mid >= 1.0) r = mid; else l = mid;
			}
			printf(" %.9lf",(l + r) * 50);
		}
		cout<<endl;
	}
	return 0;
}
