
#include<algorithm>
#include<cassert>
#include<complex>
#include<map>
#include<iomanip>
#include<sstream>
#include<queue>
#include<set>
#include<string>
#include<vector>
#include<iostream>
#include<cstring>
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define fup FOR
#define fdo FORD
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define siz SZ
#define CLR(x) memset((x), 0, sizeof(x))
#define PB push_back
#define MP make_pair
#define X first
#define Y second 
#define FI X
#define SE Y
#define SQR(a) ((a)*(a))
#define DEBUG 1
#define debug(x) {if (DEBUG)cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {if (DEBUG) {cerr <<#x <<" = "; FORE(it, (x)) cerr <<*it <<", "; cout <<endl; }}
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int> P;
typedef vector<int> VI;
const int INF=1E9+7;
template<class C> void mini(C&a4, C b4) { a4 = in(a4, b4); }

int h, w, m;
#define maxn 55
bool t[maxn][maxn];
bool t2[maxn][maxn];
void odw() {
    fup(i, 1, h) fup(j, 1, w) t2[j][i] = t[i][j];
    swap(h, w);
    fup(i, 1, h) fup(j, 1, w) t[i][j] = t2[i][j];
}

void wypisz() {
    fup(i, 1, h) {
        fup(j, 1, w) {
            char c;
            if (t[i][j] == 0) c = '.';
            else c = '*';
            if (i == 1 && j == 1) c = 'c';
                printf("%c", c);
        }
        printf("\n");
    }
}
bool jest = 0;
int main(){
    int cas;
    cin >> cas;
    fup(c, 1, cas) {
        cin >> h >> w >> m;
        m = h * w - m;
        //cout << h << " " << w << " " << m << endl;
        bool swp = 0;
        if (h > w) {
            swap(h, w);
            swp = 1;
        }
        jest = 0;
        fup(i, 1, h) fup(j, 1, w) t[i][j] = 1;

        printf("Case #%d:\n", c);
        if (m == 1) {
            t[1][1] = 0;
            jest = 1;
        }
        else if (h == 1) {
            ///cout << m << endl;
            fup(i, 1, m) {
                t[1][i] = 0;
            } 
            //cout << t[1][3] << endl;
            jest = 1;
        }
        else if (h == 2 || m == 4) {
            if (m % 2 == 0 && m >= 4) {
                jest = 1;
                fup(i, 1, m / 2) t[1][i] = t[2][i] = 0;
            }
        }
        else {
            if (m % 2 && m >= 9) {
                jest = 1;
                fup(i, 1, 3) fup(j, 1, 3) t[i][j] = 0;
                m -= 9;
                m /= 2;
                fup(i, 4, h) if (m) t[i][1] = t[i][2] = 0, m--;
                fup(i, 4, w) if (m) t[1][i] = t[2][i] = 0, m--;
                m *= 2;
                fup(i, 4, h) if (m) t[i][3] = 0, m--;
                fup(i, 3, h) fup(j, 4, w) if (m) t[i][j] = 0, m--;
            }
            else if (m % 2 == 0 && m > 2) {
                jest = 1;
                fup(i, 1, 2) fup(j, 1, 2) t[i][j] = 0;
                m -= 4;
                m /= 2;
                fup(i, 3, w) if (m) t[1][i] = t[2][i] = 0, m--;
                fup(i, 3, h) if (m) t[i][1] = t[i][2] = 0, m--;
                m *= 2;
                fup(i, 3, h) fup(j, 3, w) if (m) t[i][j] = 0, m--;
            }
        }

        if (swp) {
            odw();
        }
        if (jest) 
            wypisz();
        else printf("Impossible\n");
    }


    return 0;
}

