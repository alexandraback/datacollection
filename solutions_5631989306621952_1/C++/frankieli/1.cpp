#include <cstdio>
#include <cstdlib>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
char str[1001];
int main(){
  int n;
  scanf("%d",&n);
  for(int i = 0 ; i < n; i++){
    scanf("%s",str);
    string s = "";
    s += str[0];
    for(int j = 1; j < strlen(str); j++){
      if((str[j]+s) > (s+str[j]))
        s = str[j]+s;
      else
        s = s+str[j];
    }
    printf("Case #%d: %s\n", i+1, s.c_str());
  }
}
