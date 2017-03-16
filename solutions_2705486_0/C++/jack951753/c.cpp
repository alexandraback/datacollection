#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxl = 15;
const int maxm = 530000;
const int maxn = 4010;
int len[maxm], f[maxn], num, p[maxn];
char dict[maxm][maxl], str[maxn];
int compare(int t, int idx, int &ss, int &tt)
{
    //tt = -123
	if(t < len[idx])
		return -1;
	int s = t - len[idx] + 1, k = -1, ret = 0;
	char *c = dict[idx];
	for(int i = 0; i < len[idx]; i++)
		if(c[i] != str[s+i])
			if(k == -1 || i - k > 4)
            {
                if(k==-1) ss = i;
				k = i, ret++;
            }
			else
				return -1;
    tt = k;
	return ret;
}
void doit()
{
    memset(str, 0, sizeof(str));
    scanf(" %s", str + 1);
    int n = strlen(str + 1);
    f[0]=0;p[0]= -12343545;
    int flag = 0;
    for (int i = 1; i <= n; i++)
    {
        f[i] = 0x7fffffff;
        int ff=0;
        for (int j = 0; j < num; j++)
        {
            int ss, tt;
        	int t = compare(i,j,ss, tt);

        	if(t > -1){
                ss+=i; tt+=i;
                if(f[i - len[j]] + t < f[i])
                {
                    f[i] = f[i - len[j]] + t;

                    if(ss - p[i-len[j]] <5) ff =1;
                    else ff=0;
                    p[i] = tt;
                    // printf("d  %d %d dsf", ss, tt);
                }
            }
        }
        flag += ff;
    }
    // printf("%d ",flag);
    printf("%d\n", f[n] + flag >0);
}
int main()
{
    freopen("dict.txt", "r", stdin);
    freopen("c.out", "w", stdout);
    num = 521197;
    for (int i = 0; i < num; ++i)
    {
    	gets(dict[i]);
        len[i] = strlen(dict[i]);
    }
    freopen("c.in", "r", stdin);
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++)
        printf("Case #%d: ", i), doit();
    return 0;
}
