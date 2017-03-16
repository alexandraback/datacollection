#include <iostream>
#include <algorithm>

using namespace std;

int main() { //NEED TO TEST FLIPPED ARRAYS
  int x;
  cin >> x;
  for(int line = 1; line <= x; line++) {
    cout << "Case #" << line << ":";

    int n;
    cin >> n;
    int vals[2501] = {0};
    for(int i = 0; i < 2 * n - 1; i++) {
      for(int j = 0; j < n; j++) {
        int read;
        cin >> read;
        vals[read]++;
      }
    }

    int ret[50];
    int at = 0;
    for(int i = 0; i < 2501; i++) {
      if(vals[i] % 2 == 1) {
        ret[at] = i;
        at++;
      }
    }

    std::sort(ret, ret + n);

    for(int i = 0; i < n; i++) {
      cout << " " << ret[i];
    }

    cout << endl;
  }
}