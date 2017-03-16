#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
char str[2010],ans[2010];
int main()
{
    freopen("dd.in","r",stdin);
    freopen("out.txt","w+",stdout);
    int ncase,T=0;
    scanf("%d",&ncase);
    while(ncase--){
        printf("Case #%d: ",++T);
        int l=1000,r=1001;
        scanf("%s",str);
        int n=strlen(str);
        char top=0;
        for(int i=0;i<n;i++){
            if(str[i]>=top)
               ans[l--]=str[i],top=str[i];
            else
               ans[r++]=str[i];

        }
        for(int i=l+1;i<r;i++)
            printf("%c",ans[i]);
        printf("\n");
    }
    return 0;
}
