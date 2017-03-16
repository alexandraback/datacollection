#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
char str[1010];
int main()
{
    freopen("DD.in","r",stdin);
    freopen("out.txt","w+",stdout);
    int ncase,T=0;
    scanf("%d",&ncase);
    while(ncase--)
    {
        printf("Case #%d: ",++T);
        int n;
        scanf("%d%s",&n,str);
        int num=0,sum=0;
        for(int i=0;i<=n;i++){
            int tmp=str[i]-'0';
            if(sum<i)
            {
                num+=i-sum;
                sum=i;
            }
            sum+=tmp;
        }
        printf("%d\n",num);
    }
    return 0;
}
