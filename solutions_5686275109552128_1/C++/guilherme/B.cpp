#include<cstdio>
#include<algorithm>
using namespace std;
int pan[9999];
int main () {
  int tt;
  scanf("%d",&tt);
  for(int rr=1;rr<=tt;rr++){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
      scanf("%d",&pan[i]);
    }
    sort(pan,pan+n);
    reverse(pan,pan+n);

    int ret = pan[0];
    for(int i=1;i<=pan[0];i++){//resp
      bool fim = false;
      for(int j=0;j<i;j++){//special
	bool ok = true;
	int target = i-j;
	int cuts = 0;

	for(int k=0;k<n;k++){
	  if(pan[k]<=target) break;
	  cuts += (pan[k]-1)/target;

	  if (cuts > j){ok=false;break;}
	}
	if(cuts<j){
	  throw "perdi";
	}
	if(ok){fim=true;break;}

      }
      if(fim){ret=i;break;}
    }
    printf("Case #%d: %d\n",rr,ret);
  }
  return 0;
}
