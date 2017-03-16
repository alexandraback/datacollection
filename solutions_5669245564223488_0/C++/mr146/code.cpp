#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>


using namespace std;


char buf[1046];
int used[1046];
int timer = 146;


bool valid(string & s)
{
	timer++;
	for(int i = 0; i < s.length(); i++)
	{
		if(i > 0 && used[s[i]] == timer && s[i] != s[i - 1])
			return false;
		used[s[i]] = timer;
	}
	return true;
}


void solve(int t)
{
	fprintf(stderr, "%d\n", t);
	int n;
	scanf("%d", &n);
	vector<pair<string, int> > v;
	for(int i = 0; i < n; i++)
	{
		scanf("%s", buf);
		v.push_back(make_pair(string(buf), i));
	}
	sort(v.begin(), v.end());
	int ans = 0;
	do
	{
		bool good = true;
		string res = "";
		for(int i = 0; i < v.size(); i++)
			res += v[i].first;
		if(valid(res))
			ans++;
	}while(next_permutation(v.begin(), v.end()));
	printf("Case #%d: %d\n", t, ans);
}


int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
		solve(i + 1);
}