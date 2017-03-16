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
char str[5000], ans[5000];

int main()
{
  int tn;
  int i, z;
  int p, q;
  cin >> tn;
  for (z = 1; z <= tn; z++) {
    scanf("%s", str);
    p = q = 1500;
    ans[p] = str[0];
    for(i = 1; str[i]; i++){
      if(str[i] >= ans[p])
        p = p -1, ans[p] = str[i];
      else
        q = q +1, ans[q] = str[i];
    }
    ans[q+1] = '\0';
    printf("Case #%d: %s\n", z, ans + p);
  }
  return 0;
}
