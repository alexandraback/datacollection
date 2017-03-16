#include <iostream>
using namespace std;

#define LMAX 1000001
#define ISVOY(C) ((C)=='a' || (C)=='e' || (C)=='i' || (C)=='o' || (C)=='u')
typedef int ent;

ent maxfrom[LMAX];
string mot;
ent cpt;
ent maxuntil;

int main() {
  int T,n;
  cin >> T;
  for (int t=1; t<=T; ++t) {
    cin >> mot >> n;
    maxuntil = 0;
    cpt = 0;
    for (int p=0; p<(int)mot.size(); ++p) {
      if (ISVOY(mot[p])) maxuntil = 0;
      else maxuntil += 1;
      if (maxuntil>0) maxfrom[p] = 1;
      else maxfrom[p] = 0;
      if (maxfrom[p]>=n) cpt += 1;
      for (int p0=0; p0<p; ++p0) {
	maxfrom[p0] = max(maxfrom[p0],min(p-p0+1,maxuntil));
	if (maxfrom[p0]>=n) cpt += 1;
      }
    }
    cout << "Case #" << t << ": " << cpt << endl;
  }
  return 0;
}
