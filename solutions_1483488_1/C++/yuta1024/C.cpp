#include <iostream>
#include <set>
using namespace std;

const long long int cof[] = {1LL, 10LL, 100LL, 1000LL, 10000LL, 100000LL, 1000000LL};

int main()
{
  int T;
  cin >> T;
  for (int testcase = 1; testcase <= T; ++testcase) {
    long long int A, B, ans = 0;
    cin >> A >> B;

    int digit = 0;
    long long int tmp = A;
    while (tmp > 0LL) {
      ++digit;
      tmp /= 10LL;
    }

    for (long long int i = A; i < B; ++i) {
      set<long long int> d;
      for (int j = 1; j < digit; ++j) {
	long long int back = i % cof[j];
	long long int front = i / cof[j];
	tmp = back*cof[digit-j] + front;
	if (i < tmp && tmp <= B)
	  d.insert(tmp);
      }
      ans += d.size();
    }

    cout << "Case #" << testcase << ": " << ans << endl;
  }
  return 0;
}
