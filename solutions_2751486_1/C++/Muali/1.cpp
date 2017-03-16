#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
long long solve()
{
	string s;
	int n;
	cin>>s>>n;
	int c=0;
	vector<int> good;
	for(int i=0; i<s.size(); i++)
	{
		if(s[i]!='a'&&s[i]!='o'&&s[i]!='i'&&s[i]!='u'&&s[i]!='e')
		{
			c++;
			if(c>=n)
				good.push_back(i);
		}
		else
		{
			c=0;
		}
	}
	long long ans=0;
	int j=0;
	for(int i=0; i<s.size()&&j<good.size(); i++)
	{
		while(j<good.size()&&(i+n-1>good[j]))
			j++;
		if(j==good.size()) break;
		ans+=s.size()-good[j];
	}
	return ans;
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int z=0; z<t; z++)
	{
		cout<<"Case #"<<z+1<<": "<<solve()<<'\n';
	}
}