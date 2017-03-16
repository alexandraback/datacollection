#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <fstream>

using namespace std;

// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
// To simplify repetitions/loops, Note: define your loop style and stick with it!
#define REP(i, a, b) \
for (int i = int(a); i <= int(b); i++) // a to b, and variable i is local!
#define TRvi(c, it) \
for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define INF 2000000000 // 2 billion
// If you need to recall how to use memset:
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B
//memset(dist, MEMSET_INF, sizeof dist); // useful to initialize shortest path distances
//memset(dp_memo, -1, sizeof dp_memo); // useful to initialize DP memoization table
//memset(arr, 0, sizeof arr); // useful to clear array of integers

int main()
{
	int r,c, t,w;
	
	ifstream fin;
	ofstream fout;
	fin.open("input.in");
	fout.open("output.out");
	
	fin>>t;
	
	for (int i=1;i<=t;i++)
	{
		fin>>r;
		fin>>c;
		fin>>w;
		
		int tot;
		
		
		
		if (r==1)
		{
			if (c%w==0) tot = c/w + w - 1;
			else tot = c/w + w;
			
		}
		else
		{
			tot = r*c/w + w - 1;
		}
		fout<<"Case #"<<i<<": "<<tot<<endl;
		
	}
	
	return 0;
}
	
	
	


