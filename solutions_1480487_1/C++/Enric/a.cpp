#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

const double eps = 1e-11;

int main() {
    cout.setf(ios::fixed);
    cout.precision(6);
    int t; cin >> t;
    for (int cas=1;cas<=t;++cas) {
        int n; cin >> n;
        vector<int> v(n);
        int s = 0;
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            s+=v[i];
        }
        
        cout << "Case #" << cas << ":";
        for (int i=0;i<n;++i) {
            //cerr << "studying part " << i << endl;
            double lo = 0, hi=1,x;
            while(abs(hi-lo)>eps) {
                x = (lo+hi)/2;
                //cerr << "Test x= " << x << endl;
                double sumneed=0; //quant necessito per cada y
                //if (i==1) cerr << x << " necessito: ";
                for (int j = 0;j < n;++j) if (j!=i) {
                    //if (i==1) cerr << " " << double(v[i]+s*x-v[j])/s;
                    sumneed+=max(double(v[i]+s*x-v[j])/s,0.); // >= y
                    //cerr << j << ": " << yj << endl;
                }
                //if (i==1) cerr << endl;
                if (sumneed>1-x) hi=x; //el salvo
                else lo=x;
            }
            x*=100;
            cout << " " << x;
        }
        cout << endl;
        
    }
}
