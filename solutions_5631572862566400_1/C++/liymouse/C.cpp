#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <numeric>
#include <cstring>

typedef long long i64d;

using namespace std;

typedef struct
{
    int L , H;
    int last;
    int id;
}Elem;

Elem t[1001];
int visit[1001];
int a[1001];
int n;
int L[1001];
int start;

void dfs(int x , int len , int id)
{
    visit[x] = 1;
    L[x] = len;
    if (visit[a[x]] == 1)
    {
        if (t[a[x]].id == 0) //first
        {
            t[x].H = L[x] - L[a[x]] + 1;
            t[x].L = 0;
            start = a[x];
            t[x].last = a[x];
            t[x].id = id;
        }
        else
        {
            t[x].H = t[a[x]].H;
            t[x].L = t[a[x]].L + 1;
            t[x].last = t[a[x]].last;
            if (t[a[x]].L != 0 || a[x] == t[a[x]].last)
                t[x].id = t[a[x]].id;
            else
                t[x].id = id;
        }
    }
    else
    {
        dfs(a[x] , len + 1 , id);
        if (start == -1)
        {
            t[x].H = t[a[x]].H;
            t[x].L = t[a[x]].L + 1;
            t[x].last = t[a[x]].last;
            t[x].id = t[a[x]].id;
        }
        else
        {
            t[x].H = t[a[x]].H;
            t[x].L = t[a[x]].L = 0;
            t[x].last = t[a[x]].last;
            t[x].id = t[a[x]].id;
            if (start == x) start = -1;
        }
    }
}

int main()
{
    //freopen("C.in" , "r" , stdin);
	freopen("C-large.in" , "r" , stdin);
	freopen("C-large.out" , "w" , stdout);
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
		printf("Case #%d: " , ca);
        scanf("%d" , &n);
        for (int i = 0; i < n; i ++)
        {
            scanf("%d" , &a[i]);
            a[i] --;
            visit[i] = 0;
            t[i].L = t[i].H = 0;
            t[i].last = -1;
            t[i].id = 0;
        }
        for (int i = 0; i < n; i ++)
            if (visit[i] == 0)
            {
                start = -1;
                memset(L , 0 , sizeof(L));
                dfs(i , 1 , i+1);
            }
        int easy = 1;
        for (int i = 0; i < n; i ++)
        {
            if (t[i].H == 2) {easy = 0; break;}
        }
        int res = 0;
        for (int i = 0; i < n; i ++) res = max(res , t[i].H);
        if (easy == 0)
        {
            int maxv[1001] = {0};
            int choose[1001] = {0};
            for (int i = 0; i < n; i ++)
                if (t[i].H == 2)
                {
                    if (t[i].H + t[i].L > maxv[t[i].id])
                    {
                        maxv[t[i].id] = t[i].H + t[i].L;
                        choose[t[i].id] = i;
                    }
                }

            for (int i = 1; i <= n; i ++)
                if (maxv[i] > 0)
                {
                    int mm = 0;
                    for (int j = i+1; j <= n; j ++)
                        if (maxv[j] > 0)
                        {
                            int x = choose[i];
                            int y = choose[j];
                            if (t[x].last == t[y].last)
                            {
                                mm = max(mm , t[y].L);
                                maxv[j] = 0;
                            }
                        }
                    maxv[i] += mm;
                }
            int sum = 0;
            for (int i = 1; i <= n; i ++) if (maxv[i] > 0) sum += maxv[i];
            res = max(res , sum);
#if 0
            for (int i = 1; i <= n; i ++) res = max(res , maxv[i]);
            for (int i = 1; i <= n; i ++)
                if (maxv[i] > 0)
                for (int j = i+1; j <= n; j ++)
                    if (maxv[j] > 0)
                    {
                        int x = choose[i];
                        int y = choose[j];
                        int tmp = 0;
                        if (t[x].last != t[y].last)
                        {
                            tmp = maxv[i] + maxv[j];
                        }
                        else
                        {
                            tmp = maxv[i] + maxv[j] - t[x].H;
                        }
                        res = max(res , tmp);
                    }
#endif
        }
        printf("%d\n" , res);
    }
    return 0;
}