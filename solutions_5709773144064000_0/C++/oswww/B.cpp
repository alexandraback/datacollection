#define OSW

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
using namespace std;



int main() {
    #ifdef OSW
    freopen("C:\\Users\\Oswww\\Desktop\\in.txt", "r", stdin);
    #endif // OSW
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    int t=0;
    while (T-(t++)) {
        double C,F,X;
        cin >> C >> F >> X;


        int num = 0;
        if (C<X) {
            double temp = F*(X/C-1.0);
            if (temp>2) num = (temp-2)/F;
        }
        double f = 2;
        double time = 0;
        for (int i=0; i!=num; ++i) {
            time += C/f;
            f += F;
            //cout << f << ' ';
        }

        time += min(X/f, C/f + X/(f+F));
        cout.precision(15);
        cout << "Case #" << t << ": " << time << endl;
    }
}

