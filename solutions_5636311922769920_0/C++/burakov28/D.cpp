#include <iostream>
#include <cstdio>


using namespace std;

typedef long long LL;


int main() {
    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        cout << "Case #" << q + 1 << ": ";
    
    
        LL k, c, s;
        cin >> k >> c >> s;
        LL pw = 1;
        for (int i = 0; i < c - 1; ++i) {
            pw *= k; 
        }

        for (int i = 0; i < s; ++i) {
            cout << pw * i + 1 << " ";
        }
        cout << endl;
    }

    
    return 0;
}