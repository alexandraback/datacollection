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

int cifry(int x){
    int res = 0;
    //dbg cout << "cifry " << x;
    while(x){
        res++;
        x /= 10;
    }
    //dbg cout << " " << res << endl; 
    return res;
}

int main(){
    int n;
    cin >> n;
    For(casse, n){
        int a, b;
        cin >> a >> b;
        int count = 0;
        bool used[b+1];
        For(i, b+1) used[i] = 0;
        for(int x = a; x <= b; x++){
            db(x);
            if(used[x]) continue;
            else used[x] = 1;

            int len10 = 1;
            {
                int l = cifry(x);
                while(l--) len10 *= 10;
            }
            int subcount = 1;
            set<int> subset;
            subset.insert(x);
            for(int i = 10; i <= x; i*=10){
                int new_x = x/i + (x%i)*(len10/i);
                db(new_x);
                if(a <= new_x && new_x <= b && subset.find(new_x) == subset.end()){
                    used[new_x] = 1;
                    subcount++;
                    subset.insert(new_x);
                }
            }
            count += subcount*(subcount - 1)/2;
        }
        cout << "Case #" << casse+1 << ": " << count << endl; 
    }
}
