#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <cstdio>
#include <string>
#include <complex>
#include <stack>
#include <iomanip>
#include <map>

using namespace std;
typedef long double ld;
typedef complex<ld> pt;
typedef vector<pt> pol;

int main() {
    int N;
    cin >> N;
    for(int kase=1; kase <= N; kase++) {
        int smax; string s;
        cin >> smax >> s;
        int clapped = 0;
        int need = 0;
        for(int j=0; j<=smax; j++) {
            if(j > clapped && s[j]) {
                int friends = j-clapped;
                need += friends;
                clapped += friends;
            }
            int k = s[j]-'0';
            clapped += k;
        }
        cout << "Case #" << kase << ": " << need << endl;
    }

    return 0;    
}
