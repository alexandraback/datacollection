// In the name of God
#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <queue>
#include <utility>
#include <vector>


using namespace std;


typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> point;

#define siz(x) (int(x.size()))
#define err(x) cerr << #x << " = " << x << endl;
#define pb push_back
#define mp make_pair

#define X first
#define Y second
// #define X real()
// #define Y imag()

const double eps = 1e-8;


ll dyn[32][2][2][2]; // bit, matches A, matches B, matches K
int main()
{
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        int A, B, K;
        cin >> A >> B >> K;
        // if (A > B)
            // swap(A, B);
        for (int i = 0; i < 32; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    for (int l = 0; l < 2; l++)
                        dyn[i][j][k][l] = 0;
        dyn[31][1][1][1] = 1;
        for (int i = 30; i >= 0; i--) {
            bool isk = K & (1 << i);
            bool isa = A & (1 << i);
            bool isb = B & (1 << i);
            dyn[i][0][0][0] = dyn[i + 1][0][0][0] * 4
                            + dyn[i + 1][0][0][1] * isk * 3
                            + dyn[i + 1][0][1][0] * isb * 2
                            + dyn[i + 1][1][0][0] * isa * 2
                            + dyn[i + 1][0][1][1] * isb * isk * 2
                            + dyn[i + 1][1][0][1] * isa * isk * 2
                            + dyn[i + 1][1][1][0] * isa * isb
                            + dyn[i + 1][1][1][1] * isa * isb * isk;

            dyn[i][0][0][1] = dyn[i + 1][0][0][1] * (isk ? 1 : 3)
                            + dyn[i + 1][1][0][1] * isa * !isk * 2
                            + dyn[i + 1][0][1][1] * isb * !isk * 2
                            + dyn[i + 1][1][1][1] * isa * isb * !isk;

            dyn[i][0][1][0] = dyn[i + 1][0][1][0] * 2
                            + dyn[i + 1][0][1][1] * isk * (isb ? 1 : 2)
                            + dyn[i + 1][1][1][0] * isa 
                            + dyn[i + 1][1][1][1] * isa * isk;

            dyn[i][1][0][0] = dyn[i + 1][1][0][0] * 2
                            + dyn[i + 1][1][0][1] * isk * (isa ? 1 : 2)
                            + dyn[i + 1][1][1][0] * isb
                            + dyn[i + 1][1][1][1] * isb * isk;

            dyn[i][0][1][1] = dyn[i + 1][0][1][1] * (isk ? isb : (isb ? 1 : 2))
                            + dyn[i + 1][1][1][1] * isa * !isk;
            dyn[i][1][0][1] = dyn[i + 1][1][0][1] * (isk ? isa : (isa ? 1 : 2))
                            + dyn[i + 1][1][1][1] * isb * !isk;

            dyn[i][1][1][0] = (((A & B & (1 << i)) < (K & (1 << i))) ? dyn[i + 1][1][1][1] : 0) 
                            + dyn[i + 1][1][1][0];

            dyn[i][1][1][1] = ((A & B & (1 << i)) == (K & (1 << i))) ? dyn[i + 1][1][1][1] : 0;
            for (int j = 0; j < 2; j++) 
                for (int k = 0; k < 2; k++)
                    for (int l = 0; l < 2; l++) {
                        // if (i < 2)
                        // cerr << "DYN: " << i << " " << j << " " << k << " " << l << " " << "  =    " << dyn[i][j][k][l] << endl;
                    }
            // cerr << endl;


        }

        int ans = 0;
        for (int j = 0; j < 2; j++) 
            for (int k = 0; k < 2; k++)
                for (int l = 0; l < 2; l++) {
                    ans += dyn[0][j][k][l];
                    // cerr << j << " " << k << " " << l << " " << dyn[0][j][k][l] << endl;
                }

        cout << dyn[0][0][0][0] << endl;
    }


    return 0;
}
