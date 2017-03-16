//#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

ifstream cin("A-large.in");
ofstream cout("A-large.out");

int main() {
    int T;
    cin >> T;
    for (int t=0; t<T; t++) {
      int a[10];
      for (int i=0; i<10; i++) a[i] = 0;
      cout << "Case #" << t+1 << ": ";
      int N,Nf;
      cin >> N; Nf=N; bool found = false;
      if (N==0) cout << "INSOMNIA";
      else {
        while (!found) {
          int tmpN=Nf;
          while (tmpN!=0) {
            a[tmpN%10]=1; tmpN=tmpN/10;
          }
          found = true;
          for (int i=0; i<10; i++) if (!a[i]) found = false;
          if (!found) Nf=Nf+N; else cout << Nf;
        }
      }
      cout << endl;
    }
return 0;
}
