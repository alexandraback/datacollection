#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;


int a[64][64], n, m;
string name[64];

bool cmp1(string s1, string s2)
{
	return (s1  + s2) < (s2 + s1);
}

bool cmp2(string s1, string s2)
{
	if(s1.size() == s2.size())
		return s1 < s2;
	else
		return s1.size() < s2.size();
}
int used[64];

string dfs(int pos, int start, int parent)
{
	used[pos] = 1;

	vector <string> temp;
	int i;
	for(i = 0; i < n; i ++)
	{
		if(!used[i] && a[pos][i])
		{
			temp.push_back(dfs(i, start, pos));
		}
	}

	string helper = name[pos];
	sort(temp.begin(), temp.end(), cmp1);
	string ret = helper;
	for(i = 0; i < temp.size(); i++)
	{
		ret += temp[i];
	}
	return ret;
}

void solve()
{
	memset(a, 0, sizeof(a));
	cin >> n>> m;

	int i;
	for(i = 0; i < n; i++)
		cin >> name[i];
	
	for(i =0 ; i < m; i ++)
	{
		int p1, p2;
		cin >> p1 >> p2;
		p1--;
		p2--;
		a[p1][p2] = a[p2][p1] = 1;
	}

	memset(used, 0, sizeof(used));
	string res = dfs(0, 0, -1);

	for(i = 1; i < n; i ++)
	{

	memset(used, 0, sizeof(used));
		string temp = dfs(i, i, -1);
		if(cmp2(temp, res))
			res = temp;
	}
	cout <<  res << endl;

}
int main ()
{

	int tt;
	scanf ("%d", &tt);

	int i;
	for(i = 0; i < tt; i ++)
	{
		printf ("Case #%d: ", i+1);
		solve();
	}

	return 0;
}