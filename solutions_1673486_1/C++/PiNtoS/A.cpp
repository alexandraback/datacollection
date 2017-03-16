#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long double Double;

void update(Double& best, Double p, int succCount, int failCount) {
  Double exp = p * succCount + (1 - p) * failCount;
  if(best == -1 || exp < best)
	best = exp;
}

int main()
{
  int T;
  cin >> T;
  for(int C=1;C<=T;C++) {
	int A, B;
	cin >> A >> B;
	vector<Double> p;
	for(int i=0;i<A;i++) {
	  Double x;
	  cin >> x;
	  p.push_back(x);
	}

	vector<Double> pTotal;
	pTotal.push_back(1);
	for(int i=0;i<p.size();i++) {
	  const Double lastP = pTotal[i];
	  pTotal.push_back(lastP * p[i]);
	}

	Double best = -1;

	for(int i=0;i<A;i++) {
	  // press backspace A-i times
	  int succCount = (A - i) + (B - i) + 1;
	  int failCount = succCount + B + 1;
	  Double p = pTotal[i];
	  update(best, p, succCount, failCount);
	}

	// press enter, try again
	{
	  int succCount = 1;
	  int failCount = succCount + B + 1;
	  Double p = (A == B ? pTotal[A] : 0);
	  update(best, p, succCount, failCount);
	}

	// keep typing
	{
	  int succCount = (B - A) + 1;
	  int failCount = succCount + B + 1;
	  Double p = pTotal[A];
	  update(best, p, succCount, failCount);
	}

	printf("Case #%d: %.6Lf\n", C, best);
  }
  return 0;
}
