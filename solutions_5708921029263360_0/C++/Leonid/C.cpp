#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <list>
using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); i++)

void openFiles() {
    // freopen("test.in", "rt", stdin);
    // freopen("test.out", "wt", stdout);
	freopen("C-small-attempt2.in", "rt", stdin);
	freopen("C-small-attempt2.out", "wt", stdout);
	// freopen("C-large.in", "rt", stdin);
	// freopen("C-large.out", "wt", stdout);
}

const int BASE = 4;
inline int getNr(int a, int b, int c) {
    int nr = a + BASE * b + (BASE * BASE) * c;
    //cout << a << " " << b << " " << c << ": " << nr << endl;
    return nr;
}

bool checkOutfit(vector<int>& mp, int a, int b, int c, int limit) {    
    if (mp[getNr(a, b, c)] >= limit) return false;
    return true;
}

void addOutfit(vector<int>& mp, int a, int b, int c) {
    mp[getNr(a, b, c)]++;
}

void removeOutfit(vector<int>& mp, int a, int b, int c) {
    mp[getNr(a, b, c)]--;
}

bool addOutfits(vector<int>& mp, int a, int b, int c, int limit) {
    //cout << "check1" << endl;
    if (!checkOutfit(mp, a, b, 0, limit)) return false;
    //cout << "check2" << endl;
    if (!checkOutfit(mp, a, 0, c, limit)) return false;
    //cout << "check3" << endl;
    if (!checkOutfit(mp, 0, b, c, limit)) return false;
    addOutfit(mp, a, b, 0);
    addOutfit(mp, a, 0, c);
    addOutfit(mp, 0, b, c);
    return true;
}

void removeOutfits(vector<int>& mp, int a, int b, int c) {
    removeOutfit(mp, a, b, 0);
    removeOutfit(mp, a, 0, c);
    removeOutfit(mp, 0, b, c);
}

int A[1005], B[1005], C[1005];

void enumerate(int j, int p, int s) {
    int k = 0;
    REP(i1, j) REP(i2, p) REP(i3, s) {
        A[k] = i1 + 1;
        B[k] = i2 + 1;
        C[k] = i3 + 1;
        k++;
    }
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os<<"[";for(int i=0;i<v.size();i++)os<<" "<<v[i];os<<" ]";
    return os;
}

void printAnswer(const vector<int>& outf) {
    printf("%d\n", (int)outf.size());
    REP(o, outf.size()) {
        printf("%d %d %d\n", A[outf[o]], B[outf[o]], C[outf[o]]);
    }
}

int bestsz = 0;
vector<int> bestoutfits;
int iter = 0;
void recur(vector<int>& mp, int o, int mxo, vector<int>& outfits, int limit) {
    iter++;
    if (o == mxo) {
        if (outfits.size() > bestsz) {
            bestsz = outfits.size();
            bestoutfits = outfits;
        }
        return;
    }
    int a = A[o], b = B[o], c = C[o];
    //cerr << o << endl;
    if (addOutfits(mp, a, b, c, limit)) {        
        //cout << mp << endl;
        //cerr << mp << " " << a << " " << b << " " << c << endl;
        // cerr << endl;
        outfits.push_back(o);
        // cout << o << " -> " << outfits << endl;
        //printAnswer(outfits);
        recur(mp, o + 1, mxo, outfits, limit);
        outfits.pop_back();
        removeOutfits(mp, a, b, c);
    }
    recur(mp, o + 1, mxo, outfits, limit);
}

void solve() {
	bestsz = 0;
    bestoutfits.clear();
    int j, p, s, k; scanf(" %d %d %d %d", &j, &p, &s, &k);
    int mxo = j * p * s;
    enumerate(j, p, s);
    vector<int> outfits;
    vector<int> mp(BASE * BASE * BASE);
    recur(mp, 0, mxo, outfits, k);
    printAnswer(bestoutfits);
}

int main() {
    openFiles();
    int n; scanf("%d ", &n);
    for (int i = 0; i < n; i++) {
        cerr << i << endl;
        printf("Case #%d: ", i + 1);
        solve();
    }
    return 0;
}
