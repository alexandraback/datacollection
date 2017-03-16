#include <set>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <vector>
#include <limits>
#include <utility>
#include <map>
#include <sstream>
#include <queue>

using namespace std;

typedef unsigned long long ll;
#define MAXN 55
#define MAXD 50
#define MOD 1000000007


bool res[MAXN][MAXN];
ll t, b, m;


int main(){

    cin >> t;
    for (int cse = 1; cse <= t; cse++){
        cin >> b >> m;
        memset(res, 0, sizeof(res));

        cout << "Case #" << cse << ": ";
        if ((1LL << (b-2) < m)){
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        ll newm = m;
        ll curind = 1;
        bool possible = true;
        while (newm > 0){
            ll nodes = 0;
            if (newm == 1){
                newm--;
                res[0][b-1] = 1;
                break;
            }
            while ((1LL << nodes)-1 <= newm){
                nodes++;
            }
            nodes--;
            if (curind+nodes >= b){
                possible = false;
                break;
            }
            if (nodes){
                for (ll i = curind; i < curind+nodes;i++){
                    res[0][i] = true;
                    res[i][b-1] = true;
                    for (ll j = i + 1; j < curind+nodes; j++){
                        res[0][j] = true;
                        res[i][j] = true;
                        res[j][b-1] = true;
                    }
                }
                newm -= (1LL << nodes)-1;
                curind = curind+nodes;
            }

        }
        if (possible == false){
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        cout << "POSSIBLE" << endl;
        for (int i = 0; i < b; i++){
            for (int j = 0; j < b; j++){
                cout << res[i][j];
            }
            cout << endl;
        }

    }

    return 0;

}


