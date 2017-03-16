#include <fstream>
#include <iostream>
using std::endl;
#include <stdlib.h>
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <deque>
using std::deque;
#include <map>
using std::map;

#include <algorithm>
#include <boost/foreach.hpp>
std::ofstream gLogger("./log");

void SortedInsertFloat( deque<float> &v, const float &i) {
  for (deque<float>::iterator itr=v.begin(); itr!=v.end(); ++itr){
    if (i < *itr) {
      v.insert(itr,i);
      return;
    }
  }  
  v.push_back(i);
}


class Deceitfulwar {
public:
  Deceitfulwar( const char * filename ) : mInFile(filename)  {
    gLogger << "Deceitfulwar contructed with: " << filename << endl;
  }
  void Load() {
    mInFile >> mNumTestCases;
    gLogger << "Number of testcases: " << mNumTestCases << endl;

    float tmpItem;
    for (int testCaseIdx=0; testCaseIdx < mNumTestCases; ++testCaseIdx) {
       gLogger << " Loading testcase: " << testCaseIdx+1 << endl;
       mNaomiWeights.clear();
       mKenWeights.clear();
       mInFile >> mNumWeights;
       
       float tmpItem;
       for (int weight_idx=0; weight_idx < mNumWeights; ++weight_idx) {
         mInFile >>tmpItem;
         SortedInsertFloat(mNaomiWeights, tmpItem);
         
       }
       for (int weight_idx=0; weight_idx < mNumWeights; ++weight_idx) {
         mInFile >>tmpItem;
         SortedInsertFloat(mKenWeights, tmpItem);
       }
       
        gLogger << "   ";
        BOOST_FOREACH( float f, mNaomiWeights) {
          gLogger << f << " ";
        }
        gLogger << endl;
        
        gLogger << "   ";
        BOOST_FOREACH( float f, mKenWeights) {
          gLogger << f << " ";
        }
        gLogger << endl;
    
       
       std::cout << "Case #" << testCaseIdx +1 << ": ";
       this->SolveCurrentProblem();
       std::cout << endl;
    }
 }
  
  bool isGreaterThanNaomi(float f) {
    return (f>mNaomiChoice);
  }
  
  void SolveCurrentProblem() {
    deque<float> naomi_weights_war=mNaomiWeights;
    deque<float> ken_weights_war=mKenWeights;
    int naomiScore=0;
    // normal
    while(!naomi_weights_war.empty()) {
      mNaomiChoice = naomi_weights_war.front();
      naomi_weights_war.erase(naomi_weights_war.begin());
      //gLogger << "   Naomi chooses: " << mNaomiChoice << endl;
      
      std::deque<float>::iterator kens_choice_itr;
      for (kens_choice_itr = ken_weights_war.begin();
           kens_choice_itr != ken_weights_war.end();
           ++kens_choice_itr) {
        if (isGreaterThanNaomi(*kens_choice_itr)) {
          break;
        }
      }
      if (kens_choice_itr==ken_weights_war.end()) {
        kens_choice_itr=ken_weights_war.begin();
        naomiScore++;
      }
      ken_weights_war.erase(kens_choice_itr);
    }
    
    //Deceitfulwar
    int naomiScoreDeceitfull=0;
    while(!mNaomiWeights.empty()) {
      //naomi first choice
      mNaomiChoice = mNaomiWeights.back(); 
      gLogger << "   Naomi chooses: " << mNaomiChoice << endl;
      
      //ken first choice
      std::deque<float>::iterator kens_choice_itr;
      for (kens_choice_itr = mKenWeights.begin();
           kens_choice_itr != mKenWeights.end();
           ++kens_choice_itr) {
        if (isGreaterThanNaomi(*kens_choice_itr)) {
          break;
        }
      }
      if (kens_choice_itr==mKenWeights.end()) {
        kens_choice_itr=mKenWeights.begin();
      }
      gLogger << "   Ken chooses: " << *kens_choice_itr << endl;
      
      //naomi chooses for real
      if ( *kens_choice_itr > mNaomiChoice) {  //Naomi Loses
        gLogger << "    Naomi really chooses: " << *(mNaomiWeights.begin()) << endl;
        mNaomiWeights.erase(mNaomiWeights.begin()); //chooses lowest
      } else {
        std::deque<float>::iterator naomi_choice_itr;
        for (naomi_choice_itr =  mNaomiWeights.begin();
             naomi_choice_itr != mNaomiWeights.end();
             ++naomi_choice_itr) {
          if (*naomi_choice_itr > *kens_choice_itr ) {
            naomiScoreDeceitfull++;
            break;
          }
        }
        gLogger << "    Naomi really chooses: " << *naomi_choice_itr << endl;
        mNaomiWeights.erase(naomi_choice_itr);
      }
      
      mKenWeights.erase(kens_choice_itr);
    }
    
    
    std::cout << naomiScoreDeceitfull << " " << naomiScore;
  }
private:
  Deceitfulwar();
  std::ifstream mInFile;
  int mNumTestCases;
  
  int mNumWeights;
  deque<float> mNaomiWeights;
  deque<float> mKenWeights;
  float mNaomiChoice;
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
    Deceitfulwar problem(argv[1]);
    problem.Load();
  }
  return 0;
}