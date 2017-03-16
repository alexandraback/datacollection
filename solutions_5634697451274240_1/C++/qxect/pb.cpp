#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<ctime>
#include<cmath>

#include<algorithm>
#include<bitset>
#include<complex>
#include<deque>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<vector>
using namespace std;
char str[200];
int main(int argc, const char *argv[])
{
  int tn;
  int cnt, pos;
  int len;
  int i, z;
  cin >> tn;
  for (z = 1; z <= tn; z++) {
    scanf("%s", str);
    len = strlen(str);
    cnt = 0;
    pos = 0;
    for(i = 0; i < len; i++){
      if((!i) || str[i] != str[i-1]){
        cnt++;
        pos = (str[i]=='+');
      }
    }
    if(pos) cnt--;

    printf("Case #%d: %d\n", z, cnt);
  }
  return 0;
}
