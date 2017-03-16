#include<iostream>
#include<fstream>
#include<algorithm>
#define ll long long
using namespace std;

int solve() {
}

int main(void) {
    int T;
    cin >> T;
    int k, c, s;
   
    for (int t = 1; t <= T; ++t) {
        printf("Case #%d: ", t);
        cin >> k >> c >> s;
        for (int i = 1; i <= k; ++i)
            cout << i << " ";
        cout << endl;
    }
}
