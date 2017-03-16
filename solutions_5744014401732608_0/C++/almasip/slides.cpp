#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

    int test;
    cin >> test;
    for (int tc=1; tc<=test; ++tc) {
        long long m,b;
        cin>>b>>m;
        cout << "Case #" << tc << ": ";
        int t[52][52];
        long long mx = (long long)(1 << (b-2));
        if (m > mx) {
            cout << "IMPOSSIBLE"<<endl;
            continue;
        }
        cout << "POSSIBLE" << endl;
        for (int i=0; i<b; i++) {
            for (int j=0; j<b-1; j++) {
                t[i][j] = (i<j);
            }
        }
        t[0][b-1] = (m == mx);
        m -= t[0][b-1];

        for (int i=1; i<b; i++) {
            t[i][b-1] = m%2;
            m/=2;
        }


        for (int i=0; i<b; i++) {
            for (int j=0; j<b; j++) {
                cout << t[i][j];
                if (j<b-1) cout<<" ";
            }
            cout << endl;
        }
    }
}
