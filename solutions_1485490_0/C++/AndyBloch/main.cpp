//
//  main.cpp
//  c
//
//  Created by Andrew Bloch on 5/6/12.
//  Copyright (c) 2012 Andrew Bloch. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std ;
int verbose = 0 ;

unsigned long runTest(){
  int numBoxes , numToys ;
  cin >> numBoxes >> numToys ;
  unsigned long int boxes[numBoxes];
  unsigned long int toys[numToys];
  unsigned long int boxTypes[numBoxes];
  unsigned long int toyTypes[numToys];
  int i,j ;
  for (i = 0 ; i < numBoxes ; i++) {
    cin >> boxes[i] >> boxTypes[i];
    if (verbose)
      cout << " " << boxes[i] << " " << boxTypes[i] ; 
  }
  if (verbose)
    cout << endl;
  for (i = 0 ; i < numToys ; i++) {
    cin >> toys[i] >> toyTypes[i];
    if (verbose)
      cout << " " << toys[i] << " " << toyTypes[i] ;
  }
  if (verbose)
    cout << endl;
  unsigned long best = 0 ;
  j = 0 ;
  
  for (i = 0 ; i <= numToys ; i++) {
    if (i == numToys) {
      unsigned long int count = 0 ;
      for (i = 0 ; i < numToys ; i++) {
        if (boxTypes[0] == toyTypes[i])
          count+= toys[i];
      }
      if (count > best) best = count ;
      break ;
    }
    if ((toyTypes[i]!= boxTypes[1]) && (toyTypes[i] != boxTypes[2]))
      continue ;
    for (j = i ; j <=numToys ; j++) {
      if ((j < numToys) && (toyTypes[j] != boxTypes[2]))
        continue ;
      unsigned long int counts[3] = {0,0,0};
      int k;
      for (k = 0 ; k < i ; k++)
        if (boxTypes[0] == toyTypes[k])
          counts[0]+= toys[k];
      if (numBoxes > 1)
      for (; k < j ; k++)
        if (boxTypes[1] == toyTypes[k])
          counts[1]+= toys[k];
      if ((numBoxes > 2) && (j < numToys))
      for (; k < numToys ; k++)
        if (boxTypes[2] == toyTypes[k])
          counts[2]+= toys[k];
      unsigned long int total = 0 ;
      for (k = 0 ; k < numBoxes ; k++)
        total += boxes[k] > counts[k] ? counts[k] : boxes[k];
      if (verbose) {
        cout << "Split at " << i << " & " << j << ": " << total << endl ;
      }
      if (total > best)
        best = total ;
      if (verbose) {
        cout << "Best " << best << endl ;
      }
    }
  }
  if ((numBoxes ==3) && (boxTypes[0] == boxTypes[2])) {
    unsigned long int count = 0 ;
    for (i = 0 ; i < numToys ; i++) {
      if (boxTypes[0] == toyTypes[i])
        count+= toys[i];
    }
    unsigned long int total = boxes[0]+boxes[2];
    if (total > count)
      total = count ;
    if (total>best)
      best = total ;
    if (verbose) {
      cout << "First and last same.  Total boxes = " << total << endl ;
    }
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
    unsigned long int result = runTest();
    cout << "Case #" << i + 1 << ": " ;
    cout << result << endl;
  }
  if (verbose) {
    cout << "VERBOSE! TURN OFF BEFORE SUBMITTING." << endl ;
  }
  
  
  return 0 ;
}

