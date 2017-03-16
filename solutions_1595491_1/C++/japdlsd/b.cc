/* Look at my code
 * My code is amazing
 * Give it a lick
 * Mmm! It tastes just like raisins!
*/

//another_fine_solution by Askar

#include <cstdio>
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <tr1/unordered_set>
using namespace std;
using namespace std::tr1;

#define For(i,n) for(int i = 0; i < n; i++)
#define mp make_pair
#define PASS
 

#ifdef EBUG
    #define db(x) cout << #x << "\t: " << (x) << endl;
    #define dbg if(1)
#else
    #define db(x)
    #define dbg if(0)
#endif


int main(){
    int t; // number of cases
    cin >> t;
    For(cas, t){
        int n; // number of Googlers
        cin >> n;
        int s; // number of surprices
        cin >> s;
        int p; // wanted best result
        cin >> p;
        
        int count = 0; // number of good 
        
        For(i, n){
            int x;
            cin >> x;
            if(3*p - 3 < x){
                // good already
                count++;
            }
            else if(s && 3*(p-1)-1 <= x && p <= x){
                count++;
                s--;
            }
        }
        cout << "Case #" << cas+1 << ": " << count << endl;
    }
}
