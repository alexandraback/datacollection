#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <iomanip>
using namespace std;

typedef long long LL;

const int MAXN = 20;

LL dp[MAXN][10][10];
LL MC[MAXN][10][10];
LL MJ[MAXN][10][10];

void update(int i, int lc, int lj, int nc, int nj, LL power) {
    LL& a = dp[i + 1][nc][nj];
    LL& b = dp[i][lc][lj];
    LL& ac = MC[i + 1][nc][nj];
    LL& bc = MC[i][lc][lj];
    LL& aj = MJ[i + 1][nc][nj];
    LL& bj = MJ[i][lc][lj];
    
    LL extrac = bc + nc * power;
    LL extraj = bj + nj * power;
    LL extra = abs(extrac - extraj);
    if (a == -1 || a > extra || (a == extra && ( (ac > extrac || (ac == extrac && aj > extraj))))) {
        a =  extra;
        ac = extrac;
        aj = extraj;
        //cout << i << " " << lc << " " << lj << " " << nc << " " << nj << " " << a << endl;
        //cout << dp[i + 1][nc][nj];
    }
}

int main() {
   int cases; cin >> cases;
   for (int tc = 1; tc <= cases; tc ++) {
       string C, J; 
       cin >> C >> J;
        int len = C.size();
        LL power[20];
        power[0] = 1;
        for (int i = 1; i <= len ; i ++)
            power[i] = power[i-1] * 10;
       
        int ret = -1;
        int retc = -1;
        int retj = -1;
        for (int i = 0; i < power[len]; i ++)
           for (int j = 0; j < power[len]; j ++) {
               bool ok = true;
                for (int k = 0; k < len; k ++) {
                    if (C[k] != '?' && C[k] - '0' != i / power[len -k -1] % 10) ok = false;
                    if (J[k] != '?' && J[k] - '0' != j / power[len - k - 1] % 10) ok = false;
                    if (!ok) break;
                } 
                if (ok) {
                    int x = abs(i - j);
                    if (ret == -1 || ret > x || (ret == x && (retc > i ||( retc == i &&  retj > j)))) {
                        ret = x;
                        retc = i;
                        retj = j;
                    }
                }
           }
        cout << "Case #" << tc << ": " <<  std::setw(len) << std::setfill('0') <<  retc << " " <<std::setw(len) << std::setfill('0') << retj << endl;
   }

}
