#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <climits>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <queue>
#include <bitset>
#include <string>
#include <complex>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)
#define repa(i,s,e) for(int i=s; i<=e; i++)
#define repd(i,s,e) for(int i=s; i>=e; i--)

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;

int T, K, N, key, m;
int keys[201];
int O[201];
bitset<1050000> S;
bitset<20> C;
vector<vi> V;
vi A;

bool dfs() {
    bool isEnd = true;
    rep(i,N) {
        if(!C[i]) {
            isEnd = false;
            break;
        }
    }
    if(isEnd) return true;
    
    rep(i,N) {
        if(!C[i] && keys[O[i]] > 0) {
            C.set(i);
            int id = (int)C.to_ulong();
            if(!S[id]) {
                S.set(id);
                keys[O[i]]--;
                rep(k,V[i].size()) keys[V[i][k]]++;

                if(dfs()) {
                    A.push_back(i+1);
                    return true;
                }
            
                rep(k,V[i].size()) keys[V[i][k]]--;
                keys[O[i]]++;
            }
            C.reset(i);
        }
    }
    return false;
}

int main() {
    cin >> T;
    repa(t,1,T) {
        A.clear();
        fill(O, O+201, 0);
        C.reset();
        S.reset();
        fill(keys, keys+201, 0);
        
        cin >> K >> N;
        V = vector<vi>(N, vi());
        rep(k,K) {
            cin >> key;
            keys[key]++;
        }

        rep(n,N) {
            cin >> O[n];
            cin >> m;
            rep(i,m) {
                cin >> key;
                V[n].push_back(key);
            }
        }
        
        printf("Case #%d: ", t);
        if(dfs()) {
            rep(i,N) {
                cout << A[N-i-1] << " ";
            }
        } else {
            cout << "IMPOSSIBLE";
        }
        cout << endl;
    }
}
