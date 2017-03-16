
#include <cstring>
#include <cstdio>
using namespace std;

int main(int argc, char *argv[]) {
  int Z;
  scanf("%d", &Z);
  for (int z=1;z<=Z;z++) {
    printf("Case #%d: ", z);
    char str[101];
    scanf("%s", str);
    int len = strlen(str);
    int res = str[len-1] == '-';
    for (int i=0;i<len-1;i++)
      res += str[i] != str[i+1];
    printf("%d\n", res);
  }
  return 0;
}
