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

double a[1000008], s[1000008];
double ans;
int main()
{
	freopen("1.in" , "r" , stdin);
	freopen("1.out" , "w" , stdout);
	int T, cnt = 0;
	int m, n;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &m, &n);
		s[0] = 1;
		rep(i,1,m)
		{
			scanf("%lf", &a[i]);
			s[i] = s[i-1] * a[i];
		}
		ans = n + 2;
		drep(i,m,1)
		{
			ans = min(ans, s[i] * (n - i + 1 + m - i) + (1 - s[i]) * (n - i + 1 + n + 1 + m - i));	
		}
		cnt++;
		printf("Case #%d: %lf\n", cnt, ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

