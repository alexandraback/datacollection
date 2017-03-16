#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <assert.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;
#define PB push_back
#define MP make_pair
typedef long long LL;
typedef pair<int,int> PII;
#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)
#define inf (1<<30)
const int N = 10005;
short mul[5][5];
short from_left[N], from_right[N];
short dp[10];
short v[N][N];
short get(char x)
{
    if (x == 'i')
        return 2;
    else if (x == 'j')
        return 3;
    else
        return 4;
}
short cal(short x, short y)
{
    short sign1 = (x > 0?1 : -1);
    short sign2 = (y > 0?1 : -1);
    x *= sign1;
    y *= sign2;
    return mul[x][y] * sign1 * sign2;
}
bool valid(int x, int y, int z, LL tot)
{
    int cnt = x + y + z + 2;
    if (y == 0)
        cnt--;
    
    return cnt <= tot && cnt % 4 == tot % 4;
}
string gao(LL l, LL tot)
{
    if (l * tot < 3)
        return "NO";
    //cout << "l=" << l << endl;
    for (int x = 0; x < 4; x++) {
        //cout << "x="<<x<<endl;
        for (int i = 1; i <= l; i++) {
            //cout << " dp[x]=" << dp[x] << " v[1][i]=" << v[1][i] << endl;
            if (cal(dp[x], v[1][i]) != 2) {
                continue;
            }
            //cout << "x = " << x << " i = " << i << endl;
            for (int y = 0; y < 4; y++) {
                for (int j = 1; j <= l; j++) {
                    bool ok = true;
                    /*if (y == 1) {
                        cout << "i=" << i << " l=" << l << endl;
                        cout << "v[i+1][l]=" << v[i+1][l] << " dp[y]=" << dp[y] << " v[1][j-1]=" << v[1][j-1] << endl;
                    }*/
                    if (y > 0 && cal(cal(v[i+1][l], dp[y]), v[1][j-1]) != 3) {
                        ok = false;
                    }
                    if (y == 0) {
                        if (j <= i + 1 || v[i+1][j-1] != 3) {
                            ok = false;
                        }
                    }
                    if (ok == false)
                        continue;
                    for (int z = 0; z < 4; z++) {
                       // cout << "x= " << x << " y= " << y << " z= " << z << endl;
                        //cout << "i= " << i << " j= " << j << endl;
                        short t = cal(v[j][l], dp[z]);
                        //cout << "i=" << i << " j=" << j << endl;
                        //cout << "t=" << t << endl;
                        if (t == 4 && valid(x, y, z, tot)) {
                            //cout << x << " " << y << " " <<  z << " " << i << " " << j << endl;
                            return "YES";
                        }
                    }
                }
            }
        }
    }
    return "NO";
}
string brute(string s, LL l, LL x)
{
    string p = s;
    for (int i = 0; i < x - 1; i++)
        s += p;
    for (int i = 0; i < s.length(); i++) {
        for (int j = i + 1; j + 1 < s.length(); j++) {
            //0->i, i + 1 -> j, j + 1 -> s.l
            short now = 1;
            bool ok = true;
            for (int k = 0; k <= i; k++) {
                now = cal(now, get(s[k]));
            }
            if (now != 2)
                ok = false;
            now = 1;
            for (int k = i + 1; k <= j; k++) {
                now = cal(now, get(s[k]));
            }
            if (now != 3)
                ok = false;
            now = 1;
            for (int k = j + 1; k < s.length(); k++) {
                now = cal(now, get(s[k]));
            }
            if (now != 4)
                ok = false;
            if (ok) {
                cout << i << " " << j << endl;
                return "YES";
            }
        }
    }
    return "NO";
}
short sol(int l, int r, string &s)
{
    short now = 1;
    for (int i = l; i <= r; i++) {
        now = cal(now, get(s[i]));
    }
    return now;
}
int main()
{
    freopen("/Users/junchen/topcoder/tc/tc/A-small-attempt0.in", "r", stdin);
    freopen("/Users/junchen/topcoder/tc/tc/x1.out", "w", stdout);
    mul[1][1] = 1;
    mul[1][2] = 2;
    mul[1][3] = 3;
    mul[1][4] = 4;

    mul[2][1] = 2;
    mul[2][2] = -1;
    mul[2][3] = 4;
    mul[2][4] = -3;
    
    mul[3][1] = 3;
    mul[3][2] = -4;
    mul[3][3] = -1;
    mul[3][4] = 2;
    
    mul[4][1] = 4;
    mul[4][2] = 3;
    mul[4][3] = -2;
    mul[4][4] = -1;
    
    int T;
    cin >> T;
    //cout << T << endl;
    LL l, x;
    string str;
    for (int ca = 1; ca <= T; ca++) {
        cin >> l >> x;
        cin >> str;
        //cout << l << " " << x << " " << str << endl;
        /*from_left[0] = 1;
        from_right[l+1] = 1;
        for (int j = 1; j <= l; j++) {
            from_left[j] = cal(from_left[j-1], get(str[j-1]));
        }
        for (int j = l; j > 0; j--) {
            from_right[j] = cal(from_right[j+1], get(str[j]));
        }*/
        string ss = "";
        for (int i = 0; i < x; i++) {
            ss += str;
        }
        string res = "NO";
        for (int i = 1; i <= ss.length(); i++) {
            v[i][i-1] = 1;
            v[i][0] = 1;
            v[i+1][l] = 1;
            for (int j = i; j <= ss.length(); j++) {
                v[i][j] = cal(v[i][j-1], get(ss[j-1]));
            }
        }
        //cout << v[1][1] << " " << v[2][2] << v[3][3] << endl;
        for (int i = 1; i <= ss.length() && res == "NO"; i++) {
            if (v[1][i] != 2)
                continue;
            for (int j = i+1; j + 1 <= ss.length() && res == "NO"; j++) {
                if (v[1][i] == 2 && v[i+1][j] == 3 && v[j+1][ss.length()] == 4)
                    res = "YES";
            }
        }
        printf("Case #%d: %s\n", ca, res.c_str());
/*
        for (int i = 1; i <= l; i++) {
            v[i][i-1] = 1;
            v[i][0] = 1;
            v[i+1][l] = 1;
            for (int j = i; j <= l; j++) {
                v[i][j] = cal(v[i][j-1], get(str[j-1]));
            }
        }
        v[l+1][l] = 1;
        //cout << v[2][5] << " " << v[1][5] << endl;
        dp[0] = 1;
        for (int i = 1; i <= 3; i++) {
            dp[i] = cal(dp[i-1], v[1][l]);
        }
        //printf("%s\n", brute(str, l, x).c_str());
        printf("Case #%d: %s\n", ca, gao(l, x).c_str());*/
    }
}
/*
2
2 6
ji
 5 1927
 kjiii

*/