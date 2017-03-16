#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int T,N,d[1000100];
char s[1000100];
int main()
{
    freopen("input.in","r",stdin);
    freopen("bla.out","w",stdout);
    scanf("%d",&T);
    for(int x=1;x<=T;++x)
    {
        scanf("%s%d",s,&N);
        int y=strlen(s);
        for(int i=0;i<y;++i)
        {
            if(s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u')
                d[i]=1;
            else
                d[i]=0;
        }

        int first=0;
        int last=0;
        int rez=0;
        int that=0;

        while(first<y &&last<y)
        {
            //printf("%d %d %d %d\n",first,last,that,rez);
            while(d[first]==0)
                ++first;

            if(d[first]==1)
            {
                if(d[last]==1 && last-first==N-1)
                {

                    rez=rez+(y-last)*(first-that+1);
                    ++first;
                    that=first;
                }
                else if(d[last]==1 && last-first<N-1)
                    ++last;

                else if(d[last]==0)
                {
                    first=last+1;
                    ++last;
                }
            }
        }

        printf("Case #%d: %d\n",x,rez);
    }
    return 0;
}
