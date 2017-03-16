#include <cstdio>
#include <cstring>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

#define ll long long

int zt;
int e, r, n;
int amt[1005], energy;
ll p;

int main() {
  scanf("%d", &zt);
  for (int izz=0; izz<zt; ++izz) {
    scanf("%d %d %d", &e, &r, &n);
    p = 0;
    
    for (int i=0; i<n; ++i) {
      scanf("%d", &amt[i]);
    }
    energy = e;
    for (int i=0; i<n; ++i) {
      int toSpend = energy;
      for (int j=i+1; j<n; ++j) {
	if (amt[j] >= amt[i]) {
	  if (energy + r*(j-i) > e) {
	    toSpend = min(energy + r*(j-i) - e, energy);
	  }
	  else toSpend = 0;
	  break;
	}
      }
      p += toSpend * amt[i];
      energy -= (toSpend - r);
    }
    
    printf("Case #%d: %lld\n", izz+1, p);
  }
  
  return 0;
}