#include <string>
#include <vector>
#include <iostream>


using namespace std;

int count( int N, int S, int p, vector <int> t)
{
  int basicok;
  int maybesup;
  int i;
  int besti;
  int r;

  basicok = 0;
  maybesup = 0;

  for (i = 0; i < N; i++) {
    r = t[i] % 3;

    switch(r) {
    case 0:
      besti = t[i] / 3;
      break;
    case 1:
      besti = (t[i]+2) / 3;
      break;
    case 2:
      besti = (t[i]+1) / 3;
      break;
    }
    if (besti >= p) {
      basicok++;
    }

    if (t[i] >= 2 && besti == p - 1 &&
	r != 1) {
      maybesup++;
    }

  }

  if (S > maybesup) {
    return basicok + maybesup;
  } else {
    return basicok + S;
  }

}






int main(void)
{

  int T;
  int c;
  int x;
  string src, res;
  int numpl;

  cin >> T;

  for (c = 1; c <= T; c++) {
    int N;
    int S, p;
    vector <int> t;
    int i;

    cin >> N;
    cin >> S;
    cin >> p;

    for (i = 0; i < N; i++) {
      cin >> x;
      t.push_back(x);
    }
    numpl = count(N, S, p, t);

    cout << "Case #" << c << ": " << numpl << endl;

  }

  
  return 0;

}
