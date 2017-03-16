//#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

ifstream cin("A-small-attempt3.in");
ofstream cout("A-small.out");

int main() {
    int T;
    cin >> T;
    for (int t=0; t<T; t++) {
       cout << "Case #" << t+1 << ": ";
       int d; char c; int d2;
       cin >> d >> c >> d2;
       double k = (double)(d)/(double)(d2);
       int j=1; bool f = true;
       while (j<=40) {
            if (2*k-1>=0) {
                double z = 2*k-1;
                int nleft = 40-j+1; bool possib = false;
                while (nleft > 0) {
                    if ((z-(int)(z))==0) { possib = true; break; }
                    nleft--; z=z*2; if (z>=1) z--;
                }
                if (possib) {
                    cout << j << endl; f = false; break;
                }
            }
            j=j+1; k*=2; if (k>=1) k-=1;
       }
       if (f) cout << "impossible" << endl;
    }
return 0;
}
