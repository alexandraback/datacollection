#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;
int t,tt,a[14],now[14],col[14],z[14],r,n,m,k,e,i,j;
bool q;
void rec(int l, int f) {
  if (l==k) return;
  for (int i=f; i<m; i++) {
    int j;
    for (j=0; j<k; j++) if (now[j]%col[i]==0) break;
	if (j<k) {
	  a[l]=col[i];
	  bool w=true;
	  for (j=0; j<k; j++) {
	    if (now[j]%col[i]==0) now[j]/=col[i];
		if (now[j]>1) w=false;
	  }
	  /*printf("%d: (%d)\n",l,i);
	  for (j=0; j<=l; j++) printf("%d, ",a[j]);
	  puts("...");
	  for (j=0; j<k; j++) printf("%d ",now[j]); puts("now");*/
	  if (w) {
	    for (j=0; j<=l; j++) printf("%d",a[j]);
	    for (j=l+1; j<k; j++) printf("%d",col[rand()%(m-1)]);
		q=true;
	    return;
	  }
      rec(l+1,i);
	  break;
	}
  }
}
int main() {
  freopen("Cs2.in","r",stdin);
  freopen("Cs2.out","w",stdout);
  srand(time(0));
  scanf("%d",&tt);
  fprintf(stderr,"re\n");
  for (t=1; t<=tt; t++) {
    scanf("%d%d%d%d",&r,&n,&m,&k);
	for (i=0; i<m-1; i++) col[i]=i+2;
	printf("Case #%d:\n",t);
	while (r--) {
	  for (e=0; e<k; e++) { scanf("%d",&now[e]); z[e]=now[e]; }
	  q=false;
	  for (int it=0; !q && it<10000; it++) {
	    for (e=0; e<k; e++) now[e]=z[e];
	    random_shuffle(col,col+m-1);
	    rec(0,0);
	  }
	  if (!q) for (i=0; i<k; i++) printf("1");
	  puts("");
	  fprintf(stderr," #%d\n",r);
    }
  }
  return 0;
}
