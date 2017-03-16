//
//  main.cpp
//  b 
//
//  Created by Andrew Bloch on 4/27/12.
//  Copyright (c) 2012 Andrew Bloch. All rights reserved.
//
int verbose = 0 ;

#include <iostream>
using namespace std ;

typedef int int2[2];

int numPlays(int numLevels, int2 *starsNeeded, int *levelDoneIn, int stars, int numCompleted, int *numCompletedOut) {
  int i ;
  int lastStars = stars ;
  int plays = 0 ;
  int levelDone[numLevels];
  for (i = 0 ; i < numLevels ; i++) {
    levelDone[i] = levelDoneIn[i];
  }
  
  do {
    lastStars = stars ;
    for (i = 0 ; i < numLevels ; i++) {
      // complete all the gimmes -- those where you have enough stars to complete level with a 2-star rating
      if (levelDone[i]<2) {
        if (verbose) {
          cout << stars << " stars, " << starsNeeded[i][1] << " needed" << endl; 
        }

        if (stars >= starsNeeded[i][1]) {
          stars += 2 - levelDone[i] ;
          numCompleted ++ ;
          levelDone[i] = 2 ;
          plays++ ;
        }
      }
    }
  } while (lastStars != stars);
  if (verbose) {
    //cout << "After gimmes: " << stars << " stars, " << numCompleted << " completed, " << plays << " plays" << endl; 
  }
  if (numCompleted == numLevels) {
    *numCompletedOut = numCompleted ;
    return plays ;
  }
  int bestPlays = 10000 ;
  int bestLevel = -1 ;
  int bestCompleted = 0 ;
  int numCompletedIn=0 ;
  for (i = 0 ; i < numLevels ; i++) {
    if (verbose)
      cout << "Trying level " << i << endl ;
    if (!levelDone[i]) {
      if (starsNeeded[i][0] <= stars) {
        levelDone[i] = 1 ;
        int n = numPlays(numLevels, starsNeeded, levelDone, stars+1, numCompleted,&numCompletedIn);
        if (n && (n < bestPlays)) {
          bestPlays = n ;
          bestLevel = i ;
          bestCompleted = numCompletedIn ;
        }
        levelDone[i] = 0 ;
      }
    }
  }
  if (bestLevel < 0)
    return 0 ;
  if (numCompletedIn == numLevels) {
    if (verbose)
      cout << "Played level " << bestLevel << " at 1 star " << endl ;
    *numCompletedOut=bestCompleted ;
    return bestPlays + plays + 1;
  }
  return -1 ;
}

int runTest() {
  int numLevels ;
  cin >> numLevels ;
  int2 starsNeeded[numLevels] ;
  int levelDone[numLevels] ;
  int i ;
  for (i = 0 ; i < numLevels ; i++) {
    cin >> starsNeeded[i][0] >> starsNeeded[i][1];
    levelDone[i] = 0 ;
    if (verbose>1)
      cout << i << " " << starsNeeded[i][0] << " " << starsNeeded[i][1] << endl;
  }
  int numCompleted = 0 ;
  return numPlays(numLevels,starsNeeded,levelDone,0,0,&numCompleted);
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
      cout << result << endl;
    else {
      cout << "Too Bad" << endl ;
    }
  }
  if (verbose) {
    cout << "VERBOSE! TURN OFF BEFORE SUBMITTING." << endl ;
  }
  return 0;
}

