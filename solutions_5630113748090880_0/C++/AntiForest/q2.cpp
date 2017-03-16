#include <bits/stdc++.h>

#define INF 1000000010
#define FO(i,a,b) for (int (i) = (a); (i) < (b); ++(i))
#define sz(v) int(v.size())

using namespace std;
//PAIRS:
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pii;
typedef long long ll;

/*~~~~TEMPLATE END~~~~*/

int T, N;
int am[2505];

int main() {
    scanf ("%d", &T);
    FO (_z,1,T+1) {
        printf ("Case #%d: ", _z);
        scanf ("%d", &N);
        memset (am, 0, sizeof(am));
        FO (i,0,2*N-1) {
            FO (p,0,N) {
                int _c;
                scanf ("%d", &_c);
                am[_c]++;
            }
        }
        FO (i,0,2505) {
            if (am[i] % 2) {
                printf ("%d ", i);
            }
        }
        printf ("\n");
    }
    return 0;
}
