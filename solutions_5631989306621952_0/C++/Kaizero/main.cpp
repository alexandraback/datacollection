#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
char p[1010], q[1010], inp[1010], Ans[1010];
int main(){
    int TT, TC, i, j;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&TC);
    for(TT=1;TT<=TC;TT++){
        scanf("%s",inp);
        for(i=0;inp[i];i++){
            Ans[i]=p[i]=q[i]=0;
        }
        Ans[i]=p[i]=q[i]=0;
        for(i=0;inp[i];i++){
            for(j=0;j<i;j++)p[j]=Ans[j],q[j+1]=Ans[j];
            p[i]=inp[i], q[0]=inp[i];
            if(strcmp(p,q)<0){
                for(j=0;j<=i;j++)Ans[j]=q[j];
            }
            else {
                for(j=0;j<=i;j++)Ans[j]=p[j];
            }
        }
        printf("Case #%d: %s\n",TT,Ans);
    }
}
