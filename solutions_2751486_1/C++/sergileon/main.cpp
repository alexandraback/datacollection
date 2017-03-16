#include <queue>
#include <iostream>
#include <set>
#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <string>
#include <sstream>
using namespace std;
int n;
string s;

long long Ans()
{
	long long count = 0;
	vector <pair<long long ,long long> > P;
	for ( int i = 0 ; i < s.size() ; i ++)
	{
		
			if ( !(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'))
			{
				count++;
				if ( count ==n)
				{
					P.push_back(make_pair(i - n + 1, i));
					count--;
				}
			}
			else
				count = 0;
	}
	long long ans = 0;
	for (int i = 0 ; i < P.size() ; i ++)
	{
		if ( i==0)
		ans+= (P[i].first + s.size() - P[i].second) + P[i].first*( s.size() - P[i].second -1);
		else
		{
			long long sum = (P[i].first - P[i-1].first + s.size() - P[i].second - 1);
			long long pr = (P[i].first - P[i-1].first - 1) *( s.size() - P[i].second - 1);
			ans += sum + pr;
		}
	}
	return ans;
}
int main()
{
	//#ifdef DEBUG
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
//#endif
	int t;
	scanf("%d",&t);
	for ( int i =  0 ; i < t; i ++)
	{
		long long ans = 0;
		cin >> s;
		scanf("%d",&n);
		ans = Ans();
		printf("Case #%d: %I64d\n",i+1,ans);
	}
	return 0;
}
