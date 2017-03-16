#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>

using namespace std;

typedef vector<int> VI;


int main()
{
  int n;
  cin >> n;
  vector<int> S = { 1, 4,  9, 121, 484};
  for (int i = 1; i <= n; i++) {
    int A, B, count;
    cin >> A >> B;
    count = count_if(S.begin(), S.end(), 
                     [&](int i) {return ((i<=B)&&(i>=A));});
    printf("Case #%d: %d\n", i, count);
  }
  return 0;
}

