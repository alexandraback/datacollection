#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ull> vull;
#define FORN(y_, n_) for(int y_ = 0; y_ < (n_); ++y_)

int main (int argc, char** argv)
{
    istream* is = &cin;
    ostream* os = &cout;

    if (argc >= 2) is = new ifstream(argv[1]);
    if (argc == 3) os = new ofstream(argv[2]);
 
    int T;
    *is >> T;
    FORN(i,T){
        int N, S, p;
        *is >> N >> S >> p;
        vector<vi> d(2,vi(N,0));
        FORN(j,N){
            int n;
            *is >> n;
            if (0 == n){
                d[0][j] = (p == 0);
            }else{
                for (int k = 10; k > p -1; k--){
                    if (((n % 3 == 0) && (n /3 == k)) ||
                            (n - k == 2*(k - 1)) ||
                            (n -2*k == k - 1)) d[0][j] =1;
                    if ( (n - k == 2*(k-2)) ||
                            (n - k == (k - 1 + k -2)) ||
                            (n - 2*k == k -2 )) d[1][j] = 1;
                }
            }
        }
        int total = 0;
        for (int j = 0; (j < N) && (S> 0); j++){
            if ((d[1][j] >0) && (d[0][j] == 0)){
                S--;
                total++;
                d[1][j] = 0;
            }
        }
        for (int j = 0; (j < N) && ( S> 0); j++){
            if ((d[1][j]) && (d[0][j])){
                S--;
                total++;
                d[1][j] = d[0][j] = 0;
            }
        }
        for (int j = 0; j < N; j++){
            if ((d[0][j])){
                total++;
                d[0][j] = 0;
            }
        }

        *os << "Case #" << i+1 <<": " << total << endl;
    }
    if (is != &cin) delete is;
    os->flush();
    if (os != &cout) delete os;
    
    return 0;
}

