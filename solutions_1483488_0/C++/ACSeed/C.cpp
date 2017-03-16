#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>

using namespace std;

bool hash[2000010];

int mypow(int n)
{
    int ans = 1;
    for(int i = 0; i < n; ++i) ans *= 10;
    return ans;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int a, b;
    int t, k = 0;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &a, &b);
        int ans = 0;
        int tmp = a;
        int num = 0;
        while(tmp)
        {
            num++;
            tmp /= 10;
        }
        int tmp1 = a, tmp2;
        for(tmp1 = a; tmp1 < b; ++tmp1)
        {
            memset(hash,false,sizeof(hash));
            for(int i = 1; i < num; ++i)
            {
                int mi = mypow(i);
                int tail = tmp1 % mi;
                int h = tmp1 / mi;
                tmp2 = tail * mypow(num - i) + h;
                int d = 0;
                int tp = tmp2;
                while(tp)
                {
                    d++;
                    tp /= 10;
                }

                if(!hash[tmp2] && d == num  && tmp2 <= b && tmp2 > tmp1)
                {
                    hash[tmp2] = true;
                    ans++;
                }
            }
        }
        printf("Case #%d: %d\n",++k,ans);
    }
    return 0;
}
