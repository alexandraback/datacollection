#include <bits/stdc++.h>
using namespace std;
const int N = 30;
typedef long long LL;
#define fix(x) x = x >= MOD ? x % MOD : x
const LL MAXN = 5e18;

char c1[N],c2[N];
LL f1,f2;
LL a1,a2;
LL d;
LL ans1[N],ans2[N];
int n;

void init()
{
    scanf("%s %s",c1 + 1,c2 + 1);
  //  printf("%s %s\n",c1 + 1,c2 + 1);
    n = strlen(c1 + 1);
    c1[n + 1] = '0';
    c2[n + 1] = '0';
    d = MAXN;
}

void update()
{
    LL df = abs(f1 - f2);
  //  cout<<f1<<","<<f2<<endl;
    if(df < d) a1 = f1,a2 = f2,d = df;
    else if(df == d)
    {
        if(f1 < a1){a1 = f1,a2 = f2,d = df;}
        else if(f1 == a1)
        {
            if(f2 < a2) {a1 = f1,a2 = f2,d = df;}
        }
    }
}

void work()
{
    bool s = 0;
    int mid = n + 1;
    for(int i = 1;i <= n;i++)
    {
        if(c1[i] != c2[i] && c1[i] != '?' && c2[i] != '?') {mid = i;break;}
        if(c1[i] == '?' && c2[i] == '?')
        {
            f1 = f2 = 0LL;
            for(int j = 1;j < i;j++) f1 = f1 * 10LL + 1LL * (c1[j] - '0'),f2 = f2 * 10LL + 1LL * (c2[j] - '0');
            f1 = f1 * 10LL + 1LL,f2 = f2 * 10LL;
            for(int j = i + 1;j <= n;j++)
            {
                f1 *= 10LL;f2 *= 10LL;
                if( c1[j] != '?' ) f1 += 1LL * (c1[j] - '0');
                if( c2[j] != '?' ) f2 += 1LL * (c2[j] - '0'); else f2 += 9LL;
            }
            update();

            f1 = f2 = 0LL;
            for(int j = 1;j < i;j++) f1 = f1 * 10LL + 1LL * (c1[j] - '0'),f2 = f2 * 10LL + 1LL * (c2[j] - '0');
            f1 = f1 * 10LL ,f2 = f2 * 10LL + 1LL;
            for(int j = i + 1;j <= n;j++)
            {
                f1 *= 10LL;f2 *= 10LL;
                if( c1[j] != '?' ) f1 += 1LL * (c1[j] - '0'); else f1 += 9LL;
                if( c2[j] != '?' ) f2 += 1LL * (c2[j] - '0');
            }
            update();

            c1[i] = '0';
            c2[i] = '0';
        }
        else
        {
            if(c1[i] == '?')
            {
                if(c2[i] != '9')
                {
                    f1 = f2 = 0LL;
                    for(int j = 1;j < i;j++) f1 = f1 * 10LL + 1LL * (c1[j] - '0'),f2 = f2 * 10LL + 1LL * (c2[j] - '0');
                    f1 = f1 * 10LL + 1LL * (c2[i] - '0' + 1),f2 = f2 * 10LL + 1LL * (c2[i] - '0');
                    for(int j = i + 1;j <= n;j++)
                    {
                        f1 *= 10LL;f2 *= 10LL;
                        if( c1[j] != '?' ) f1 += 1LL * (c1[j] - '0');
                        if( c2[j] != '?' ) f2 += 1LL * (c2[j] - '0'); else f2 += 9LL;
                    }
                    update();
                }
                if(c2[i] != '0')
                {
                    f1 = f2 = 0LL;
                    for(int j = 1;j < i;j++) f1 = f1 * 10LL + 1LL * (c1[j] - '0'),f2 = f2 * 10LL + 1LL * (c2[j] - '0');
                    f1 = f1 * 10LL + 1LL * (c2[i] - '0' - 1),f2 = f2 * 10LL + 1LL * (c2[i] - '0');
                    for(int j = i + 1;j <= n;j++)
                    {
                        f1 *= 10LL;f2 *= 10LL;
                        if( c1[j] != '?' ) f1 += 1LL * (c1[j] - '0'); else f1 += 9LL;
                        if( c2[j] != '?' ) f2 += 1LL * (c2[j] - '0');
                    }
                    update();
                }
                c1[i] = c2[i];
            }
            else
            if(c2[i] == '?')
            {
                if(c1[i] != '0')
                {
                    f1 = f2 = 0LL;
                    for(int j = 1;j < i;j++) f1 = f1 * 10LL + 1LL * (c1[j] - '0'),f2 = f2 * 10LL + 1LL * (c2[j] - '0');
                    f1 = f1 * 10LL + 1LL * (c1[i] - '0'),f2 = f2 * 10LL + 1LL * (c1[i] - '0' - 1);
                    for(int j = i + 1;j <= n;j++)
                    {
                        f1 *= 10LL;f2 *= 10LL;
                        if( c1[j] != '?' ) f1 += 1LL * (c1[j] - '0');
                        if( c2[j] != '?' ) f2 += 1LL * (c2[j] - '0'); else f2 += 9LL;
                    }
                    update();
                }
                if(c1[i] != '9')
                {
                    f1 = f2 = 0LL;
                    for(int j = 1;j < i;j++) f1 = f1 * 10LL + 1LL * (c1[j] - '0'),f2 = f2 * 10LL + 1LL * (c2[j] - '0');
                    f1 = f1 * 10LL + 1LL * (c1[i] - '0'),f2 = f2 * 10LL + 1LL * (c1[i] - '0' + 1);
                    for(int j = i + 1;j <= n;j++)
                    {
                        f1 *= 10LL;f2 *= 10LL;
                        if( c1[j] != '?' ) f1 += 1LL * (c1[j] - '0'); else f1 += 9LL;
                        if( c2[j] != '?' ) f2 += 1LL * (c2[j] - '0');
                    }
                    update();
                }
                c2[i] = c1[i];
            }
        }
    }


    f1 = f2 = 0LL;
    for(int i = 1;i < mid;i++) f1 = f1 * 10LL + 1LL * (c1[i] - '0'),f2 = f2 * 10LL + 1LL * (c2[i] - '0');

//cout<<mid<<" ";cout<<f1<<" "<<f2<<endl;
    if(mid == n + 1)
    {
        update();
    }
    else
    {
        f1 = f1 * 10LL + 1LL * (c1[mid] - '0'),f2 = f2 * 10LL + 1LL * (c2[mid] - '0');
      //  cout<<f1<<" "<<f2<<endl;
        if(f1 > f2)
        {
            for(int i = mid + 1;i <= n;i++)
            {
                f1 *= 10LL;f2 *= 10LL;
                if( c1[i] != '?' ) f1 += 1LL * (c1[i] - '0');
                if( c2[i] != '?' ) f2 += 1LL * (c2[i] - '0'); else f2 += 9LL;
            }
            update();
        }
        else
        {
            for(int i = mid + 1;i <= n;i++)
            {
                f1 *= 10LL;f2 *= 10LL;
                if( c1[i] != '?' ) f1 += 1LL * (c1[i] - '0'); else f1 += 9LL;
                if( c2[i] != '?' ) f2 += 1LL * (c2[i] - '0');
            }
            update();
        }
    }

//    cout<<a1<<" "<<a2<<endl;
    memset(ans1,0,sizeof(ans1));
    memset(ans2,0,sizeof(ans2));
    int i = 0;
    while(a1){i++,ans1[n - i + 1] = a1 % 10LL,a1/=10LL;}
    i = 0;
    while(a2){i++,ans2[n - i + 1] = a2 % 10LL,a2/=10LL;}
    for(int i = 1;i <= n;i++) cout<<ans1[i];cout<<" ";
    for(int i = 1;i <= n;i++) cout<<ans2[i];cout<<endl;
}

int main()
{
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B-small-attempt1.out","w",stdout);

    int T;
    scanf("%d",&T);
    for(int i = 1;i <= T;i++)
    {
        printf("Case #%d: ",i);
        init();
        work();
    }

    return 0;
}
