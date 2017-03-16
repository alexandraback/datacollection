#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// to use:
// g++ -o template template.cpp
// ./template < in.txt

double get(int A, int B, double probs[]) {
  double strategy[A+1];
  // strategy[i] : press backspace i times, 
  // then type out rest of word and press enter.

  // probab[0] = ---
  // probab[1] = (1-p1)      // prob 1st letter wrong
  // probab[2] = p1 (1-p2)   // prob 2nd letter is the first wrong letter

  // probab[i] = p1 * p2 * ... p_{i-1} * (1-p_i)

  // probab[A-1] = p1 * p2 * ... p_{A-2} * (1-pA-1)
  // probab[A] = p1 * p2 * ... * (1-pA) // only last letter typed wrong
  // probab[A+1] = p1 * p2 * ... * pA // all letters right!

  double probab[A+2];

  for (int i = 1; i <= A+1; i++) {
    probab[i] = 1.0;
    for (int j = 1; j < i; j++) {
      probab[i] *= probs[j];
    }
    if (i <= A)
      probab[i] *= (1-probs[i]);
    //cout << endl;
    //cout << i << " " << probab[i] << endl;
  }


  for (int i = 0; i <= A; i++){
    // looping over strategies, delete i letters then type out word
    for (int j = 1; j <= A+1; j++) { 
      // looping over different scenarios (probab)
      if (i+j > A || j == A+1) {
	strategy[i] += (probab[j] * (i+i+B-A+1));
      }
      else
	strategy[i] += (probab[j] * (i+i+B-A+1+B+1));
      //cout << " ~~ ? strategy " << i << " " << strategy[i] << endl;
    }
    //cout << "strategy " << i << " " << strategy[i] << endl;
  }

  double otherstrat = 0.0; // press enter right away, retype word

  if (A < B) {
    otherstrat = 2+B;
  }
  else { // A==B
    otherstrat = probab[A+1] + (1-probab[A+1])*(2+B);
  }

  double mini = otherstrat;
  //cout << "press enter right away " << mini << endl;
  for (int i = 0; i <= A; i++) {
    //cout << "press delete " << i << " times: "<< strategy[i] << endl;

    if (strategy[i] < mini)
      mini = strategy[i];
  }

  return mini;
}

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    int A,B;
    cin >> A >> B;
    double probs[A+1];
    probs[0] = 0.0;
    for (int j = 1; j <= A; j++) {
      cin >> probs[j]; // probs[j] == p_j (numbered from 1 to A)
    }

    cout << "Case #" << (i+1) << ": ";
    cout.precision(6);
    cout.setf(ios::fixed,ios::floatfield);
    cout << get(A,B,probs) << endl;
  }
  return 0;
}
