#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

int num[21];
int dp[2000001];
int pre[2000001];
int main() {
  freopen("C.in","r",stdin);
  freopen("C.out","w",stdout);
  int cas,n;
  scanf("%d",&cas);
  for(int t=1;t<=cas;t++) {
    scanf("%d",&n);
    int L,R=0;
    for(int i=0;i<n;i++)scanf("%d",&num[i]),R+=num[i];
    printf("Case #%d:\n",t);
    sort(num,num+n);
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    int pos=-1,val;
    for(int i=0;i<n&&pos==-1;i++) {
      for(int k=R;k>=num[i];k--) {

        dp[k]+=dp[k-num[i]];
        if(dp[k]==1&&dp[k-num[i]]==1) {
          pre[k]=i;
        }
        if(dp[k]>1) {
          pos=i;
          val=k;
          break;
        }
      }
    }
    int res[2][20];
    int cnt0=0,cnt1=0;
    //printf("dp[3]:%dpre[3]:%d\n",dp[3],pre[3]);
    //printf("val:%dpos:%d\n",val,pos);
    if(pos!=-1) {
      int tmp=val;
      while(tmp) {
        //printf("%d ",pre[tmp]);
        res[0][cnt0++]=pre[tmp];
        tmp-=num[pre[tmp]];


      }
      for(int i=0;i<cnt0;i++) {
        printf("%d",num[res[0][i]]);
        if(i!=cnt0-1) {
          printf(" ");
        } else printf("\n");
      }
      res[1][cnt1++]=pos;
      tmp=val-num[pos];
      while(tmp) {
        res[1][cnt1++]=pre[tmp];
        tmp-=num[pre[tmp]];

      }
      for(int i=0;i<cnt1;i++) {
        printf("%d",num[res[1][i]]);
        if(i!=cnt1-1) {
          printf(" ");
        } else printf("\n");
      }
    } else {
      printf("Impossible\n");
    }
  }
  return 0;
}
