//
//  main.cpp
//  a
//
//  Created by Andrew Bloch on 4/27/12.
//  Copyright (c) 2012 Andrew Bloch. All rights reserved.
//
int verbose = 0 ;

#include <iostream>
using namespace std ;

double runTest() {
  int ctyped ;
  int passwordLength ;
  cin >> ctyped >> passwordLength ;
  int i ;
  double prob[ctyped];
  for (i = 0 ; i < ctyped ; i++) {
    cin >> prob[i];
  }
  if (verbose) {
    for (i = 0 ; i < ctyped ; i++) {
      cout << " " << prob[i];
    }
    cout << endl ;
  }
  double best = passwordLength+2 ;
  double pright = 1 ;
  for (i = 0 ; i < ctyped ; i++ ) {
    pright *= prob[i];
    int keysToFinish = (passwordLength-i-1)+ctyped-i-1+1 ;
    double expKeystrokes = pright*keysToFinish;
    int keysIfWrong = keysToFinish + passwordLength+1 ;
    expKeystrokes += (1.0-pright)*keysIfWrong;
    if (verbose)
      cout << "P " << pright << " keys right " << keysToFinish << " keys wrong " << keysIfWrong << " exp " << expKeystrokes << endl ; 
    if (expKeystrokes < best)
      best = expKeystrokes ;
  }
  
  return best ;
}

int main(int argc, const char * argv[])
{
  if (argc>1) {
    verbose = atoi(argv[1]);
    if (verbose) {
      cout << "Verbosity: " << verbose << endl ;
    }
  }
  int testCases ;
  cin >> testCases ;

  if (verbose) {
    cout << "Test cases: " << testCases<< endl ;
  }
  int i;
  for (i = 0 ; i < testCases ; i++) {
    double result = runTest();
    cout << "Case #" << i + 1 << ": " ;
    printf("%f",result );
    cout << endl;
  }
  if (verbose) {
    cout << "VERBOSE! TURN OFF BEFORE SUBMITTING." << endl ;
  }
  return 0;
}

