#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <cstdio>

using namespace std;
typedef long long int LL;

vector <string> singlepaste(int len, string pat) {
  int plen = pat.length();
  vector <string> V;
  int pos, room;

  room = len - plen;
  

  for (pos = 0; pos <= room; pos++) {
    string s;
    int i;
    int r;
    r = room;

    for (i = 0; i < pos; i++) {
      s += "0";
      r--;
    }
    s += pat;
    while (r) {
      s += "0";
      r--;
    }
    V.push_back(s);
  }
  return V;

}

vector <string> doublepaste(int len, string pat) {
  int plen = pat.length();
  int len1;
  vector <string> V, X, Y;
  int i, j;

  for (len1 = plen; len1 <= len - plen; len1++) {
    string s;
    int r;

    for (r = len1; r > plen; r--) {
      s += "0";
    }
    s += pat;
    Y = singlepaste(len - len1, pat);
    for (j = 0; j < Y.size(); j++) {
      V.push_back(s + Y[j]);
    }
  }
  return V;
}


int main(void) {
  int T, t;
  vector <string> V, V32, V16, V16_1;
  int i, x, N, J;
  string pat;
  vector <int> divs;

  V16 = doublepaste(12, "11");
  V16_1 = singlepaste(12, "11");

  cin >> T;
  cin >> N;
  cin >> J;
  for (t = 1; t <= T; t++) {
    cout << "Case #" << t << ": " << endl;
    if (N == 16) {
      V = V16;
      V.insert(V.end(), V16_1.begin(), V16_1.end());
      pat = "11";
      for (x = 2; x <= 10; x++) {
	divs.push_back(x+1);
      }
      for (i = 0; i < J; i++) {
	cout << pat + V[i] + pat;
	for (x = 2; x <= 10; x++) {
	  cout << " " << divs[x-2];
	}
	cout << endl;
      }
    } else if (N == 32) {
      pat = "1001";
      V = doublepaste(24, pat);
      for (x = 2; x <= 10; x++) {
	divs.push_back(x*x*x+1);
      }
      i = 0;
      while (J && i < V.size()) {
	cout << pat + V[i++] + pat;
	for (x = 2; x <= 10; x++) {
	  cout << " " << divs[x-2];
	}
	cout << endl;
	J--;
      }

      pat = "1011";
      V = doublepaste(24, pat);
      for (x = 2; x <= 10; x++) {
	divs[x-2] = (x*x*x+ x+ 1);
      }
      i = 0;
      while (J && i < V.size()) {
	cout << pat + V[i++] + pat;
	for (x = 2; x <= 10; x++) {
	  cout << " " << divs[x-2];
	}
	cout << endl;
	J--;
      }

      pat = "1101";
      V = doublepaste(24, pat);
      for (x = 2; x <= 10; x++) {
	divs[x-2]=(x*x*x+ x*x + 1);
      }
      i = 0;
      while (J && i < V.size() ) {
	cout << pat + V[i++] + pat;
	for (x = 2; x <= 10; x++) {
	  cout << " " << divs[x-2];
	}
	cout << endl;
	J--;
      }

      pat = "1111";
      V = doublepaste(24, pat);
      for (x = 2; x <= 10; x++) {
	divs[x-2]=(x*x*x+ x*x + x + 1);
      }
      i = 0;
      while (J && i < V.size() ) {
	cout << pat + V[i++] + pat;
	for (x = 2; x <= 10; x++) {
	  cout << " " << divs[x-2];
	}
	cout << endl;
	J--;
      }
    }
    
  }      


  return 0;
}
