#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>


#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define pii piar < int, int >


using namespace std;


typedef long long LL;


int main() {
    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        cout << "Case #" << q + 1 << ": ";
        string s;
        cin >> s;
        string cur = "";

        for (int i = 0; i < (int) s.size(); ++i) {
            string c = "";
            c += s[i];
            cur = max(cur + c, c + cur);
        }
        cout << cur << endl;
    }
    return 0;
}