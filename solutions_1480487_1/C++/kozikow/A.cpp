#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#define EPS 1e-9
using namespace std;

bool ok(double score, double perc, double sum, const vector<int>& points) {
  double sum_glo = 0;
  for(int i=0; i<points.size(); i++) {
    double roznica = (score-(double)points[i]);
    if(roznica > 0)
      sum_glo += roznica / sum;
  }
  //cerr << "Suma to " << sum_glo << endl;
  return (sum_glo-EPS) > (1.0);
}

double binary_search(double dol, double gora, double punkt, const vector<int>& points, double sum) {
  //cerr << dol << ' ' << gora << ' ' << (gora+dol)/2.0 << endl;
  if(fabs(gora-dol) < EPS)
    return (gora+dol)/2.0;
  
  double sro = (dol+gora) / 2.0;
  if(ok(punkt + sum * sro, sro, sum, points))
    return binary_search(dol,sro,punkt,points,sum);
  else
    return binary_search(sro,gora,punkt,points,sum);
  
}


int main() {
  int t;
  cin >> t;
  for(int z=1; z<=t; z++) {
    cout << "Case #" << z << ": ";
    int n;
    cin >> n;
    vector<int> points;
    int sum = 0;
    while(n--) {
      int x;
      cin >> x;
      sum += x;
      points.push_back(x);
    }
    double global_sum = 0;
    for(int i=0; i<points.size(); i++) {
      double wynik = binary_search(0.0,1.0,points[i],points,sum);
      global_sum += wynik;
      printf("%.6lf ", wynik*100.0);
    }
    cout << '\n';
  }
  return 0;
}