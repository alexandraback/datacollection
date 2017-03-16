#include<iostream>
#include<string>
#include<stdio.h>
#include<math.h>
using namespace std;

int main()
{
    int i,j,k,hash[31][11],l;
    for(i=0;i<=30;i++) {
        for(j=0;j<=10;j++) hash[i][j]=0;
    }
    for(i=0;i<=10;i++) {
        for(j=i;j<=10;j++) {
            for(k=j;k<=10&&k-i<=2;k++) {
                for(l=0;l<=k;l++) {
                    if(k-i==2) {
                        if(hash[i+j+k][l]==0) hash[i+j+k][l]=2;
                    }
                    else {
                        hash[i+j+k][l]=1;
                    }
                }
            }
        }
    }
    for(i=0;i<=30;i++) {
        //for(j=0;j<=10;j++) printf("%d ",hash[i][j]);
      //  printf("\n");
    }
    
    freopen("B-large.in","r",stdin);
    freopen("B.txt","w",stdout);
    int T,N,S,p,t,ans,flag,a,b;
    scanf("%d",&T);
    for(i=1;i<=T;i++) {
        ans=0;
        flag=0;
        scanf("%d%d%d",&N,&S,&p);
        for(j=0;j<N;j++) {
            scanf("%d",&t);
            if(hash[t][p]==1) ans++;
            else if(hash[t][p]==2) flag++;
        }
        if(flag>=S) ans+=S;
        else ans+=flag;
        printf("Case #%d: %d\n",i,ans);
    }
   // system("pause");
    return 0;
}
