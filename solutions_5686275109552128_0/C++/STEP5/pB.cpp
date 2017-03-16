#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1010;

int N;
int arr[MAXN];

int main()
{
  ios_base::sync_with_stdio(0);

  int T;
  cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    cin >> N;
    for(int i=0; i<N; i++)
      cin >> arr[i];

    int ans = MAXN;
    for(int i=1; i<MAXN; i++)
    {
      int cur = i;
      for(int j=0; j<N; j++)
        if(arr[j] > i)
          cur += (arr[j]-1) / i;
      ans = min(ans, cur);
    }
    cout << "Case #" << tt << ": " << ans << endl;
  }

  return 0;
}
