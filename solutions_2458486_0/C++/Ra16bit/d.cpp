#include <cstdio>
#include <vector>
using namespace std;
int t,tt,i,j,k,n,x,cur,a[202],b[202],o[22];
vector <int> g[22];
bool f[(1<<20)+5];
int main() {
  freopen("Ds.in","r",stdin);
  freopen("Ds.out","w",stdout);
  scanf("%d",&tt);
  for (t=1; t<=tt; t++) {
    scanf("%d%d",&k,&n);
	for (i=0; i<=200; i++) a[i]=0;
	for (i=0; i<k; i++) {
	  scanf("%d",&x);
	  a[x]++;
	}
	for (i=0; i<n; i++) {
	  scanf("%d%d",&o[i],&cur);
	  g[i].clear();
	  for (j=0; j<cur; j++) {
	    scanf("%d",&x);
		g[i].push_back(x);
	  }
	}
	f[0]=true;
	for (i=1; i<(1<<n); i++) {
	  f[i]=false;
	  for (j=0; j<=200; j++) b[j]=a[j];
	  for (j=0; j<n; j++) if ((i&(1<<j))==0) {
	    b[o[j]]--;
	    for (k=0; k<g[j].size(); k++) b[g[j][k]]++;
	  }
	  for (j=0; j<n; j++) if ((i&(1<<j)) && b[o[j]]>0) f[i]|=f[i^(1<<j)];
	}
    printf("Case #%d: ",t);
	if (f[(1<<n)-1]) {
	  for (i=(1<<n)-1; i!=0; ) {
	    for (j=0; j<=200; j++) b[j]=a[j];
	    for (j=0; j<n; j++) if ((i&(1<<j))==0) {
	      b[o[j]]--;
	      for (k=0; k<g[j].size(); k++) b[g[j][k]]++;
	    }
	    for (j=0; j<n; j++) if ((i&(1<<j)) && b[o[j]]>0 && f[i^(1<<j)]) {
		  printf("%d",j+1);
		  i^=(1<<j);
		  putchar(i==0?'\n':' ');
		  break;
		}
	  }
	} else puts("IMPOSSIBLE");
  }
  return 0;
}
