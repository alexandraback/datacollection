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


int main(){
    int T;
    cin >> T;
    for(int t = 1; t <=T;t++){
        int N;
        cin >> N;
        int a[N];
        ll sum = 0;
        For(i, N){
            cin >> a[i];
            sum += a[i];
        }
        double priemer = 2.00*sum/N;
        cout << "Case #" << t << ":";
        int amaz = 0;
        int amaz_sum = 0;
        For(i, N) if(a[i] < priemer){ amaz++; amaz_sum += a[i];}
        double amaz_priemer = 1.00 *(amaz_sum +sum) /amaz;
        For(i, N){
            cout.precision(10);
            if(a[i] >= priemer) cout << " 0.0";
            else cout << " " << (amaz_priemer-a[i])/sum*100.00;
        }
        cout << endl;

    }
}
