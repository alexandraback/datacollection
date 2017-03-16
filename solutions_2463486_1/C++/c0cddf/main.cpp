#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <cassert>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

#define ll long long
#define point pair<double, double>
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define uint unsigned int
#define double long double
#define merge botva
#define M_PI 3.14159265358979323846

const int maxn = 120, maxt = 100020, INF = 1200000000;

int gi;

#define big pair<int, string>
#define mp make_pair
#define y second

int n, m, minf;
int fr[maxn], fc[maxn], a[maxn][maxn];

big operator+ (const big& a, const big& b) {
        big c;
        if (a.y.size() > b.y.size()) {return b + a; }
        c.y = b.y;
        c.y.push_back('0');
        for (int i = 0; i < a.y.size(); ++i) {
                c.y[i] += a.y[i] - '0';
                while (c.y[i] > '9') c.y[i] -= 10, ++c.y[i + 1];
        }
        while (c.y.size() && c.y[c.y.size() - 1] == '0') c.y.resize(c.y.size() - 1);
        return c;
}

big operator* (const big& a, const big& b) {
        big c;
        c.y.resize(a.y.size() + b.y.size());
        int z = 0;
        for (int i = 0; i < c.y.size(); ++i) {
                for (int j = 0; j <= i; ++j)
                        if (j < a.y.size() && i - j < b.y.size()) {
                                //if (a.y[i] < '0') {cout << "!!!\n"; exit(0);}
                                //if (b.y[i - j] < '0') {cout << "??\n"; exit(0);}
                                z += (a.y[j] - '0') * (b.y[i - j] - '0');
                                
                        }
                //if (z < 0) {cout << "CAGE !\n"; exit(0); }
                c.y[i] = '0';
                c.y[i] += (z % 10);
                z /= 10;
        }
        while (c.y.size() && c.y[c.y.size() - 1] == '0') c.y.resize(c.y.size() - 1);
        return c;
}

bool sm (const big& a, const big& b) {
        if (a.y.size() == b.y.size()) {
                for (int j = a.y.size() - 1; j >= 0; --j)
                        if (a.y[j] != b.y[j])
                                return a.y[j] <= b.y[j];
                return 1;
        } else return a.y.size() <= b.y.size();
}

int va, vb;
big me, down, up;
int ans = 0;

vector<big> vans;

void per(int i) {
        //cout << me.y << endl;
        int bad;
        if (i <= va - i - 1) {
                big ze;
                for (int j = (i == 0); j <= 9; ++j) {
                        me.y[i] = me.y[va - i - 1] = '0' + j;
                        big ze = me * me;
                        bad = 0;
                        for (int j = 0; j < ze.y.size(); ++j)
                                if (ze.y[j] != ze.y[ze.y.size() - j - 1]) {bad = 1; break;}
                        if (bad) continue;
                        per(i + 1);
                }
                me.y[i] = me.y[va - i - 1] = '0';
        } else {
                //cout << "i is " << i << endl;
                //if (down <= me * me && me * me <= up)
                vans.push_back(me * me);
                        //++ans;//, cout << me.y << endl;
        }
}

int main() {
        //freopen("ellipse.in", "r", stdin);
        //freopen("ellipse.out", "w", stdout);

        int t;
                for (va = 1; va <= 51; ++va) {
                        me.y.assign(va, '0');
                        per(0);
                        
                }
        sort(vans.begin(), vans.end(), sm);
        //for (int i = 0; i < 50; ++i)
        //        cout << vans[i].y << endl;
                
        //cout << ans << endl;
        //return 0;
        scanf("%d\n", &t);
         
        for (gi = 1; gi <= t; ++gi) {
                string s1, s2;
                cin >> s1 >> s2;
                reverse(s1.begin(), s1.end());
                reverse(s2.begin(), s2.end());
                down = mp(0, s1), up = mp(0, s2);
                ans = 0;
                
                for (int j = 0; j < vans.size(); ++j) {
                        if (!sm(vans[j], up)) break;
                        if (sm(down, vans[j]))
                                ++ans;
                }
                cout << "Case #" << gi << ": " << ans << endl;
        }
}
