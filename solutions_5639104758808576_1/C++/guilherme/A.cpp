#include<cstdio>
#include<cstring>

char ent [99999];
int main () {
  int tt;
  scanf("%d",&tt);
  for(int rr=1;rr<=tt;rr++) {
    int n;
    scanf("%d %s",&n,ent);
    int need = 0;
    int tem = 0;
    for (int i=0;i<=n;i++){
      int x = ent[i] - '0';
      if (i>tem) {
	need += i-tem;
	tem += x + i-tem;
      }
      else {
	tem += x;
      }
    }
    printf("Case #%d: %d\n",rr,need);
  }
  return 0;
}
