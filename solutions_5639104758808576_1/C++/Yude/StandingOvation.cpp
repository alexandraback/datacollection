#include <bits/stdc++.h>
using namespace std;


int main() {
    int totaltc;
    string shynesses;
    int smax;
    int tc = 1;
    cin >> totaltc;
    while (totaltc--) {
        cin >> smax >> shynesses;
        int numfriends = 0;
        int totalstanding = shynesses[0] - '0';
        for (int i = 1; i <= smax; i++) {
            if (totalstanding < i) numfriends++, totalstanding ++;
            totalstanding += shynesses[i] - '0';
        }
        cout << "Case #" << tc++ << ": " << numfriends << endl;
    }
    return 0;
}
