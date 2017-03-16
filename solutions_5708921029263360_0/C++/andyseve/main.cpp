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
        int J,P,S,K;
        cin >> J >> P >> S >> K;
        if(K < S){
            cout << "Case #" << tt << ": " << J * P * K << endl;
            int count = 0;
            for (int i = 0; i < J; i++){
                for (int j = 0; j < P; j++){
                    for (int k = 0; k < K; k++){
                        if(j == 0 && ((i+j+k) % S) == 0) count++;
                        cout << i+1 << " " << j + 1 << " " << ((i+j+k) % S) + 1 << endl;
                    }
                }
            }
            if(count > K) break;
        }
        else{
            cout << "Case #" << tt << ": " << J * P * S << endl;
            for (int i = 0; i < J; i++)
                for (int j = 0; j < P; j++)
                    for (int k = 0; k < S; k++)
                        cout << i+1 << " " << j + 1 << " " << k+1 << endl;
        }
    }
    return 0;
}
