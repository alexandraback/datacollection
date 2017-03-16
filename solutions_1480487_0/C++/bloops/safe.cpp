#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <cstdio>
#include <cstring>
#include <cassert>
using namespace std;
const int N = 210;
double A[N];
double B[N];

int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int q = 1; q <= T; q++){
        int n;
        cin >> n;
        int X = 0;
        for (int i = 0; i < n; i++){
            cin >> A[i];
            X += A[i];
        }
        for (int i = 0; i < n; i++){
            double lo = 0.0, hi = 1.0;
            while(hi - lo > 1e-9){
                double mi = (lo + hi)/2;
                double iscore = A[i] + X*mi;
                double need = 0;
                for (int j = 0; j < n; j++){
                    if(j == i)
                        continue;
                    if(iscore > A[j])
                        need += double(iscore - A[j]) / X;
                }
                
                if(need + mi + 1e-10 < 1.0)
                    lo = mi;
                else
                    hi = mi;
            }
            B[i] = lo * 100;
        }
        cout.precision(10);
        cout << "Case #" << q << ": ";
        for (int i = 0; i < n; i++){
            cout << B[i] << ' ';
        }
        
        cout << '\n';
    }
    return 0;
}

