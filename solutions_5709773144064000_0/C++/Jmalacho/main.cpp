#include <fstream>
#include <iostream>
using std::endl;
#include <stdlib.h>
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <map>
using std::map;
std::ofstream gLogger("./log");

/*void SortedInsertInt( vector<int> &v, const int &i) {
  for (vector<int>::iterator itr=v.begin(); itr!=v.end(); ++itr){
    if (i < *itr) {
      v.insert(itr,i);
      return;
    }
  }  
  v.push_back(i);
}
*/

class Cookie {
public:
  Cookie( const char * filename ) : mInFile(filename)  {
    gLogger << "Cookie contructed with: " << filename << endl;
  }
  void Load() {
    mInFile >> mNumTestCases;
    gLogger << "Number of testcases: " << mNumTestCases << endl;

    float tmpC;
    for (int testCaseIdx=0; testCaseIdx < mNumTestCases; ++testCaseIdx) {
       gLogger << " Loading testcase: " << testCaseIdx+1 << endl;
       mInFile >> mFarmCost;
       mInFile >> mFarmProduction;
       mInFile >> mGoal;
       
       std::cout << "Case #" << testCaseIdx +1 << ": ";
       this->SolveCurrentProblem();
       std::cout << endl;
    }
  }
  void SolveCurrentProblem() {
    std::cout.precision(20);
    mBaseProduction=2;
    double curProduction=mBaseProduction;
    double curTime=0;
    //double curCookies=0;
    while(1) {
      double estimatedFinishC1 = mGoal / curProduction;
      double timeTillNextBuy = mFarmCost / curProduction;
      double estimatedFinishC2=timeTillNextBuy + (mGoal / (curProduction + mFarmProduction));
      gLogger << "   estimatedFinish(no buy): " << estimatedFinishC1 << endl;
      gLogger << "   estimatedFinish(buy)   :  "<< estimatedFinishC2 << endl;
      gLogger << "   NextBuy: " << timeTillNextBuy << endl;
      if ( estimatedFinishC1 < estimatedFinishC2 ) { //don't buy
	std::cout << curTime + estimatedFinishC1;
	return;
      } else { //Buy
	curTime+=timeTillNextBuy;
	curProduction+=mFarmProduction;
      }
    }
  }
private:
  Cookie();
  std::ifstream mInFile;
  int mNumTestCases;
  
  double mFarmCost;
  double mFarmProduction;
  double mGoal;
  double mBaseProduction;
};

void cleanup() {
  gLogger.close();
}

int main(int argc, char ** argv) {
  if (argc < 2) {
    std::cerr << "No file given\n";
    return 1;
  } else {
    atexit(&cleanup);
    Cookie problem(argv[1]);
    problem.Load();
  }
  return 0;
}