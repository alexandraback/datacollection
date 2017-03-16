//
//  main.cpp
//  a
//
//  Created by Andrew Bloch on 5/6/12.
//  Copyright (c) 2012 Andrew Bloch. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std ;
int verbose = 0 ;

int iterate(int *table, int *visited, int numClasses, int c) {
  if (verbose)
    cout << "Checking classes inheriting from " << c << endl ;
  if (visited[c])
    return 1 ;
  visited[c] = 1 ;
  int i;
  for (i = 1 ; i <= numClasses ; i++) {
    if (table[i*(numClasses+1)+c]) {
      if (iterate(table, visited, numClasses, i))
        return 1 ;
    }
  }
  if (verbose)
    cout << "Done checking classes inheriting from " << c << endl ;  
  return 0 ;
}
int runTest(){
  int numClasses ;
  cin >> numClasses ;
  int inheritTable[numClasses+1][numClasses+1];
  int i ;
  int j ;
  for (i = 1 ; i <= numClasses ; i++)
    for (j = 1 ; j <= numClasses ; j++)
      inheritTable[i][j]=0;
  
  for (i = 1 ; i <= numClasses ; i++) {
    int numInherit ;
    cin >> numInherit ;
    inheritTable[i][0] = numInherit ;
    for (j = 0 ; j < numInherit ; j++) {
      int c ;
      cin >> c ;
      inheritTable[i][c] = 1 ;
    }
  }
  if (verbose) {
    for (i = 1 ; i <= numClasses ; i++) {
      cout << i << ":" ;
      for (j = 1 ; j <= numClasses ; j++)
        cout << " " << inheritTable[i][j] ;
      cout << endl ;
    }
  }
  for (i = 1 ; i <= numClasses ; i++) {
    if (inheritTable[i][0] == 0) {
      int visited[numClasses+1];
      for (j = 1 ; j <= numClasses ; j++)
        visited[j] = 0 ;
      if (iterate((int *)inheritTable, visited, numClasses, i))
        return 1 ;
    }
  }
  return 0 ;
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
    int result = runTest();
    cout << "Case #" << i + 1 << ": " ;
    if (result)
      cout << "Yes" << endl;
    else
      cout << "No" << endl ;
  }
  if (verbose) {
    cout << "VERBOSE! TURN OFF BEFORE SUBMITTING." << endl ;
  }
  

  return 0 ;
}

