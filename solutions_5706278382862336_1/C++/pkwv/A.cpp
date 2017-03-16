#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
#define ll long long
using namespace std;

char s[30];

bool tag;

ll gcd(ll a,ll b)
{
    if(a>b) swap(a,b);
    while(a>0)
    {
        ll t=a;
        a=b%a;
        b=t;
    }
    return b;
}

int find_a(ll a,ll b)
{
    if(b==1)
    {
        return 0;
    }
    if(b&1)
    {
        tag=true;
        return -1;
    }
    if(a>b/2)
    {
        return find_a(a-b/2,b/2);
    }else if(a<b/2)
    {
        return 1+find_a(a,b/2);
    }else
    {
        return 1;
    }
}

int main()
{
#ifdef PKWV
    freopen("A-large.in","r",stdin);
    freopen("out.out","w",stdout);
#endif // PKWV
    int T;
    int cas=1;
    scanf("%d",&T);
//    printf("%d==\n",T);
    while(T--)
    {
        scanf("%s",s);
        int len=strlen(s);
        ll a=0,b=0;
        int i=0;
        while(s[i]>='0'&&s[i]<='9')
        {
            a=a*10+s[i]-'0';
            i++;
        }
        i++;
        while(s[i]>='0'&&s[i]<='9')
        {
            b=b*10+s[i]-'0';
            i++;
        }
        ll g=gcd(a,b);
        a/=g;
        b/=g;
        ll t=b;
        while(!(t&1))
        {
            t>>=1;
        }
        printf("Case #%d: ",cas++);
        if(t!=1)
        {
            printf("impossible\n");
        }else
        {
            int res=0;
            while(a<b)
            {
                res++;
                a*=2;
            }
            printf("%d\n",res);
        }
    }
    return 0;
}
