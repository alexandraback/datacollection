#include <cstdio>
#include <iostream>
#define MAX 2000000
using namespace std;

typedef long long int llint;
int   A[10000001];
llint sol;
int POW[10];
int to,tmp;
int T,a,b;
int L[2][10];

int main(){
  POW[0]=1;
  for (int i=1; i<10; i++) POW[i]=POW[i-1]*10;

  scanf("%d",&T);
  for (int t=1; t<=T; t++){
    memset(A,0,sizeof A);
    scanf("%d %d",&a,&b);
    sol=0;
    for (int i=a; i<=b; i++){
      sol+=A[i];
      
      to=0; tmp=i; // counting the number of digits (to)
      while (tmp>0) {to++; tmp/=10;}
      
      A[i]++;
      tmp=i;
      L[0][0]=tmp;
      L[1][0]=A[tmp];
      for (int j=1; j<to; j++){
	tmp*=10;
	tmp+=(tmp/POW[to])%10;
	tmp%=POW[to];
	
	if (tmp>=POW[to-1]) {L[0][j]=tmp; L[1][j]=A[tmp];}
	else L[0][j]=-1;
      }
      for (int j=0; j<to; j++) if (L[0][j]>=0 && A[L[0][j]]==L[1][j]) A[L[0][j]]++;
    }
    printf("Case #%d: %lld\n",t,sol);
  }
}

