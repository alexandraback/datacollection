#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAX 1005

int mark[MAX];
int t;

int main()
{
	scanf("%d", &t);
	for(int tc=1; tc<=t; ++tc)
	{
		map<string, int> cnt1, cnt2;
		set<string> tree1, tree2;
		vector< pair<string, string> > vtopic;
		char s1[30], s2[30];
		int n;
		
		memset(mark, 0, sizeof(mark));

		scanf("%d", &n);
		for(int i=0; i<n; ++i)
		{
			scanf(" %s %s ", s1, s2);
			vtopic.pb(mp(s1, s2));
			cnt1[s1]++;
			cnt2[s2]++;
		}
			
		for(int i=0; i<n; ++i)
		{
			string str1 = vtopic[i].fi, str2 = vtopic[i].se;

			if(cnt1[str1] == 1 || cnt2[str2] == 1)
			{
				tree1.insert(str1);
				tree2.insert(str2);
				mark[i] = 1;

				//printf("first: %s %s\n", str1.c_str(), str2.c_str());
			}
		}
		
		for(int i=0; i<n; ++i)
		{
			string str1 = vtopic[i].fi, str2 = vtopic[i].se;
			
			if(mark[i]) continue;

			if(tree1.find(str1) == tree1.end() && tree2.find(str2) == tree2.end())
			{
				tree1.insert(str1);
				tree2.insert(str2);
				mark[i] = 1;
				
				//printf("second: %s %s\n", str1.c_str(), str2.c_str());
			}
		}
	
		for(int i=0; i<n; ++i)
		{
			string str1 = vtopic[i].fi, str2 = vtopic[i].se;
			
			if(mark[i]) continue;

			if(tree1.find(str1) == tree1.end() || tree2.find(str2) == tree2.end())
			{
				tree1.insert(str1);
				tree2.insert(str2);
				mark[i] = 1;
				
				//printf("third: %s %s\n", str1.c_str(), str2.c_str());
			}
		}

		int sol = 0;
		for(int i=0; i<n; ++i)
		{
			string str1 = vtopic[i].fi, str2 = vtopic[i].se;
			
			if(mark[i]) continue;

			if(tree1.find(str1) != tree1.end() && tree2.find(str2) != tree2.end())
			{
				sol++;
				//printf("sol: %s %s\n", str1.c_str(), str2.c_str());
			}
		}

		printf("Case #%d: %d\n", tc, sol);
	}

	return 0;
}
