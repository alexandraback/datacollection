#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

bool vis[10000000];
int fact[]={0,0,1,3,6,10,15,21,28};
int digit;
int power[]={1,10,100,1000,10000,100000,1000000,10000000};

void rever(int& a)
{
    int rem=a%10;

    a/=10;
    a+=rem*power[digit-1];
}

int main()
{
    int cases;

    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);

    scanf("%d",&cases);


    int a,b,temp,count,cnt;
    for (int m=1;m<=cases;++m)
    {
        scanf("%d %d",&a,&b);

        memset(vis,false,sizeof(vis));

        temp=a;
        digit=0;

        while (temp)
        {
            temp/=10;
            ++digit;
        }



        count=0;
        for (int i=a;i<=b;++i)
        {
            cnt=1;
            temp=i;
            while (!vis[temp])
            {
                vis[temp]=true;
                rever(temp);

                if (temp>=a && temp <=b && !vis[temp])
                    ++cnt;

            }


            count+=fact[cnt];

        }
        printf("Case #%d: %d\n",m,count);


    }
}
