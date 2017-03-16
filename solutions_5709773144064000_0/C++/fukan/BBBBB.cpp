#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

double t[100010],s[100010];

int main()
{
    int T,cas=1;
    double c,f,x,ans;
    freopen("2.txt","r",stdin);
    freopen("22.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf%lf%lf",&c,&f,&x);

        memset(t,0,sizeof(t));
        memset(s,0,sizeof(s));

        int i=0;
        double down=2,sumt=0;
        while(1)
        {
            i++;
            t[i] = c/down;
            s[i] = sumt+x/down;
            sumt += t[i];
            down += f;
            if(i>=2 && s[i]>s[i-1])
            {
                ans = s[i-1];
                break;
            }
        }
        printf("Case #%d: %.7lf\n",cas++,ans);
    }
    return 0;
}
