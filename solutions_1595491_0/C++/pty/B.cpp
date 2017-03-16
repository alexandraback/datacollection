#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;i++)
#define drep(i,r,l) for(int i=r;i>=l;i--)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define LL long long
#define travel(u) for(int i=start[u],v;v=e[i].a,i;i=e[i].next)
#define eps 1e-10
#define sqr(x) ((x)*(x))
#define pb push_back

int t[1008], n, s, p;
int T, p1[1008], p2[1008];
int main()
{
	int T;
	scanf("%d", &T);
	int cnt = 0;
	while (T--)
	{
		scanf("%d%d%d", &n, &s, &p);
		rep(i,1,n)
			scanf("%d", &t[i]);
		int ans = 0;
		rep(i,1,n)
		{
			if (t[i] % 3 == 2)
			{
				p1[i] = (t[i] + 1) / 3;
				p2[i] = p1[i] + 1;
				if (p2[i] - 2 < 0) p2[i] = p1[i];				
			}	
			else if (t[i] % 3 == 1)
			{
				p1[i] = (t[i] + 2) / 3;
				p2[i] = p1[i];	
			}
			else
			{
				p1[i] = t[i] / 3;
				p2[i] = p1[i] + 1;	
				if (p2[i] - 2 < 0) p2[i] = p1[i];
			}
			if (p1[i] < p && p2[i] >= p && s > 0)
				s--, ans++;
			
			if (p1[i] >= p) ans++;
		}
		++cnt;
		printf("Case #%d: %d\n", cnt, ans);
	}
	return 0;
}
