#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <cmath>
#include <set>

#define REP(i,n) FOR(i,0,n)
#define FOR(i,s,n) for (int i = (int)(s); i < (int)(n); ++i)
#define ALL(c) (c).begin(), (c).end()

using namespace std;

int solve(int A, int B)
{
  int digit = (int)log10(A);
  int pow10 = (int)pow((double)10, digit);
  set<pair<int, int> > bag;
  for (int num = A; num <= B; ++num) {
    int num2 = num;
    for (int i = 0; i < digit; ++i) {
      num2 = (num2 % 10) * pow10 + (num2 / 10);
      if (num < num2 && A <= num2 && num2 <= B) {
	bag.insert(make_pair(num, num2));
      }
    }
  }
  return bag.size();
}

int main()
{
  int T;
  cin >> T;
  for (int cs = 1; cs <= T; ++cs) {
    int A, B;
    cin >> A >> B;
    cout << "Case #" << cs << ": " << solve(A, B) << endl;
  }
  
  return 0;
}
