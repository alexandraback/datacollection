#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
  int t;
  scanf("%d",&t);
  for(int test=1; test<=t; test++){
    int n, suprise, p;
    int normal=0;
    int may=0;
    scanf("%d %d %d",&n, &suprise, &p);
    for(int i=0; i<n ; i++){
      int score;
      scanf("%d", &score);
      if(3*p-2<=score){
        normal++;
        continue;
      }
      if(p-2>=0 && 3*p-4<=score) may++;
    }
    printf("Case #%d: %d\n",test,normal+min(may,suprise));
  }
  return 0;
}

