#include<cstdio>

int main () {
  int tt;
  scanf ("%d",&tt);
  for(int rr=1;rr<=tt;rr++){
    int x,r,c;
    scanf("%d %d %d",&x,&r,&c);
    bool ok = true;
    if (x==1) {
      ok = true;
    } else if (x==2) {
      ok = (((r*c)%2) == 0);
    } else if (x==3) {
      ok = false;
      if ((r*c)%3==0 && r>=2 && c>=2) {
	ok = true;
      } 
    } else if (x==4) {
      ok = false;
      if ((r*c)%4==0 && r>=3 && c>=3) {
	ok = true;
      }
    }
    printf("Case #%d: ",rr);
    if (ok) {
      printf("GABRIEL\n");
    } else {
      printf("RICHARD\n");
    }

  }
  return 0;
}
