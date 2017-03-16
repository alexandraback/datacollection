#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

char s[1000050];
int n;
bool iscon(char a)
{
    if (a!='a'&&a!='e'&&a!='i'&&a!='o'&&a!='u')return true;
    return false;
}
int main()
{
    freopen("A-small-attempt0 (1).in","r",stdin);
    freopen("out.txt","w",stdout);
    int amm,cnt=0;
    scanf("%d",&amm);
    while (amm--)
    {
        cnt++;
        scanf("%s%d",s,&n);
        int l=strlen(s);
        int TOT=l*(l+1)/2;
        int temp=0,last=0;
        for (int i=0;i<l;i++)
        {
            //printf("%d  %d  %d\n",i,TOT,temp);
            if (iscon(s[i]))
            {
                temp++;
                while (i+1<l&&iscon(s[i+1]))
                {
            //printf("  %d\n",temp);
                    temp++;
                    i++;
                }
                if (temp>=n)
                {
                    TOT-=((i-temp+n-last)*(i-temp+n-last+1)/2);
            //printf("     %d  %d\n",TOT,temp);
                    TOT+=((n-1)*n/2);
            //printf("     %d\n",TOT);

                    TOT-=(temp*(n-1));
            //printf("     %d  %d\n",TOT,temp);
                    TOT+=(n-1)*(n-2)/2;
            //printf("     %d\n",TOT);

                    TOT+=(n-1)*n/2;
            //printf("     %d\n",TOT);

                    last=i-(n-2);
                    temp=0;
                }
            }
            else
            {
                temp=0;
            }
        }
        TOT-=((l-last)*(l-last+1)/2);
        printf("Case #%d: %d\n",cnt,TOT);
    }
    return 0;
}
