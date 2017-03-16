#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<map>
#include<set>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
#define MP(i,j) make_pair(i,j)
#define X first
#define Y second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> PII;

int k, l, s;
double s1, s2, mx;
char a[105], b[105], ans[105];
template <class T>void up(T&a,T b){if(a<b)a=b;}
template <class T>void down(T&a,T b){if(a>b)a=b;}
void dfs(int n)
{
	if (n > s)
	{
		double ns = 0;
		s2++;
		for (int j = 1; j + l - 1 <= s; j++)
		{
			int bj = 1;
			for (int k = 1; k <= l; k++)
				if (b[k] != ans[j + k - 1])
				{
					bj = 0;
					break;
				}
			s1 += bj;
			ns += bj;
		}
		up(mx, ns);
	}
	else for (int x = 1; x <= k; x++)
	{
		ans[n] = a[x];
		dfs(n + 1);
	}
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++)
    {
        printf("Case #%d: ", t);
	    scanf("%d%d%d", &k, &l, &s);
    	scanf("%s", a + 1);
	    scanf("%s", b + 1);
	    s1 = s2 = mx = 0;
	    dfs(1);
	    printf("%.8f\n", mx - s1 / s2);
    }
    return 0;
}
