#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 100+10;

char save[maxn];
int s[maxn];
int n;

int res;

//void dfs()
//{
//
//}


int main()
{
    //freopen("./test.txt","r",stdin);
    freopen("./B-large.in","r",stdin);
    freopen("./out","w",stdout);
    int kase;
    scanf("%d",&kase);
    for(int z = 1;z <= kase;++z)
    {
        scanf("%s",save);
        n = strlen(save);
        for(int i = 0;i < n;++i)
            if(save[i] == '+')
                s[i] = 1;
            else
                s[i] = 0;

        int cnt = 0;
        for(int i = n-1;i >= 0;--i)
        {
            if(s[i] == 0)
            {
                cnt++;
                for(int j = 0;j <= i;++j)
                    s[j] ^= 1;
            }
        }

        res = cnt;

        printf("Case #%d: %d\n",z,cnt);
    }

    return 0;
}
