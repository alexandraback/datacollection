#include <iostream>
#include <vector>

using namespace std;

int main() {
  int T; cin >> T;
  for (int test_cases = 1; test_cases <= T; test_cases++) {
    int N; cin >> N;
    vector<int> heights(2501, 0);
    for (int i = 1; i < 2 * N; i++) {
      for (int j = 0; j < N; j++) {
	int num; cin >> num;
	heights[num]++;
      }      
    }
    printf("Case #%d:", test_cases);
    for (int i = 1; i <= 2500; i++) {
      if (heights[i] % 2 == 1) {
	printf(" %d", i);
      }
    }
    printf("\n");
  }
  return 0;
}
