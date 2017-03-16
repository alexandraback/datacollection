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
        int D;
        int P[1001];
        for(int i=0; i<1001; i++) {
            P[i] = 0;
        }
        cin >> D;
        int moves = 0;
        for(int i=0; i<D; i++) {
            int x;
            cin >> x;
            P[x]++;
        }
        for(int i=0; i<1001; i++) {
            if(P[i]) moves = i;
        }
        int best = moves;
        //cerr << moves << endl;
        for(int i=1000; i>=0; i--) {
            if(P[i] > 0) {
                int a = i/2, b = (i+1)/2;
                moves += P[i];
                P[a] += P[i];
                P[b] += P[i];
                P[i] = 0;
                for(int j=i; j>=0 && !P[j]; j--) {
                    moves--;
                }
                if(moves < best) best = moves;
                //cerr << moves << endl;
            }
        }
        cout << "Case #" << kase << ": " << best << endl;
    }

    return 0;    
}
