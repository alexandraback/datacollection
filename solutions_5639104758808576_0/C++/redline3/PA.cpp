#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int tt;
int smax;
char str[1010];

int main(void){
  int i, j;
  int sum;
  int add;
  scanf("%d", &tt);
  for(int tc=1; tc<=tt; ++tc){
    scanf("%d %s", &smax, str);
    sum = add = 0;
    for(i=0; i<=smax; ++i){
      if(sum < i){
        add += i-sum;
        sum = i;
      }
      sum += str[i] - '0';
    }
    printf("Case #%d: %d\n", tc, add);
  }
  return 0;
}
