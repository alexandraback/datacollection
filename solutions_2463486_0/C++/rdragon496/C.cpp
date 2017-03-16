#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<queue>
#define MAXN 64
#define INF 1<<30
///
using namespace std;

char check(char a,char b,char c,char d)
{
    if(a==b&&b==c&&c==d&&d!='.'&&d!='T') return d;
    if(a==b&&b==c&&c!=d&&c!='.'&&d=='T') return c;
    if(a==b&&b==d&&c!=d&&d!='.'&&c=='T') return d;
    if(a==c&&c==d&&b!=d&&d!='.'&&b=='T') return d;
    if(b==c&&c==d&&a!=d&&d!='.'&&a=='T') return d;
    return 0;
}

int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int cases;
    scanf("%d",&cases);
    int a,b;
    for(int t=1; t<=cases; t++)
    {
        scanf("%d %d",&a,&b);
        int ans=0;
        int temp[5];
        for(int i=a; i<=b; i++)
        {
            int x=(int)(sqrt(1.0*i)+1e-6);
            if(x*x==i)
            {
                int tmp=x;
                int cnt=0;
                while(tmp)
                {
                    temp[cnt++]=tmp%10;
                    tmp/=10;
                }
                bool flag=true;
                for(int j=0; j<cnt/2; j++)
                {
                    if(temp[j]!=temp[cnt-1-j])
                    {
                        flag=false;
                        break;
                    }
                }
                if(flag)
                {
                    cnt=0;
                    tmp=i;
                    while(tmp)
                    {
                        temp[cnt++]=tmp%10;
                        tmp/=10;
                    }
                    bool flag1=true;
                    for(int j=0; j<cnt/2; j++)
                    {
                        if(temp[j]!=temp[cnt-1-j])
                        {
                            flag1=false;
                            break;
                        }
                    }
                    if(flag1) ans++;
                }
            }
        }
        printf("Case #%d: %d\n",t,ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
