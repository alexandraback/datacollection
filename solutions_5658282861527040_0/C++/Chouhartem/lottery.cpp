#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  int T;
  cin >> T;
  for (int C = 1; C <= T; ++C){
    int a,b,k;
    cin >> a >> b >> k;
    long long count = 0;
    for (int i = 0; i < a; ++i) {
      for (int j = 0; j < b; ++j) {
        if ( (i & j) < k )
          ++count;
      }
    }
    cout << "Case #" << C << ": " << count << endl;
  }
}
