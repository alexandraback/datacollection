#include <stdio.h>
#include <algorithm>

using namespace std;

long double a[2000],b[2000],r,s;
long long i,j,k,l,m,n,t,tt;

int main()
{

scanf("%lld", &t);

for(tt=1;tt<=t;tt++) {
  scanf("%lld", &n);
  
  for(i=0;i<n;i++) scanf("%Lf", a+i);
  for(i=0;i<n;i++) scanf("%Lf", b+i);
  
  sort(a,a+n);
  sort(b,b+n);
  
  i = n-1;
  j = n-1;
  k = 0;
  
  while(i>=0 && j>=0) {
   if(b[j] > a[i]) {k++; i--; j--; continue;}
  
   i--;
  }
  
  j = 0;
  l = 0;
  
  for(i = 0; i < n; i++) {
    if(a[i]<b[j]) continue;
    
    j++;
    l++;
  }
  
/*  
  for(i=0;i<n;i++) printf("%.3Lf, ",a[i]);
  printf("\n");
  for(i=0;i<n;i++) printf("%.3Lf, ",b[i]);
  printf("\n");
*/  
  printf("Case #%lld: %lld %lld\n", tt, l, n-k);

}


return 0;
}