#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1005;
char input[maxn];
int sum[maxn];
int main()
{
    int T,Smax,index=1;
    freopen("A-large.in","r",stdin);
    freopen("A.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %s",&Smax,input);
        memset(sum,0,sizeof(sum));
        int len=strlen(input);
        int need=0;
        sum[0]=input[0]-'0';
       // cout<<len<<endl;
        for(int i=1; i<len; i++)
        {
            if(input[i]!='0')
            {
                if(i<=sum[i-1])
                {
                    sum[i]=sum[i-1]+input[i]-'0';
                    //  continue;
                }
                else
                {
                    need+=(i-sum[i-1]);
                    sum[i]=i+input[i]-'0';
                }
            }
            else
                sum[i]=sum[i-1];
        }
        printf("Case #%d: %d\n",index++,need);
    }
    return 0;
}
