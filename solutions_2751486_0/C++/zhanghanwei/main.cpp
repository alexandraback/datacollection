#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<map>
#include<queue>
#include<cstdlib>
#include<string>
#include<iostream>
using namespace std;
char s[1000050];
bool is1(char a)
{
    if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u')
        return 0;
    return 1;
}
int main()
{
    long long k,t,i,j,n,m,T;
    freopen("A-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%I64d",&T);
    for(t=1;t<=T;++t)
    {
        scanf("%s%I64d",s,&n);
        long long summ=0;
        long long en=strlen(s),st=0;
       // printf("%s\n%I64d\n",s,n);
        for(i=0;i<en;++i)
        {
            k=1;
            if(is1(s[i]))
            {
                while(i+k<en&&is1(s[i+k])&&k<n)k++;
                if(k==n)
                {
                    summ+=(i-st+1)*(en-(i+k-1));
                    //printf("%I64d %I64d\n",(i-st+1),(en-(i+k-1)));
                    st=i+1;
                }
            }
        }
        printf("Case #%I64d: %I64d\n",t,summ);
    }
    return 0;
}
