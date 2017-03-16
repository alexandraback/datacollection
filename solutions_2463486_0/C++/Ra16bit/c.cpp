#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int t,tt,j,a[22];
long long i,ii,l,r;
vector<long long> v;
int main() {
  freopen("Cs.in","r",stdin);
  freopen("Cs.out","w",stdout);
  for (i=1; i<=10000000; i++) {
    for (j=0, ii=i; ii>0; j++, ii/=10) a[j]=ii%10;
	for (ii=0; ii<j; ii++) if (a[ii]!=a[j-1-ii]) break;
	if (ii<j) continue;
	for (j=0, ii=i*i; ii>0; j++, ii/=10) a[j]=ii%10;
	for (ii=0; ii<j; ii++) if (a[ii]!=a[j-1-ii]) break;
	if (ii>=j) v.push_back(i*i);
  }
  v.push_back(1000000000000000LL);
  scanf("%d",&tt);
  for (t=1; t<=tt; t++) {
    scanf("%I64d%I64d",&l,&r);
    printf("Case #%d: %d\n",t,lower_bound(v.begin(),v.end(),r+1)-lower_bound(v.begin(),v.end(),l));
  }
  return 0;
}
