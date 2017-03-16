#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <ctime>
#include <cmath>

using namespace std;

#define forn(I,N) for (int I=0; I<N; I++)
#define fornd(I,N) for (int I=N-1; I>=0; I--)
#define forab(I,A,B) for (int I=A; I<=B; I++)
#define forabd(I,A,B) for (int I=B; I>=A; I--)
#define FOREACH(I,A) for (__typeof__(A)::iterator I=A.begin(); I<A.end(); I++)
#define pb push_back
#define mp make_pair

typedef long long int ll;

int getIndex(string& s, int ind, char target) {
  int N = s.length() - 1;
  bool sign = true;
  char current = '1';

  int index = -1;
  forab(i, ind, N) {
    if(current == '1') {
      current = s[i];
    }
    else if(current == s[i]) {
      current = '1';
      sign = !sign;
    }
    else if(current == 'i' && s[i] == 'j') {
      current = 'k';
    }
    else if(current == 'i' && s[i] =='k') {
      current = 'j';
      sign = !sign;
    }
    else if(current == 'j' && s[i] == 'i') {
      current = 'k';
      sign = !sign;
    }
    else if(current == 'j' && s[i] == 'k') {
      current = 'i';
    }
    else if(current == 'k' && s[i] == 'i') {
      current = 'j';
    }
    else if(current == 'k' && s[i] == 'j') {
      current = 'i';
      sign = !sign;
    }

    //cout << current << endl;
    if(sign && current == target) {
      index = i + 1;
      break;
    }
  }

  return index;
}

bool isResult(string & s, int ind, char target) {
  int N = s.length() - 1;
  bool sign = true;
  char current = '1';

  int index = -1;
  forab(i, ind, N) {
    if(current == '1') {
      current = s[i];
    }
    else if(current == s[i]) {
      current = '1';
      sign = !sign;
    }
    else if(current == 'i' && s[i] == 'j') {
      current = 'k';
    }
    else if(current == 'i' && s[i] =='k') {
      current = 'j';
      sign = !sign;
    }
    else if(current == 'j' && s[i] == 'i') {
      current = 'k';
      sign = !sign;
    }
    else if(current == 'j' && s[i] == 'k') {
      current = 'i';
    }
    else if(current == 'k' && s[i] == 'i') {
      current = 'j';
    }
    else if(current == 'k' && s[i] == 'j') {
      current = 'i';
      sign = !sign;
    }
  }

  return sign && current == target;
}

int main() {
  int T;
  cin >> T;

  forn(i, T) {
    ll L, X;
    string dijkstra;
    
    cin >> L >> X >> dijkstra;

    if(X > 12) {
      X = 12 + (X % 4);
    }

    string buffer = "";
    forn(i, X) {
      buffer += dijkstra;
    }
    //cout << buffer << endl;

    bool possible = true;
    int indexJ, indexK;
    indexJ = getIndex(buffer, 0, 'i');
    //cout << "i " << indexJ << endl;
    if(indexJ == -1) {
      possible = false;
    }
    else {
      indexK = getIndex(buffer, indexJ, 'j');
      //cout << "j " << indexK << endl;
      if(indexK == -1) {
        possible = false;
      }
      else {
        possible = isResult(buffer, indexK, 'k');
        //cout << "k " << possible << endl;
      }
    }

    cout << "Case #" << i+1 << ": ";
    if(possible) {
      cout << "YES" << endl;
    }
    else {
      cout << "NO" << endl;
    }
  }

  return 0;
}
