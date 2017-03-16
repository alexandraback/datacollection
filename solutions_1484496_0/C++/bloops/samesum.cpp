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
typedef pair<int,int> ii;

ii sums[1<<20];
int A[22];

int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;

    for (int q = 1; q <= T; q++){
        int n;
        cin >> n;
        for (int i = 0; i < n; i++){
            cin >> A[i];
        }
        for (int bit = 0; bit < (1<<n); bit++){
            sums[bit].first = 0;
            for (int i = 0; i < n; i++){
                if(bit & (1<<i))
                    sums[bit].first += A[i];
            }
            sums[bit].second = bit;
        }
        sort(sums, sums + (1<<n));

        cout << "Case #" << q << ":\n";

        bool possible = false;
        for (int i = 0; i+1 < (1<<n); i++){
            if(sums[i].first == sums[i+1].first){
                possible = true;
                for (int j = 0; j < n; j++){
                    if(sums[i].second & (1<<j))
                        cout << A[j] << ' ';
                }
                cout << '\n';                

                for (int j = 0; j < n; j++){
                    if(sums[i+1].second & (1<<j))
                        cout << A[j] << ' ';
                }
                cout << '\n';                
                break;
            }
        }
        
        if(!possible)
            cout << "Impossible\n";

    }
    return 0;
}

