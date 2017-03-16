#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
int t,tt,a[14],now[14],r,n,m,k,e,i,j;
vector<vector<long long> > all;
vector<long long> cur,num;
vector<long long> ret() {
  vector<long long> v;
  for (int i=0; i<(1<<n); i++) {
    long long z=1;
	for (int j=0; j<n; j++) if (i&(1<<j)) z*=a[j];
	v.push_back(z);
  }
  return v;
}
void rec(int l, long long s, int f) {
  if (l==n) {
    all.push_back(ret());
	num.push_back(s);
	//printf("~%I64d\n",s);
	//for (int i=0; i<all.back().size(); i++) printf("%I64d, ",all.back()[i]); puts("");
    return;
  }
  for (int i=f; i<=m; i++) {
    a[l]=i;
    rec(l+1,s*10+i,i);
  }
}
int main() {
  freopen("Cs1.in","r",stdin);
  freopen("Cs1.out","w",stdout);
  srand(time(0));
  scanf("%d",&tt);
  for (t=1; t<=tt; t++) {
    scanf("%d%d%d%d",&r,&n,&m,&k);
	rec(0,0,2);
	printf("Case #%d:\n",t);
	while (r--) {
	  for (e=0; e<k; e++) scanf("%d",&now[e]);
	  cur.clear();
	  for (i=0; i<all.size(); i++) {
	    for (e=0; e<k; e++) {
	      for (j=0; j<all[i].size(); j++) if (all[i][j]==now[e]) break;
		  if (j>=all[i].size()) break;
	    }
	    if (e>=k) cur.push_back(i);
	  }
	  printf("%I64d\n",num[cur[rand()%cur.size()]]);
    }
  }
  return 0;
}
