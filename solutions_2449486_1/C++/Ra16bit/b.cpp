#include <cstdio>
using namespace std;
int t,tt,n,m,i,j,k,a[111][111],b[111],c[111];
int main() {
  freopen("Bl.in","r",stdin);
  freopen("Bl.out","w",stdout);
  scanf("%d",&tt);
  for (t=1; t<=tt; t++) {
    scanf("%d%d",&n,&m);
	for (i=0; i<n; i++) c[i]=0;
	for (i=0; i<m; i++) b[i]=0;
	for (i=0; i<n; i++) for (j=0; j<m; j++) scanf("%d",&a[i][j]);
	printf("Case #%d: ",t);
	for (k=1; k<=100; k++) {
	  for (i=0; i<n; i++) for (j=0; j<m; j++) if (a[i][j]==k) {
		c[i]++; b[j]++;
	  }
	  bool q=true;
	  for (i=0; i<n; i++) for (j=0; j<m; j++) if (a[i][j]==k && c[i]!=m && b[j]!=n) q=false;
	  if (!q) {
	    puts("NO");
		break;
	  }
	}
	if (k>100) puts("YES");
  }
  return 0;
}
