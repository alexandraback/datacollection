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

int n;
struct arr
{
	int x , y;
	bool operator<(const arr &t)const
	{
		return y < t.y || y == t.y && x > t.x;	
	}
}a[1000008];
bool t[1008];

int main()
{
	freopen("1.in" , "r" , stdin);
	freopen("1.out" , "w" , stdout);
	int T, p = 0;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		rep(i,1,n)
			scanf("%d%d", &a[i].x, &a[i].y);
		sort(a+1, a+n+1);
		memset(t, 0, sizeof(t));
		p++;
		int k = 0, cnt = 0;
		rep(i,1,n)
		{
			while (k < a[i].y)
			{
				bool f = 0;
				drep(j,n,i)
					if (!t[j] && k >= a[j].x)
					{
						t[j] = 1; k++; cnt++; f = 1; break;
					}
				if (!f) { printf("Case #%d: Too Bad\n", p); goto die; }
			}
			if (t[i]) k++; else k += 2;	
		}
		printf("Case #%d: %d\n", p, cnt + n);
		die:;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

