#include <string>
#include <cassert>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main()
{
	int T;
	scanf("%d",&T);
	for(int test=1;test<=T;test++)
	{
		int n;
		scanf("%d",&n);
		vector<vector<int> > l;
		REP(i,2*n-1)
		{
			vector<int> v(n);
			REP(j,n)
				cin>>v[j];
			l.push_back(v);
		}
		int cnt[2501]={};
		REP(i,l.size())
			REP(j,l[i].size())
				cnt[l[i][j]]^=1;
		vector<int> res;
		REP(i,2501)
			if(cnt[i])
				res.push_back(i);
		assert(res.size()==n);
		printf("Case #%d:",test);
		REP(i,res.size())
			printf(" %d",res[i]);
		puts("");
	}
	return 0;
}
