#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

void main_1B_A() {
    unsigned int T;

    cin >> T;
    for (unsigned int i=0;i<T;++i) {
        unsigned int N, S=0, partialS=0, partialN=0;
        vector<unsigned int> s;

        cin >> N;
        s.resize(N);

        for(unsigned int j=0;j<N;++j) {
            cin >> s[j];
            S += s[j];
        }

        for(unsigned int j=0;j<N;++j) {
            if (2*S > s[j]*N) {
                partialS += s[j];
                ++partialN;
            }
        }
        double k = ((double)(S+partialS))/partialN;

        cout << "Case #" << (i+1) << ":";

        for(unsigned int j=0;j<N;++j) {
            double percentage;
            if (2*S > s[j]*N) percentage = (100*((k-s[j])/S));
            else percentage = 0;
            cout << " " <<setprecision(8) << percentage;
        }
        cout << endl;
    }
}


