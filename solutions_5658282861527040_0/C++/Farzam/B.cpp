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



int main()
{
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        int A, B, K;
        cin >> A >> B >> K;
        int ans = 0;
        for (int i = 0; i < A; i++)
            for (int j = 0; j < B; j++)
                if ((i & j) < K)
                    ans++;
        cout << ans << endl;
    }


    return 0;
}
