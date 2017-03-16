#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void get(int N, int a[], int b[]) {
  //for (int i = 0; i < N; i++) 
  //  cout << a[i] << " " << b[i] << endl;

  bool playedA[N]; // already got 1st star from this level
  bool playedB[N]; // already got 2nd star from this level

  for (int i = 0; i < N; i++) {
    playedA[i] = 0;
    playedB[i] = 0;
  }

  int totStars = 0;
  int gamesPlayed = 0;
  bool progressMade = 1;

  while (totStars < 2*N && progressMade) {
    progressMade = 0;
    for (int i = 0; i < N; i++) {
      // haven't played for 2nd star yet, and have enuff stars required
      if (playedB[i] == 0 && totStars >= b[i]) {
	//play it! 2 star rating
	gamesPlayed += 1;
	if (playedA[i]) totStars += 1;
	else totStars += 2;
	playedB[i] = 1;
	progressMade = 1;
	break;
      }
    }

    if (progressMade == 1) continue;
    else {
      int besti = -1; // this is i where b[i] is max!, and we haven't played either A or B YET!
      
      for (int i = 0; i < N; i++) {
	// haven't played game at all (neither 1st or 2nd star), 
	// and have enuff reqs stars
	if (playedA[i] == 0 && playedB[i] == 0 && totStars >= a[i]) {
	  //cout << "HI ";
	  //cout << i << endl;
	  // check if best. find besti
	  if (besti == -1 || b[i] > b[besti]) {
	    besti = i;
	  }
	}
      }
      //cout << besti << endl;
      
      if (besti > -1) {
	//play it! 1 star rating
	gamesPlayed += 1;
	totStars += 1;
	playedA[besti] = 1;
	progressMade = 1;
      }

    }

  }

  if (totStars == 2*N) {
    cout << gamesPlayed;
    return;
  }
  cout << "Too Bad";
}

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    int N;
    cin >> N;
    int a[N];
    int b[N];

    for (int j = 0; j< N; j++) {
      cin >> a[j] >> b[j];
    }

    cout << "Case #" << (i+1) << ": ";
    get(N,a,b);
    cout << endl;
  }
  return 0;
}
