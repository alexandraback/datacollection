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

int porovnaj(int x, int y){
    dbg cout << "porovnaj\n";
    db(x);
    db(y);
    if(cifry(x) != cifry(y)){
        return 0;
    }
    else if(cifry(x) == 1){
        return 0;
    }
    else{
        int len = cifry(x);
        int len10 = 1;
        {
            int l = len;
            while(l--) len10 *= 10;
        }
        for(int i = 10; i <= x; i*=10){
            int new_x = x/i + (x%i)*(len10/i);
            db(new_x);
            if(new_x == y){
                return 1;
            }
        }
        return 0;
    }
}

int main(){
    int n;
    cin >> n;
    For(casse, n){
        int a, b;
        cin >> a >> b;
        int count = 0;
        for(int i = a; i <= b; i++){
            for(int j = i+1; j <= b; j++){
                count += porovnaj(i, j);
            }
        }
        cout << "Case #" << casse+1 << ": " << count << endl; 
    }
}
