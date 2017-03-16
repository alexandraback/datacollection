#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>
#include <cmath>
#include <ctime>
#include <memory.h>

#define WR printf
#define RE scanf
#define PB push_back
#define SE second
#define FI first
#define MP make_pair

#define FOR(i,Be,En) for(int (i)=(Be);(i)<=(En);++(i))
#define DFOR(i,Be,En) for(int (i)=(Be);(i)>=(En);--(i))
#define SZ(a) (int)((a).size())
#define FA(i,v) FOR(i,0,SZ(v)-1)
#define RFA(i,v) DFOR(i,SZ(v)-1,0)
#define CLR(a) memset(a,0,sizeof(a))

#define LL  long long
#define VI  vector<int>
#define PAR pair<int ,int> 

using namespace std;
void __never(int a){printf("\nOPS %d", a);}
void __die(int a){printf("%d",(a*a)/(a+a));}
#define ass(s) {if (!(s)) {__never(__LINE__);cout.flush();cerr.flush();__die(0);}}


#define MAXL 10050

//1 - 1
//2 - 'i'
//3 - 'j'
//4 - 'k'

int prod_t[5][5] = 
{ 0, 0, 0, 0, 0,
  0, 1, 2, 3, 4,
  0, 2,-1, 4,-3,
  0, 3,-4,-1, 2,
  0, 4, 3,-2,-1
};

int pow_t[5][4];

inline int prod(int a, int b) {
    if (a < 0) {
        if (b < 0) return prod_t[-a][-b];
        return -prod_t[-a][b];
    }
    if (b < 0) return -prod_t[a][-b];
    return prod_t[a][b];
}

inline int pow(int a, int p) {
    ass(p < 4);
    ass(a != 0 && a <= 4 && a >= -4);
    if (a < 0) {
        if (p & 1) {
            return -pow_t[-a][p];
        }
        return pow_t[-a][p];
    }
    return pow_t[a][p];
}

inline int code(char c) {
    if (c == 'i') return 2;
    if (c == 'j') return 3;
    if (c == 'k') return 4;
    ass(false);
    return 0;
}

void initPow() {
    FOR(i,1,4) {
        pow_t[i][0] = 1;
        FOR(j,1,3) pow_t[i][j] = prod(pow_t[i][j-1], i);
    }
}


int findLeft(int b, int res) {
    int ans = 0;
    FOR(a,-4,4) {
        if (a == 0) continue;
        if (prod(a,b)==res) {
            ass(ans == 0);
            ans = a;
        }
    }
    return ans;
}

int findRight(int a, int res) {
    int ans = 0;
    FOR(b,-4,4) {
        if (b == 0) continue;
        if (prod(a,b)==res) {
            ass(ans == 0);
            ans = b;
        }
    }
    return ans;
}

void init()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("c.out","w",stdout);
}



int c[MAXL];

int pref[MAXL];
int suff[MAXL];

void selfTest() {
    FOR(i,-4,4) FOR(j,-4,4) {
        if (i * j == 0) continue;
        cout << findLeft(i,j) << " " << i << " " << j << "\n";
        cout << i << " " << findRight(i,j) << " " << j << "\n";
    }
}

int range(int i, int j) {
    int A = findRight(pref[i-1],pref[j]);
    int B = findLeft(suff[j+1],suff[i]);
    ass(A == B);
    return A;
}

bool sol(int L, int X){	
    pref[0] = 1;
    FOR(i,1,L) pref[i] = prod(pref[i-1], c[i]);
    suff[L+1] = 1;
    DFOR(i,L,1) suff[i] = prod(c[i], suff[i+1]);
    
    if (X == 1) {
        FOR(i,1,L-2) {
            if (pref[i] != 2) continue;
            FOR(j,i+1,L-1) {
                if (suff[j+1] == 4 && range(i+1,j) == 3) {
                    return true;
                }
            }
        }
        return false;
    }
    
    FOR(i,1,L+1) FOR(j,0,L) {
        FOR(p0,0,3) FOR(p1,0,3) {
            int p2 = X - p0 - p1 - 2;
            if (p2 < 0) continue;
            p2 %= 4;
            if (prod(pow(pref[L], p0), pref[i-1]) == 2)
                if (prod(prod(suff[i], pow(pref[L], p1)), pref[j] ) == 3)
                    if (prod(suff[j+1], pow(pref[L], p2)) == 4) {
                        return true;
                    }
        }
    }
    return false;
}
int main()
{
	init();
    //selfTest();
    initPow();
    int T;
    cin >> T;
    LL X;
    int L;
    string s;
    FOR(t,1,T) {
        cin >> L >> X;
        ass(X > 0);
        if (X > 100) {
            X = (X % 4) + 100;
        }
        cin >> s;
        ass(SZ(s) == L);
        ass(L < MAXL);
        FOR(i,1,L) c[i] = code(s[i-1]);
        cout << "Case #" << t << ": " << (sol(L, (int)X) ? "YES" : "NO") << std::endl;
    }
	return 0;
}