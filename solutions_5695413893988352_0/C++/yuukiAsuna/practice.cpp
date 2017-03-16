#include <bits/stdc++.h>
#define PB push_back
#define FT first
#define SD second
#define MP make_pair
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int>  P;
const int N = 233,MOD = 7+1e9;
char s1[10], s2[10];
int len;
char ai[5], aj[5];
bool isok(char *s, int x)
{
    for(int i = len - 1;i >= 0;i --)
    {
        if(s[i] != '?')
        {
            if((s[i] - '0') != x % 10) return 0;
        }
        x /= 10;
    }
    return 1;
}
int main()
{
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T, ca = 0;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%s%s", s1, s2);
        len = strlen(s1);
        int ansi, ansj, _min = INF;
        int MAX = 1;
        for(int i = 0;i < len;i ++) MAX *= 10;
        for(int i = 0;i < MAX;i ++)
        {
            if(!isok(s1, i)) continue;
            for(int j = 0;j < MAX;j ++)
            {
                if(!isok(s2, j)) continue;
                if(abs(i - j) < _min) {
                    _min = abs(i-j);
                    ansi = i, ansj = j;
                }
                else if(abs(i-j) == _min)
                {
                    if(i < ansi) 
                    {
                        ansi = i, ansj = j;
                    }
                    else if(i == ansi)
                    {
                        if(j < ansj) 
                        {
                            ansi = i, ansj = j;
                        }
                    }
                }
            }
        }
        memset(ai, 0, sizeof ai);
        memset(aj, 0, sizeof aj);        
        for(int i = len - 1;i >= 0;i --) 
        {
            ai[i] = ansi%10 + '0', ansi /= 10;
            aj[i] = ansj%10 + '0', ansj /= 10;
        }
        printf("Case #%d: %s %s\n", ++ca, ai, aj);
    }
    return 0;
}