#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
 
 
#define FNAME ""
 
#define pb push_back
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define vi vector<int>
#define vvi vector<vi>
#define forn(i, n) for (int i = 0; i < n; i++)
#define fornr(i, n) for (int i = n - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = a; i < b; i++)
#define gcd __gcd
 
#ifdef WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif
 
using namespace std;
 
template <class T> T sqr(const T &a) {return a * a;}
 
int len[100], a[100], t, n, boo, used[30], ans;
char s[100][100];

int main()
{
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout); 
	scanf("%d\n", &t);
	forn(q, t)
	{
		printf("Case #%d: ", q + 1);
		scanf("%d\n", &n);
		forn(i, 26)
			used[i] = 0;
		boo = 1;
		forn(i, n)
		{
			scanf("%s", s[i]);
			len[i] = strlen(s[i]);
			a[i] = i;
		}
		ans = 0;
		do
		{
			forn(i, 26)
				used[i] = 0;
			boo = 1;
			forn(i, n)
				forn(j, len[a[i]])
				{
					if (used[s[a[i]][j] - 'a'])
					{
						if (!j && s[a[i - 1]][len[a[i - 1]] - 1] != s[a[i]][j])
							boo = 0;
						if (j && s[a[i]][j - 1] != s[a[i]][j])
							boo = 0;

					}	
					used[s[a[i]][j] - 'a'] = 1;
				}
			ans += boo;
		} while (next_permutation(a, a + n));
		printf("%d\n", ans);		
	}	
}
 
 