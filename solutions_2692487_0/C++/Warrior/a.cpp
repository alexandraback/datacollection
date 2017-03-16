#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

#define MAX 105

using namespace std;

int a,n;
int v[MAX];

int main() {
  int tt;
  cin >> tt;
  
  for (int t = 1; t<=tt; t++) {
    cin >> a >> n;
    for (int i = 0; i<n; i++)
      cin >> v[i];
  
    sort(v, v+n);

    //printf("--------- %d\n", a);
    //for (int i = 0; i<n; i++)
    //printf("--- %d\n", v[i]);
    
    int sol = MAX;
    int olda = a;
    if (a == 1)
      sol = n;
    else {
      for (int k = 0; k <= n; k++) {
	a = olda;
	//printf("k: %d\n", k);
	int csol = k;
	for (int i = 0; i<n-k; i++) {
	  if (a > v[i])
	    a += v[i];
	  else {
	    //printf("%d < %d (%d)\n", a, v[i], csol);
	    while (a <= v[i]) {
	      csol++;
	      a += a-1;
	    }
	    a += v[i];
	  }
	}
	//printf("- %d %d\n", k, csol);
	sol = min(sol, csol);
      }
    }
    cout << "Case #" << t << ": " << sol << endl;

  }
  return 0;
}
