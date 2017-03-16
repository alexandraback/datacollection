#include <cstdio>
#include <cstring>
using namespace std;

int main(){
  freopen("A-small-attempt0.in","r",stdin);
  freopen("1.txt","w",stdout);  
  int tt, r, c, w;
  scanf("%d",&tt);
  for(int cas = 1; cas <= tt; ++cas){
    printf("Case #%d: ", cas);
    scanf("%d%d%d",&r,&c,&w);

    if(c%w==0) printf("%d\n", r*(c/w+w-1));
    else printf("%d\n", r*(c/w+w));

  }
  return 0;
}
