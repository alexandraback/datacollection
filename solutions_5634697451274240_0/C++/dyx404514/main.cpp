#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
char str[110];
int main()
{
    freopen("dd.in","r",stdin);
    freopen("out.txt","w+",stdout);
    int ncase,T=0;
    scanf("%d",&ncase);
    while(ncase--){
        printf("Case #%d: ",++T);
        scanf("%s",str);
        int n=strlen(str)-1;
        int ans=0;
        while(n>=0&&str[n]!='-')
            n--;
        if(n<0)
            printf("%d\n",ans);
        else{
            ans++;
            for(int i=n-1;i>=0;i--)
                if(str[i]!=str[i+1])
                    ans++;
            printf("%d\n",ans);
        }
    }
    return 0;
}
