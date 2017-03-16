#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <set>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int,int> pii;

const ll N = 2e5;
const ll M = 11;
const ll INF = 1e7;
const ll SQ = 320;
const ll MOD = 1e9+7;

#define inf cin
#define of cout
#define mp make_pair
#define F first
#define S second

string a[N],b[N];
vector<string> v1,v2;
vector<int> v[N];
int mark[N];
int mat[2][N];

bool dfs(int x)
{
	mark[x] = 1;
	for (int i = 0; i<v[x].size(); i++)
	{
		int u = v[x][i];
		int t = mat[1][u];
		if (t==-1 || (!mark[t] && dfs(t)))
		{
			mat[1][u] = x;	
			mat[0][x] = u;
			return true;
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	ifstream inf("input.txt");
	ofstream of("output.txt");
	cin.tie();

	int t;
	cin >> t;
	for (int k = 1; k<=t; k++)
	{
		cout << "Case #" << k << ": "; 
		v1.clear();
		v2.clear();
		int n;
		cin >> n;
		for (int i = 0; i<n; i++)
		{
			cin >> a[i] >> b[i];
			v1.push_back(a[i]);
			v2.push_back(b[i]);
		}
		sort(v1.begin(),v1.end());
		v1.resize(unique(v1.begin(),v1.end())-v1.begin());
		sort(v2.begin(),v2.end());
		v2.resize(unique(v2.begin(),v2.end())-v2.begin());
		int s1 = v1.size() , s2 = v2.size();
		for (int i = 0; i<s1; i++)
			v[i].clear();
		for (int i = 0; i<n; i++)
		{
			int x = lower_bound(v1.begin(),v1.end(),a[i])-v1.begin();
			int y = lower_bound(v2.begin(),v2.end(),b[i])-v2.begin();
			v[x].push_back(y);
		}
		for (int i = 0; i<s1; i++)
			mat[0][i] = -1;
		for (int i = 0; i<s2; i++)
			mat[1][i] = -1;
		bool found = 1;
		while (found)
		{
			memset(mark,0,sizeof mark);
			found = 0;
			for (int i = 0; i<s1; i++)
				if (mat[0][i]==-1)
					found |= dfs(i);
		}
		int ans = 0;
		for (int i = 0; i<s1; i++)
			if (mat[0][i]!=-1)
				ans++;
		cout << n-((s1+s2)-ans) << '\n';
	}
	return 0;
}