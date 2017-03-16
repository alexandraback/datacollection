#define DEBUG 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int len(int n) {
  int i;
  for(i=0;n>0;i++,n/=10);
  return i;
}

void d(int N[7], int n, int l) {
  int i;
  for(i=l-1;i>=0;i--) {
    N[i]=n%10;
    n/=10;
  }
}

int c(int N[7], int l) {
  int i, ans=0;
  for(i=0;i<l;i++)
    ans=ans*10+N[i];
  return ans;
}

void r(int N[7], int l) {
  int i, tmp;
  tmp=N[0];
  for(i=0;i<l-1;i++)
    N[i]=N[i+1];
  N[i]=tmp;
}

int calc(int N[7], int l, int b, int n) {
  int i, j, m, ans=0, u[6], nu=0;
  for(i=0;i<l-1;i++) {
    r(N,l);
    m=c(N,l);
    for(j=0;j<nu;j++)
      if(u[j]==m) {
	j=nu;
	m=-1;
      }
    if(m>n && m<=b) {
      ans++;
      u[nu++]=m;
      if(DEBUG) printf("%d %d\n", n, m);
    }
  }
  return ans;
}

int main(void) {
  int i;
  int ans;
  int tc, cn, a, b, N[7], M[7], l, n, m;

  scanf("%d", &tc);
  for(cn=1;cn<=tc;cn++) {
    scanf("%d%d", &a, &b);
    l=len(a);
    ans=0;
    for(n=a;n<b;n++) {
      d(N, n, l);
      ans+=calc(N, l, b, n);
    }
    printf("Case #%d: %d\n", cn, ans);
  }
  return 0;
}
