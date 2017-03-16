#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>


#define SIZE(A) ((int)(A).size())
#define ALL(A) (A).begin(),(A).end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define NMAX OOOOOO
#define MMAX OOOOOO
#define LL long long

using namespace std ;

//#define INFILE "date.in"
//#define	OUTFILE "date.out"
#define cin F
#define cout G

ifstream F (INFILE) ;
ofstream G (OUTFILE) ;

LL T ;
LL nr = 0, N, A, i, x, nrT = 0 ;
vector<LL> V ;

void Solve() ;

int main() {
    int i ;
    cin >> T ;
    for (i = 1; i <= T; ++i) {
        cout << "Case #" << i << ": " ;
        Solve() ;
        cout << '\n' ;
    }
	F.close() ;
	G.close() ;
	return 0;
}


void Solve() {
    nr = 0 ; nrT = 999999999 ;
    V.clear() ;
    cin >> A >> N ;
    for (i = 1; i <= N; ++i) {
        cin >> x ;
        V.pb(x) ;
    }
    sort(ALL(V)) ;
    for (i = 1; i <= N; ++i) {
        x = V[i - 1] ;
        if (x < A) {
            A += x ;
            continue ;
        }
        if (A + (A - 1) > x && (A - 1)) {
            ++nr ;
            A += (A - 1) + x ;
            continue ;
        }
        if (nr + (N-i) + 1 < nrT) {
            nrT = nr + (N - i) + 1 ;
        }
        while (A <= x && (A - 1)) {
            ++nr ;
            A += (A - 1) ;
        }
        if (A > x) {
            A += x ;
        }
        else {
            break ;
        }
        if (nr > nrT && nrT) {
            break ;
        }
    }
    if (nrT && nr) {
        cout << (nr > nrT ? nrT : nr) ;
    }
    else if (nrT == 999999999) {
        cout << nr ;
    }
    else {
        cout << nrT ;
    }
}
