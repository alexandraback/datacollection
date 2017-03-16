#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <map>
#define loop(a,b,c) for (int a = b; a < c; a++) 

using namespace std;

int nextatk = 0, atks = 1, wi = 2, ei = 3, str = 4, delta_di = 5, mv = 6, delta_si = 7;

int main() {
  int cases; cin >> cases;
  loop (cs,0,cases) {
    cerr << cs << "\n";
    int N;
    cin >> N;
    int tribes[N][8];
    loop (i,0,N) {
      loop (j,0,8) cin >> tribes[i][j];
    }
    int counters[N];
    map<int,int> wall;
    int vic = 0;
    int day = 0;
    while(1) {
      bool keepgoing = false;
      loop (i,0,N) {
        if (tribes[i][atks] > 0) keepgoing = true;
        if (tribes[i][nextatk] == 0 && tribes[i][atks] > 0) {
          bool wewin = false;
          loop (j,tribes[i][wi],tribes[i][ei]) {
            if (wall[j] < tribes[i][str]) { wewin = true; }
          }
          if (wewin) vic++;
        }
      }
      loop (i,0,N) {
        if (tribes[i][nextatk] == 0 && tribes[i][atks] > 0) {
          loop (j,tribes[i][wi],tribes[i][ei]) {
            if (wall[j] < tribes[i][str]) { wall[j] = tribes[i][str]; }
          }
          //cout << i << " " << tribes[i][wi] << " " << tribes[i][ei] << ": " << tribes[i][str] << " " << day << " "<< wewin << "\n";
          tribes[i][nextatk] = tribes[i][delta_di]-1;
          tribes[i][atks]--;
          tribes[i][str] += tribes[i][delta_si];
          tribes[i][wi] += tribes[i][mv];
          tribes[i][ei] += tribes[i][mv];
        }
        else tribes[i][nextatk]--;
      }
      if (!keepgoing) break;
      day++;
    }
    cout << "Case #" << (cs+1) << ": " << vic << "\n";
  }
}
