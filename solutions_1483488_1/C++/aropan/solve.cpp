#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>

using namespace std;


const int MAXX = 10000000;
const int MAXL = 10;

int a, b;
int upd[MAXX], cnt;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif

    int t;
    scanf("%d\n", &t);
    for (int test = 1; test <= t; test++)
    {
    	printf("Case #%d: ", test);
    	scanf("%d %d", &a, &b);
    	cnt++;
    	int ans = 0;
    	for (; a <= b; a++)
    		if (upd[a] != cnt)
    		{
    			char s[MAXL];
    			sprintf(s, "%d", a);
    			int n = 0;
    			int l = strlen(s);
    			for (int i = 0; i < l; i++)
    			{
    				if (s[0] != '0')
    				{
    					int x;
    					sscanf(s, "%d", &x);
    					if (upd[x] == cnt) break;
    					if (a <= x && x <= b)
    					{
    						upd[x] = cnt;
    						n++;
    					}
    				}
    				char c = s[0];
    				memmove(s, s + 1, l - 1);
    				s[l - 1] = c;
    			}
    			ans += n * (n - 1) / 2;
    		}
    	printf("%d", ans);
    	fflush(stdout);
    	printf("\n");
    }

    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}
