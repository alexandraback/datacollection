/* Look at my code
 * My code is amazing
 * Give it a lick
 * Mmm! It tastes just like raisins!
*/

//another_fine_solution by Askar

// input/output
#include <cstdio>
#include <iostream>
// structures
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <tr1/unordered_set>
#include <tr1/unordered_map>
// other stuff
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <utility>
// debug
#ifndef EBUG
    #define NDEBUG
#endif
#include <cassert>

using namespace std;
using namespace std::tr1;

#ifdef EBUG
    #include <cstdio>
    #define db(x) cout << #x << "\t: " << (x) << endl;
    #define dbg if(1)
#else
    #define db(x)
    #define dbg if(0)
#endif

#define For(i,n) for(int i = 0; i < n; i++)
#define iter(x) typeof((x).begin())
#define Foreach(it, str) for(typeof((str).begin()) it = (str).begin(); it != (str).end(); it++)
#define mp make_pair
#define PASS
#define ll long long
#define INF 2000000000

vector<ll> pole;

vector<int> stav;

int N;
bool hura;

void rek(int k){
    db(k);
    if(hura) return;
    if(k == N){
        ll sum1 = 0;
        ll sum2 = 0;
        For(i, N){
            if(stav[i] == 1) sum1 += pole[i];
            if(stav[i] == 2) sum2 += pole[i];
        }
        if(sum1 == sum2 && sum1 != 0){
            hura = true;
        }
        return;
    }

    For(i, 3){
        if(hura) return;
        stav[k] = i;
        rek(k+1);
    }
}

int main(){
    int T;  
    cin >> T;
    for(int t = 1; t <= T; t++){
        ///////////////////
        cin >> N;
        pole.clear();
        pole.resize(N);
        For(i, N){
            cin >> pole[i];
        }
        stav.clear();
        stav.resize(N, 0);
        cout << "Case #" << t << ":";
        hura = false;
        rek(0);
        if(!hura) cout << endl << "Impossible\n";
        else{
            cout << endl;
            For(i, N) if(stav[i] == 1) cout << pole[i] << " "; cout << endl;
            For(i, N) if(stav[i] == 2) cout << pole[i] << " "; cout << endl;
        }

        ///////////////////
    }
}
