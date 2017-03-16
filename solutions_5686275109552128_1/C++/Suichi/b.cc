#include<cstdio>
#include<algorithm>

using namespace std;
int D;
int P[1001];


void read(){
  scanf("%d",&D);
  int r;
  for(int i=0;i<D;i++){
    scanf("%d",&r);
    P[r]++;
  }
}

int solve(int T){
  int ans=999999999;
  int divide=0;
  int initmax=0;
  for(int i=1;i<=1000;i++){
    if(P[i]>0)initmax=i;
  }
  for(int i=1;i<=initmax;i++){
    divide=0;
    for(int j=i+1;j<=initmax;j++){
      if(P[j]==0)continue;
      divide+=(((j-1)/i + 1)-1) * P[j];
    }
    ans=min(divide+i,ans);
  }
  printf("CASE #%d: %d\n",T,ans);
}

int main(){
  int T;
  scanf("%d",&T);
  for(int i=1;i<=T;i++){
    for(int j=0;j<=1000;j++){
      P[j]=0;
    }
    read();
    solve(i);
  }
}
