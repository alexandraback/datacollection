#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

void runcase() {
  double ret;
  int ccount;
  cin >> ccount;

  vector<int> cscore;
  cscore.resize(ccount);

  int csum = 0;
  for (int i=0;i<ccount;i++) {
    cin >> cscore[i];
    csum += cscore[i];
  }

  // total points = csum * 2

  double avg = (csum*2.)/ccount;
  //cout << " avg is " << avg << endl;

  /*double avg2 = 0;
  for (int i=0;i<ccount;i++) {
    if ( avg > cscore[i]) {
      avg2 += ((avg-cscore[i])/csum);
    }
    
  }

  cout << " avg2 is " << avg2 << endl;*/

  
  int nccount = 0;
  double newavg = 0;
  // loop contestants, remove outliers
  for (int i=0;i<ccount;i++) {
    if (cscore[i] > avg) continue;
    newavg += cscore[i];
    nccount++;
  }
  newavg += csum;
  newavg /= nccount;
    
  
  // loop contestants
  for (int i=0;i<ccount;i++) {
    if (cscore[i] > avg) { cout << " 0.0"; continue; } 

    cout << setprecision(9) << " " << (newavg-cscore[i])/csum * 100.0;


    /*int sum = 0;
    // sum others
    for (int j=0;j<ccount;j++) {
      if (i == j) continue;
      sum += cscore[j];
    }

    double best = ((sum+csum)*1.)/(ccount-1);*/




    // csum to distrib between you two for a tie
    //double avg = (cscore[i]+lowest+csum)/2;

    //cout << " " << ((avg-cscore[i])/csum)*100.0;
  }
  // other than contestant, what's highest possible lowest score
}

int main(int argv, char* argc[]) {
  int case_count;
  cin >> case_count;
  for (int i = 0; i < case_count; i++) {
    cout << "Case #" << (i+1) << ":";
    runcase();
    cout << endl;
  }
}

