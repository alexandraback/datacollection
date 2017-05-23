// Rank and File

#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int T;
  int N;
  int num;

  cin >> T;

  for (int i = 1; i <= T; ++i) {
    cin >> N;
    vector<int> v(2501, 0);

    for (int j = 0; j < 2 * N - 1; ++j) {
      for (int k = 0; k < N; ++k) {
        cin >> num;
        ++v[num];
      }
    }

    vector<int> result;
    int count = 0;
    const int size = v.size();
    for (int i = 0; i < size; ++i) {
      if (v[i] & 1) {
        result.push_back(i);
        ++count;
        if (count == N) {
          break;
        }
      }
    }

    cout << "Case #" << i << ":";
    for (const auto &item : result) {
      cout << " " << item;
    }
    cout << endl;
  }
  return 0;
}
