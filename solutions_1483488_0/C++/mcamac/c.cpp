#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main() {
  ifstream fin("csmall.in");
  ofstream fout("csmall.out");

  int t; fin >> t;
  for(int c = 1; c <= t; c++){
    int a, b;
    fin >> a >> b;
    int tot = 0;
    int d = 0, t = a;
    while(t >= 1) {
      t /= 10;
      d++;
    }
    int dig[d];
    int seen[d];
    for (int n = a; n <= b; n++) {
      t = n;
      for(int s = 0; s < d; s++) {
        dig[d - s - 1] = t % 10;
        t /= 10;
      }
      for(int s = 1; s <= d - 1; s++) { // offset
        int r = 0;
        for(int q = 0; q < d; q++) {
          r = 10 * r + dig[(s + q) % d];
        }
        seen[s] = r;
        if(n < r && r <= b) {
          bool flag = true;
          for(int sj = 1; sj < s; sj++) {
            if(seen[sj] == r) flag = false;
          }

          if(flag) {
            tot++;
            //cout << n << " " <<  r << endl;
          }
        }
        // /cout << r << endl;
      }
    }

    cout << "Case #" << c << ": " << tot << endl;
    fout << "Case #" << c << ": " << tot << endl;
  }

}