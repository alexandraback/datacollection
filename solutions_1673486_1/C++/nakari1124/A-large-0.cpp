#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long i64;

#define FOREACH(type, collection, arg) for(vector<type>::iterator arg = collection.begin(); arg != collection.end(); arg++)
#define FOREACH_R(type, collection, arg) for(vector<type>::iterator arg = collection.rbegin(); arg != collection.rend(); arg++)

int main(int argc, char *argv[]){
  int T;
  cin >> T;

  for(int t=1;t<=T;t++) {
    printf("Case #%d: ", t);
    i64 A, B;
    cin >> A >> B;

    vector<double> p(A);
    for(int i=0;i<A;i++)
      cin >> p[i];
    
    double l1 = A + 2 * B + 2;
    double l2 = B + 1;
    double result = A + B + 1;
    for(int i=0;i<A;i++) {
      l2 *= p[i];
      result = min(result, double(l1 - 2 * (i + 1) - l2));
    }

    printf("%.6lf\n", min(result, double(B + 2)));
  }

  return 0;
}
