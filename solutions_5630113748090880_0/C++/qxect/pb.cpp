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
map<int, int> lib;
int main()
{
  int tn;
  int n;
  int z, i, j;
  int t;
  map<int, int>::iterator itr;
  vector<int> arr;
  cin >> tn;
  for (z = 1; z <= tn; z++) {
    lib.clear();
    printf("Case #%d:", z);
    cin >> n;
    for(i=0; i<n+n-1; i++){
      for(j=0; j<n; j++){
        scanf("%d", &t);
        if(lib.count(t) == 0)
          lib[t] = 1;
        else
          lib[t]++;
      }
    }
    arr.clear();
    for(itr = lib.begin(); itr != lib.end(); itr++)
      if((itr->second) % 2 ==1)
        arr.push_back(itr->first);
    sort(arr.begin(), arr.end());
    for(i = 0; i < n; i++)
      printf(" %d", arr[i]);
    puts("");
  }
  return 0;
}
