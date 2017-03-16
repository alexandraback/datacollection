

#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <complex>
#include <cassert>

using namespace std;

#define rep(i,b) for(int i=(0);i<(b);++i)
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fore(a,b) for(__typeof((b).begin()) a = (b).begin();a!=(b).end();++a)
#define vv vector
#define pb push_back
#define ll long long
#define ld long double
#define ss(a) (int)(a).size()
#define all(x) (x).begin(),(x).end()
#define clr(x,a) memset(x,a,sizeof(x))
#define vi vv<int>
#define vs vv<string>

int cond = (ll)1;
#define db(x) { if (cond > 0) { cond--; rep (xxx, 1) cerr << __LINE__ << " " << #x << " " << x << endl; cerr.flush(); } }

int x[100][100];

int r, c, m;

void wypisz() {
    x[0][0] = 'c';
    printf("\n");
    rep(i, r) {
        rep (j, c) printf("%c", x[i][j]);
        printf("\n");
    }
    assert(x[0][0] == 'c');

    int cst = 0;
    int cdot = 0;
    rep (i, r) rep(j, c) 
        if (x[i][j] == '*') cst++;
        else if (x[i][j] == '.') cdot++;
    assert(cst == m);
    assert(1 + cdot + cst == r*c);
}

int wynik(int a, int b, int a2, int b2) {
    rep (i, r) rep(j, c) x[i][j] = '*';
    x[0][0] = 'c';
    rep (i, a) rep(j, b) x[i][j] = '.';
    fo (xxx, 0, a2-1)
        x[a][xxx] = '.';
    fo (xxx, 0, b2-1)
        x[xxx][b] = '.';
}

void solve() {
    scanf("%d%d%d", &r, &c, &m);
    rep (i, r) rep(j, c) x[i][j] = '.';
    int puste = r*c - m;

    
    x[0][0] = 'c';

    if (r == 1) {
        fo(j, puste, c-1) x[0][j] = '*';
        wypisz();
        return;
    }
    if (c == 1) {
        fo(j, puste, r-1) x[j][0] = '*';
        wypisz();
        return;
    }
    if (puste == 1) {
        rep (i, r) rep(j, c) x[i][j] = '*';
        x[0][0] = 'c';
        wypisz();
        return;
    }
    if (puste == 2 || puste == 3) {
        printf("\nImpossible\n");
//#printf("\nImpossible %d %d %d\n", r, c, m);
        return;
    }
    db(puste)
    fo (a, 2, r) fo (b, 2, c) {
        fo(dol, 0, b)
            fo (ri, 0, a) {
                if (dol != 1 && ri != 1) {
                    int sum = a * b + dol + ri;
                    if (dol && a == r) continue;
                    if (ri && b == c) continue;

                    if (sum == puste) {
                        db(a<<" "<<b<<" "<<dol<<" "<<ri);
                        wynik(a, b, dol, ri);
                        wypisz();
                        return;
                    }
                }
            }
    }
    printf("\nImpossible\n");
// printf("Impossible2 %d %d %d\n", r, c, m);
    return;
}

int main(int argc, char ** argv) {
    //  freopen("../1.in","r",stdin); 
    //  freopen("../2.in","r",stdin); 
    //  freopen("../3.in","r",stdin); 
    //  freopen("../C-small.in","r",stdin); freopen("../C-small.out","w",stdout);
    //freopen("../C-small-attempt0.in","r",stdin);freopen("../C-small-attempt0.out","w",stdout);
   //  freopen("../C-small-attempt1.in","r",stdin);freopen("../C-small-attempt1.out","w",stdout);
//      freopen("../C-small-attempt2.in","r",stdin);freopen("../C-small-attempt2.out","w",stdout);
      freopen("../C-large.in","r",stdin); freopen("../C-large.out","w",stdout);

    cond = argc >= 2 && argv[1][0] == 'q' ? 1 << 30 : 0;
    int t;
    scanf("%d", &t);
    fo (i, 1, t) {
        if (cond)
            cerr << __LINE__ << " " << i << endl;
        printf("Case #%d: ", i);
        solve();
        fflush(stdout);
        cerr.flush();
    }
	return 0;
}

