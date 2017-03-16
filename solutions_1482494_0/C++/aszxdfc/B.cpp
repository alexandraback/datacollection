#include<iostream>
#include<string>
#include<stdio.h>
#include<math.h>
using namespace std;

int main()
{
    freopen("B-small-attempt1.in","r",stdin);
    freopen("Bin.txt","w",stdout);
    int T,i,j,n,a[1100],b[1100];
    scanf("%d",&T);
   // printf("%d\n",T);
    for(i=1;i<=T;i++) {
        scanf("%d",&n);
      //  printf("\n%d\n",n);
        bool flag1=false;
        bool hasha[1100]={false},hashb[1100]={false};
        for(j=0;j<n;j++) {
            scanf("%d%d",&a[j],&b[j]);
         //   printf("%d %d\n",a[j],b[j]);
        }
        int ct,sum,ans;
        ct=sum=ans=0;
        while(ct<n) {
           // cout<<ct<<" "<<sum<<" "<<ans5<<endl;
            bool flag=false;
            for(j=0;j<n;j++) {
                if(!hashb[j]&&b[j]<=sum) {
                    if(hasha[j]==false) {
                        sum+=2;
                        hasha[j]=true;
                    }
                    else sum++;
                    ct++;
                    ans++;
                    hashb[j]=true;
                    flag=true;
                }
            }
            if(flag==false) {
                for(j=0;j<n;j++) {
                    if(!hasha[j]&&a[j]<=sum) {
                        sum++;
                        ans++;
                        hasha[j]=true;
                        break;
                    }
                }
                if(j==n) {
                    flag1=true;
                    break;
                }
            }
        }
        if(flag1) printf("Case #%d: Too Bad\n",i);
        else printf("Case #%d: %d\n",i,ans);
    }
    return 0;
}
        
