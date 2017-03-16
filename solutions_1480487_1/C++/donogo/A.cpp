#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>
#include <stdio.h>

using namespace std;


int issafe(int i, double yi, vector <double> J)
{
  int j, N;
  double X;
  double sci;
  double resty;

  N = J.size();

  X = 0;
  for (j = 0; j < N; j++) {
    X += J[j];
  }
  sci = J[i] + X * yi;

  resty = 1.0 - yi;

  for (j = 0; j < N; j++) {
    if (i == j) {
      continue;
    }
    if (J[j] <= sci) {
      resty -= (sci - J[j]) / X;
      if (resty <= 0) {
	return 1;
      }
    }
  }
  return 0;
  
}

vector <double> saferates(vector <double> J)
{
  int i, N;
  double y, y0, y1;
  vector <double> sr;
  N = J.size();
  
  for (i = 0; i < N; i++) {
    y0 = 0;
    y1 = 1;
    while (y1 - y0 > 1e-7) {
      y = (y0 + y1)/2;
      if (issafe(i, y, J)) {
	y1 = y;
      } else {
	y0 = y;
      }
    }
    sr.push_back(y);
  }
  return sr;
  
}

int main(void)
{
  int T, c;
  double r;
  int N;
  int i;
  int m;
 

  cin >> T;

  for (c = 1; c <= T; c++)  {
    vector <double> J;
    vector <double> sr;
    cin >> N;
    for (i = 0; i < N; i++) {
      cin >> m;
      J.push_back((double) m);
    }
    sr = saferates(J);

    //    cout << "Case #" << c << ":";
    printf("Case #%d:", c);
    for (i = 0; i < N; i++) {
      printf("%10.6f", sr[i]*100.0);
    }
    cout << endl;

  }
  

  return 0;

}


