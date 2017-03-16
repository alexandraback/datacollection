#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

ifstream in("data.in");
ofstream out("data.out");

string scores[2];

string bestscores[2];
int scorevalues[2];
int mindiff;

void solve(int team, int pos) {
  if (team == 2) {
    for (int i=0; i<2; i++) {
      scorevalues[i]=0;
      for (int j=0; j<scores[i].size(); j++) {
	scorevalues[i] *= 10;
	scorevalues[i] += int(scores[i][j]-'0');
      }
    }
    int curdiff = abs(scorevalues[0] - scorevalues[1]);
    if (curdiff < mindiff) {
      mindiff = curdiff;
      bestscores[0] = scores[0];
      bestscores[1] = scores[1];
    }
    return;
  }
  if (pos >= scores[team].size()) {
    solve(team+1,0);
    return;
  }
  if (scores[team][pos] != '?') {
    solve(team, pos+1);
    return;
  }

  for (int i=0; i<=9; i++) {
    scores[team][pos] = char('0' + i);
    solve(team, pos+1);
  }

  scores[team][pos] = '?';
}

int main() {
  int t;
  in >> t;
  for (int caseNum = 1; caseNum <= t; caseNum++) {
    in >> scores[0] >> scores[1];

    mindiff = 1000000;
    solve(0,0);

    out << "Case #" << caseNum << ": " << bestscores[0] << " " << bestscores[1] << endl;
  }
}
