#include<bits/stdc++.h>
using namespace std;

char ans[100];

int main(){
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    int test;
    scanf("%d",&test);

    int len,tot;
    scanf("%d%d",&len,&tot);

    puts("Case #1:");
    int x=0;
    while(tot--){
        ans[0]=ans[1]=ans[len-1]=ans[len-2]='1';
        int tmp=x;
        for(int i=0,j=len-3;i<(len-4)/2;i++,j-=2){
            ans[j]=ans[j-1]='0'+(tmp&1);
            tmp>>=1;
        }
        x++;
        printf("%s 3 2 5 2 7 2 9 2 11\n",ans);
    }

    return 0;
}
