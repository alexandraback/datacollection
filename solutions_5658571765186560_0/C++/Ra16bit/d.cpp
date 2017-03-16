#include <cstdio>
#include <algorithm>
using namespace std;
int t,tt,x,n,m;
int main() {
  scanf("%d",&tt);
  for (t=1; t<=tt; t++) {
    scanf("%d%d%d",&x,&n,&m);
    if (n<m) swap(n,m);
    printf("Case #%d: ",t);
    if (x>6 || x>n || (n*m)%x!=0) { puts("RICHARD"); continue; }
    if (x==3 && m<2) { puts("RICHARD"); continue; }
    if (x==4 && m<3) { puts("RICHARD"); continue; }
    if (x==5 && m<4) { puts("RICHARD"); continue; }
    if (x==6 && m<4) { puts("RICHARD"); continue; }
    puts("GABRIEL");
  }
  return 0;
}

