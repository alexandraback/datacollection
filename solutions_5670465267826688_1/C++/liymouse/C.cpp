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

int get(char c)
{
    if (c == 'i') return 1;
    else if (c == 'j') return 2;
    else return 3;
}

int cal(int a , int b)
{
    int v[4][4] = {
    {0 , 1 , 2 , 3},
    {1 , 0 , 3 , 2},
    {2 , 3 , 0 , 1},
    {3 , 2 , 1 , 0}};
    int s[4][4] = {
    {0 , 0 , 0 , 0},
    {0 , 1 , 0 , 1},
    {0 , 1 , 1 , 0},
    {0 , 0 , 1 , 1}};
    return s[a][b] * 10 + v[a][b];
}

int main()
{
	freopen("C-large.in" , "r" , stdin);
    //freopen("input.txt" , "r" , stdin);
	//freopen("C-small-attempt2.out" , "w" , stdout);
    freopen("C-large.out" , "w" , stdout);
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
		printf("Case #%d: " , ca);
        char s[10010];
        int L;
        i64d t;
        scanf("%d %lld" , &L , &t);
        scanf("%s" , s);

        //cal on row
        int c = 0;
        int sign = 0;
        for (int i = 0; i < L; i ++)
        {
            int x = cal(c , get(s[i]));
            sign = sign ^ (x/10);
            c = x % 10;
        }
        int s_res = c;
        int s_sign = sign;
        //cal total 
        //int rt = t-1;
        int rt = (t-1)%4;
        for (int i = 0; i < rt; i ++)
        {
            int x = cal(c , s_res);
            sign = sign ^ (x/10) ^ s_sign;
            c = x % 10;
        }

        //if total mul = -1
        if (c == 0 && sign == 1)
        {
            //cal i
            int x = 0;
            int i_Len = 1;
            c = get(s[x]);
            sign = 0;
            while (i_Len <= 4 * L)
            {
                if (c == 1 && sign == 0) break;
                x = (x + 1) % L; 
                i_Len ++;
                int v = cal(c , get(s[x]));
                sign = sign ^ (v/10);
                c = v % 10;
            }
            
            if (c == 1 && sign == 0 && (i64d)i_Len < (i64d)L * (i64d)t)
            {
                //cal j
                int y = L-1;
                int k_Len = 1;
                c = get(s[y]);
                sign = 0;
                while (k_Len <= 4 * L)
                {
                    if (c == 3 && sign == 0) break;
                    y --; if (y < 0) y = L-1;
                    k_Len ++;
                    int v = cal(get(s[y]) , c);
                    sign = sign ^ (v/10);
                    c = v % 10;
                }
                if (c == 3 && sign == 0 && (i64d)(i_Len+k_Len) < (i64d)L * (i64d)t)
                {
                    printf("YES\n");
                }
                else printf("NO\n");
            }
            else printf("NO\n");
        }
        else printf("NO\n");
    }
    return 0;
}