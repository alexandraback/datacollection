#include <iostream>
#include <string>

using namespace std;

long long gcd(long long i, long long j) {
  if (i <= j)
	return gcd(j, i);

  return (i % j == 0) ? j : gcd(j, i % j);
}

bool test(long long i) {
  while (i % 2 == 0) {
	i /= 2;
  }

  return i == 1;
}

int main()
{
  int nCases;
  cin >> nCases;
  for (int iCase = 1; iCase <= nCases; ++iCase) {
	long long P, Q;
	char c;
	cin >> P >> c >> Q;
	// cout << "has " << p << "/" << q << endl;

	long long g = gcd(P, Q);
	long long p = P / g;
	long long q = Q / g;

	if (test(q)) {
	  int cnt = 0;
	  for (long long b = p; b < q; b *= 2) {
		cnt++;
	  }
	  cout << "Case #" << iCase << ": " << cnt << endl;
	} else {
	  cout << "Case #" << iCase << ": impossible" << endl;
	}
  }
}

