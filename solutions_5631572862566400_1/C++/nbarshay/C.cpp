#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>

#define For(i,a,b) for(int i = a; i < b; i++)
#define rep(i,x) For(i,0,x)
#define foreach(i,c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define sz(x) ((int)(x).size())
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define TWO(x) (1LL<<(x))

using namespace std;

vector<int> A;
vector<int> V;

vector<vector<int>> B;

int nidx;

int cstart;
int clen;

//return: color
bool rec(int at) {
    if(V[at] == -2) {
        V[at] = nidx;
        cstart = at;
        clen = 1;
        return true;
    } else if(V[at] == -1) {
        V[at] = -2;
        int hit = rec(A[at]);
        if(hit) {
            V[at] = nidx;
            if(at == cstart) {
                return false;
            } else {
                clen++;
                return true;
            }
        } else {
            V[at] = -1;
            return false;
        }
    } else {
        return false;
    }
}

int tlen(int at) {
    int res = 0;
    for(int x : B[at]) {
        if(V[x] == -1) {
            res = max(res, tlen(x)+1);
        }
    }
    return res;
}

int main() {
    int np; cin>>np;
    rep(i, np){
        cout << "Case #"<<(i+1)<<": ";

        int n; cin>>n;

        A = vector<int>(n);
        B = vector<vector<int>>(n);
        rep(i,n) {
            cin >> A[i];
            A[i]--;
            B[A[i]].push_back(i);
        }

        V = vector<int>(n, -1);

        vector<int> cyclen;

        nidx = 0;

        rep(i, n) {
            clen = 0;
            rec(i);
            if(clen > 0) {
                cyclen.push_back(clen);
                nidx++;
 
            }
        }

        vector<vector<int>> tlens(nidx, vector<int>(2,0));
        rep(i,n) {
            if(V[i] >= 0) {
                tlens[V[i]].push_back(tlen(i) );
            }
        }

        rep(i, nidx) {
            sort(tlens[i].begin(), tlens[i].end());
            reverse(tlens[i].begin(), tlens[i].end());
        }

        int opta = 0;
        int optb = 0;

        int res = 0;
        rep(i, nidx) {
            if(cyclen[i] > 2) {
                opta = max(cyclen[i], opta);
            } else {
                optb += 2 + tlens[i][0] + tlens[i][1];
            }
        }

        cout << max(opta, optb) << endl;
    }
}
