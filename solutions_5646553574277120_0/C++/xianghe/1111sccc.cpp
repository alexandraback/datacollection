#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int coin[110];
bool value[111];

int main()
{
    freopen("C-small-attempt4.in", "r", stdin);
    freopen("csout.out", "w", stdout);
    int t;
    cin >> t;
    
    for(int i = 1; i <= t; ++i){
        int c, d, v;
        cin >> c >> d >> v;
        memset(value, 0, sizeof(value));
        value[0]=1;
        for(int j = 0; j < d; ++j){
            int coin[j];
            cin >> coin[j];
            for(int k = v; k >= coin[j]; k--)
                value[k] = value[k] || value[k - coin[j]];
        }
        
        int rst = 0;
        for(int j = 1; j <= v; ++j){
            if(value[j] == 0){
                for(int k = v; k >= j; k--)
                    value[k] = value[k] || value[k-j];
                rst++;
            }
        }
        cout << "Case #" << i << ": " << rst << endl;
    }
    return 0;
}
