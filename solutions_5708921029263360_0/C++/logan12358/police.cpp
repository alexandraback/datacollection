#include <cstdio>
#include <vector>
using namespace std;

#define min(a, b) ((a)<(b)?(a):(b))

int main() {
  int t; scanf("%d", &t);
  for(int _i=1; _i<=t; _i++) {
    int j, p, s, k; scanf("%d %d %d %d", &j, &p, &s, &k);
    //printf("Case #%d: (%d %d %d %d) ", _i, j, p, s, k);
    printf("Case #%d: ", _i);
    int a=0, b=0, c=0;
    vector<int> res;
    for(a=0; a<j; a++) {
      c=0;
      for(b=0; b<p; b++) {
        int S=c%s;
        for(int d=0; d<k; d++) {
          //printf("%d %d %d\n", a+1, b+1, c%s+1);
          res.push_back(a+b*10+(c%s)*100);
          c++;
          if(c%s==S) {
            break;
          }
        }
      }
    }
    printf("%d\n", res.size());
    for(auto x : res) {
      printf("%d %d %d\n", x%10+1, (x/10)%10+1, (x/100)%10+1);
    }
  }
}
