#include <cmath>
#include <cstdio>
#include <algorithm>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <utility>
#include <vector>
#include <iostream>
#include <iomanip>
#include <stdint.h>

using namespace std;


string doCase(istream & in)
{
  uint64_t A, B;
  in >> A >> B;
  vector<double> probs;
  double initprob = 1.0;
  for(int i = 0; i < A; i++)
  {
    double d;
    in >> d;
    initprob*= d;
    probs.push_back(initprob);
  }

  uint64_t expectedCancelRightAway=B+1+1;

  double bestExpected = expectedCancelRightAway;

  
  // function for backspace = B-A+1 + 2*bs
  uint64_t backspaceCount = 0;
  uint64_t currentCost    = B-A+1;
  double probAllCorrectSoFar = initprob;
  do{
    uint64_t currentFailedCost = currentCost + B+1;
    double invprobAllCorrectSoFar = 1-probAllCorrectSoFar;
    double thisExpectVal = probAllCorrectSoFar*currentCost +
                           invprobAllCorrectSoFar*currentFailedCost;

    //cout << "DEBUG" << thisExpectVal << endl;
    //cout << "DEBUG-probC" << probAllCorrectSoFar << endl;
    //cout << "DEBUG-cost" << currentCost << endl;
    //cout << "DEBUG-probNC" << invprobAllCorrectSoFar << endl;
    //cout << "DEBUG-coster" << currentFailedCost << endl;
    if(thisExpectVal < bestExpected)
      bestExpected = thisExpectVal;

    backspaceCount++;
    if(backspaceCount == A)
      break;
    currentCost+=2;
    if(currentCost > expectedCancelRightAway)
      break;
    probAllCorrectSoFar = probs[A-backspaceCount-1]; // 0.0 prob resilliant
  }while(true);

  ostringstream oss;
  oss << fixed << setprecision(6) <<  bestExpected;
  return oss.str();
}

int main() {
  uint64_t T;
  cin >> T;
  for (int Ti = 1; Ti <= T; ++Ti) {
    cout << "Case #" << Ti << ": " << doCase(cin) << endl;
  }
  return 0;
}
