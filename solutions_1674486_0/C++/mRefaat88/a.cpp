#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <cctype>
#include <algorithm>
#include <functional>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;

#define fo(i,n) for(i=0;i<(n);++i)

typedef vector<int> vi ;
typedef vector<string> vs ;
typedef vector<double> vd ;
#define sz(x) ((int)(x).size())
#define all(x) x.begin(),x.end()
#define pb(x) push_back(x)
typedef long long ll;
vector<vector<int> > clss;
bool pr[1001];
bool mrkParents(int n)
{
	bool res = false;
	for(int i = 0 ; i < clss[n].size() ; i++) {
		int p = clss[n][i];
		if(pr[p]) return true;
		pr[p]= true;
		res |= mrkParents(p);
		if(res) return true;
	}
	return false;
}
int main()
{
	freopen("A-small-attempt0.in","rt",stdin);
	freopen("A-small.out","wt",stdout);
	int tt,n,m;
	scanf("%d",&tt);
	for(int t = 1; t <= tt ; t++) {
		scanf("%d",&n);
		clss.clear();
		clss.resize(n);
		for(int i = 0 ; i < n ; i++) {
			scanf("%d", &m);
			clss[i].resize(m);
			for(int j = 0 ; j < m ; j++)
			{
				scanf("%d", &clss[i][j]);
				clss[i][j]--;
			}
		}
		bool res = 0 ;
		for(int i = 0 ; i < n ; i ++)
		{
			memset(pr,0,sizeof(pr));
			bool r = mrkParents(i);
			res |= r;
			if(r) {
				break;
			}
		}
		printf("Case #%d: %s\n", t, res?"Yes":"No");
	}
	return 0;
}
