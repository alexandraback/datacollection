#include <iostream>
#include <fstream>

#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;


int main() {
  //ifstream input("A-small.in", ifstream::in);
  ifstream input("A-large.in", ifstream::in);
  ofstream output("problem-a.out", ofstream::out);

  int caseCount;
  input >> caseCount;
  
  for (int caseId = 1; caseId <= caseCount; ++caseId) {

    int n;
    input >> n;

    vector<int> scores;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      int tmp;
      input >> tmp;
      scores.push_back(tmp);
      sum += tmp;
    }

    output << "Case #" << caseId << ":";
    
    //sort(begin(scores), end(scores));

    auto max = [](float a, float b) {return a > b ? a : b;};

    for (auto it = begin(scores); it != end(scores); ++it) {
      float minneeded = 0;

      vector<float> bi;
      for (auto bit = begin(scores); bit != end(scores); ++bit) {
        if (bit != it) {
          bi.push_back((float(*bit)-float(*it))/float(sum));
        }
      }

      float a = 0;
      float b = 1;
      do {
        minneeded = (a+b)/2.0f;
        float votesleft = 1 - minneeded;
        for (float val : bi) {
          float neededToEqual = max(0, minneeded - val);
          votesleft -= neededToEqual;
        }

        if (votesleft > 0) {
          a = minneeded;
        } else {
          b = minneeded;
        }
      } while (abs(b-a) > 10e-8);

      output << " " << minneeded*100.0f;    
    }

    output << endl;
  }

  return 0;
}