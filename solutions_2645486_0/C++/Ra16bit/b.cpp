#include <cstdio>
#include <algorithm>
using namespace std;
int t,tt,i,ii,n,l,r,e;
bool u[10010];
pair<int,int> a[10010];
long long b[10010],c[10010],m,cur,now,res;
int main() {
  freopen("Bs.in","r",stdin);
  freopen("Bs.out","w",stdout);
  scanf("%d",&tt);
  for (t=1; t<=tt; t++) {
    scanf("%d%I64d%d",&e,&m,&n);
	for (i=0; i<n; i++) { scanf("%d",&a[i].first); a[i].second=i+1; u[i+1]=false; }
	sort(a,a+n);
	reverse(a,a+n);
	for (res=ii=0; ii<n; ii++) {
	  i=a[ii].second;
	  for (l=i; l>0 && !u[l]; l--);
	  for (r=i; r<=n && !u[r]; r++);
	  if (l==0) cur=e; else cur=min((long long)e,c[l]+m*(i-l));
	  if (r>n) now=0; else now=max(0LL,b[r]-m*(r-i));
	  //printf("%d %d | %d %d | %I64d %I64d\n",a[ii].first,a[ii].second,l,r,cur,now);
	  res+=(cur-now)*a[ii].first;
	  u[i]=true;
	  b[i]=cur;
	  c[i]=now;
	}
    printf("Case #%d: %I64d\n",t,res);
  }
  return 0;
}
