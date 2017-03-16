#include <stdio.h>
#include <string>

using namespace std;

char keyboard[10];
char destination[10];
int ksize, dsize, total_presses;
int maxi, sum, total_res;

void generate(string s) {
  if(s.size() == total_presses) {
    int cnt = 0;
    for(int i=0; i<total_presses; ++i) {
      int ok = 1;
      for(int j=0; j<dsize; ++j) {
        if(s[i+j] != destination[j]) {
          ok = 0;
          break;
        }
      }
      cnt += ok;
    }
    if(maxi < cnt) maxi = cnt;
    sum += cnt;
    total_res++;
    return;
  }
  for(int i=0; i<ksize; ++i) {
    string t = s;
    t += keyboard[i];
    generate(t);
  }
}   
          
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int test;
  scanf("%d", &test);
  for(int t=1; t<=test; ++t) {
    scanf("%d %d %d\n", &ksize, &dsize, &total_presses);
    scanf("%s %s", keyboard, destination);
    maxi = sum = total_res = 0;
    generate(string());
    printf("Case #%d: %.7lf\n", t, 1.0*maxi - 1.0*sum/total_res);
  }
  return 0;
}
    
  