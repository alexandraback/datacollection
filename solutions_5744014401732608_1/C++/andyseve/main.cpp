#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cassert>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
#define int long long

int power(int a, int b)
{
    if (b == 0) return 1;
    if (b & 1) return power(a, b - 1) * a;
    return power(a * a, b / 2);
}

#undef int
int main()
{
#define int long long
    freopen("in", "r", stdin); freopen("out","w", stdout);
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++)
    {
        cerr << "Executing Case #" << tt << "\n";
        int b; cin >> b;
        int m; cin >> m;
        if(m > power(2,b-2)){
            cout << "Case #" << tt << ": IMPOSSIBLE" << endl;
        }
        else if(m == power(2,b-2)){
            cout << "Case #" << tt << ": POSSIBLE" << endl;
            for (int j = 0; j < b; j++){
                for (int i = 0; i < j+1; i++) cout << 0;
                for (int i = j+1; i < b; i++) cout << 1;
                cout << endl;
            }
        }
        else{
            cout << "Case #" << tt << ": POSSIBLE" << endl;
            int c[b];
            c[b-1] = 0;
            for (int i = 1; i < b; i++){
                c[b-1-i] = m % 2;
                m /= 2;
            }
            for (int i = 0; i < b; i++){
                cout << c[i];
            }
            cout << endl;
            for (int j = 1; j < b; j++){
                for (int i = 0; i < j+1; i++) cout << 0;
                for (int i = j+1; i < b; i++) cout << 1;
                cout << endl;
            }
        }
    }
    return 0;
}
