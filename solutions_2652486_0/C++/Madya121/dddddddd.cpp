// INCLUDE LIST
#include <cstdio>
#include <bitset>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <list>
#include <vector>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;

// DEFINE LIST
#define REP(_I, _J, _K) for(_I = (_J) ; _I < (_K) ; _I++)
#define input(_A)       freopen(_A, "r", stdin);
#define output(_A)      freopen(_A, "w", stdout);
#define INPUT           input("in.txt");
#define OUTPUT          output("out.txt");
#define hold            {fflush(stdin); getchar();}
#define reset(_A, _B)   memset((_A), (_B), sizeof (_A));
#define debug           printf("<<TEST>>\n");
#define eps             1e-11
#define f_cmp(_A, _B)   (fabs((_A) - (_B)) < eps)
#define phi             acos(-1)
#define pb              push_back
#define value(_A)       cout << "Variabel -> " << #_A << " -> " << _A << endl;
#define st              first
#define nd              second

// TYPEDEF LIST
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef long long       LL;

// VAR LIST
int MAX =               1000000;
int MIN =               -1000000;
int INF =               1000000000;
int x4[4] =             {0, 1, 0, -1};
int y4[4] =             {1, 0, -1, 0};
int x8[8] =             {0, 1, 1,  1,  0, -1, -1, -1};
int y8[8] =             {1, 1, 0, -1, -1, -1,  0,  1};
int i, j, k;

// MAIN CODE
int main () {
    input("C-small-1-attempt0.in");
    OUTPUT;
    int t, r, n, m, k, kasus = 0, arr[100];
    bool bisa, ada;
    cin >> t;
    while(t--) {
        cin >> r >> n >> m >> k;
        cout << "Case #" << ++kasus << ":" << endl;
        REP(i, 0, r) {
            ada = false;
            REP(j, 0, k) cin >> arr[j];
            int a, b, c, z, S;
            for(a=2;a<=m;a++) {
                for(b=2;b<=m;b++) {
                    for(c=2;c<=m;c++) {
                        int bil[5];
                        bool visit[50];
                        reset(visit, false);
                        bisa = true;
                        bil[0] = a;
                        bil[1] = b;
                        bil[2] = c;
                        int mask = (1 << 3), ret;
                        for(z=0;z<mask;z++) {
                            ret = 1;
                            for(S=0;S<3;S++) {
                                if ((z & (1 << S)) > 0)
                                    ret *= bil[S];
                            }
                            for(S=0;S<k;S++) {
                                if (arr[S] == ret)
                                    visit[S] = true;
                            }
                        }
                        for(z=0;z<k;z++) {
                            if (visit[z] == false)
                                bisa = false;
                        }
                        if (bisa) {
                            cout << bil[0] << bil[1] << bil[2] << endl;
                            ada = true;
                            goto hell;
                        }
                    }
                }
            }
            hell:
            if (!ada) cout << "111" << endl;
        }
    }
    return 0;
}

// VINCENTIUS MADYA
// DARKSTALKER
// LANGUAGE : C++
