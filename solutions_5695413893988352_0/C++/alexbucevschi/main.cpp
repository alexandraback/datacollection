#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ll long long
#define pii pair<int,int>
#define tii tuple <int,int,int>
#define N 200005
#define mod 1000000005
#define X first
#define Y second
#define eps 0.0000000001
#define all(x) x.begin(),x.end()
#define tot(x) x+1,x+n+1
using namespace std;

int t, T, n, i, ok, dif, s1, s2;
char c[N], j[N];
set<pair<int, string>>cc, jj;
string sol1, sol2;
void bak(char s[N], int k) {
    int x;

    if(k == n) {
        x = atoi(s);
        stringstream ss;
        string t;
        ss << s;
        ss >> t;
        cc.insert(mp(x, t));
        return;
    }

    char q;

    if(s[k] != '?')
        bak(s, k + 1);
    else
        for(q = '0'; q <= '9'; q++) {
            s[k] = q;
            bak(s, k + 1);
            s[k]='?';
        }
}
void bak1(char s[N], int k) {
    int x;

    if(k == n) {
        x = atoi(s);
        stringstream ss;
        string t;
        ss << s;
        ss >> t;
        jj.insert(mp(x, t));
        return;
    }

    char q;

    if(s[k] != '?')
        bak1(s, k + 1);
    else
        for(q = '0'; q <= '9'; q++) {
            s[k] = q;
            bak1(s, k + 1);
            s[k]='?';
        }
}
int abs(int x, int y) {
    return max(x - y, y - x);
}
int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    scanf("%d", &T);

    for(t = 1; t <= T; t++) {
        printf("Case #%d: ", t);
        scanf("%s", &c);
        scanf("%s", &j);
        n = strlen(c);
        cc.clear();
        jj.clear();
        sol1.clear();
        sol2.clear();
        dif = 100000;
        s1 = 100000;
        s2 = 100000;
        bak(c, 0);
        bak1(j, 0);

        for(auto it : cc)
            for(auto jt : jj) {
                if(dif == abs(jt.X - it.X)) {
                    if(s1 == it.X) {
                        if(s2 > jt.X) {
                            s2 = jt.X;
                            sol2 = jt.Y;
                        }
                    }

                    if(s1 > it.X) {
                        s1 = it.X;
                        s2 = jt.X;
                        sol1 = it.Y;
                        sol2 = jt.Y;
                    }
                }

                if(dif > abs(jt.X - it.X)) {
                    dif = abs(jt.X - it.X);
                    s1 = it.X;
                    s2 = jt.X;
                    sol1 = it.Y;
                    sol2 = jt.Y;
                }
            }

        printf("%s %s\n", sol1.c_str(), sol2.c_str());
    }

    return 0;
}
