#include <map> 
#include <set> 
#include <list>
#include <stack>
#include <cmath> 
#include <queue> 
#include <ctime>
#include <cfloat>
#include <vector> 
#include <string> 
#include <cstdio>
#include <bitset>
#include <random>
#include <climits> 
#include <cstdlib> 
#include <cstring> 
#include <cassert> 
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

#define FILL(X, V) memset(X, V, sizeof(X))
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for(TI(a) i = a.begin(); i != a.end(); i++)

#define PB push_back
#define MP make_pair

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;


int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    
    cout << "Case #1:\n";
    
    int R, N, M, K;
    cin >> R >> N >> M >> K;
    
    int64 prod[K];
    int64 guess[N];
    
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(2,M);
    
    while (R--) {
        
        REP(i,K) cin >> prod[i];
        unordered_set< string > tried;
        
        int tries = 0;
        while (true) {
            REP(i,N) guess[i] = distribution(generator); 
            sort(guess,guess+N);
            
            string sguess = "";
            REP(i, N) sguess += char(guess[i]);
            
            if (tried.count(sguess)) continue;
            
            unordered_set< int64 > possible;
            
            REP(mask,(1<<N)) {
                int64 subset = 1LL;
                REP(i, N) if (mask & (1<<i)) subset *= guess[i];
                possible.insert(subset);
            }
            
            bool valid_guess = true;
            
            REP(i, K) if (!possible.count(prod[i])) {
                valid_guess = false;
                break;
            }
            
            if (valid_guess || (tries == 100)) {
                REP(i,N) cout << guess[i]; cout << "\n";
                break;
            } else {
                tried.insert(sguess);
                tries++;   
            }
        }
        
    }
    
	return 0;
}

















