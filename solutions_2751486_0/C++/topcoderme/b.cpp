#include<stdio.h>
#include<string.h>
using namespace std;

char s[1000050];
inline bool isc(char ch)
{
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
        return 0;
    return 1;
}

int main()
{
    int t,n,c,res,lp,len,i;
    scanf("%d\n",&t);
    for(int w=1;w<=t;w++)
    {
        scanf("%s %d",s,&n);
       // printf("%s1\n",s);
        //printf("%d\n",n);
        c=0;res=0;lp=-1;
        len=strlen(s);

        for(i=0;s[i]!='\0';i++)
        {
            if(isc(s[i]))
                c++;
            else c=0;
            if(c==n)
            {
                c--;
                res+=(i-n-lp+1)*(len-i-1+1);
                lp=i-n+1;

            }


        }
        //Case #1: 4
        printf("Case #%d: %d\n",w,res);

    }
}
