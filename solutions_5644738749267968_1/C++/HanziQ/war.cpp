#include <iostream>
#include <algorithm>
using namespace std;

void solveCase() {
  int count;
  cin >> count;

  double * naomi, * ken;

  naomi = new double[count];
  ken = new double[count];

  int ns, ne, ks, ke;
  ns = 0;
  ne = count - 1;
  ks = 0;
  ke = count - 1;

  for(int i = 0; i < count; i++)
    cin >> naomi[i];

  for(int i = 0; i < count; i++)
    cin >> ken[i];

  sort(naomi, naomi + count);
  sort(ken, ken + count);

  int dwar = 0;
  int war = 0;

  int blocks = count;

  // DWAR

  while(blocks > 0) {
    if(naomi[ns] < ken[ks]) {
      ke--;
      ns++;
    }
    else {
      ns++;
      ks++;
      dwar++;
    }
    blocks--;
  }

  //end DWAR
  // WAR
  ns = 0;
  ne = count - 1;
  ks = 0;
  ke = count - 1;

  blocks = count;
  while(blocks > 0) {
    if(naomi[ne] > ken[ke]) {
        ne--;
        ks++;
        war++;
    }
    else {
      ne--;
      ke--;
    }
    blocks--;
  }


  cout << dwar << " " << war;

}

int main() {
  int T;
  cin >> T;
  for(int i = 1; i <= T; i++) {
    cout << "Case #" << i << ": ";
    solveCase();
    cout << endl;
  }
}