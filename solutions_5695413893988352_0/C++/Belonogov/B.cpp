#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 100;
const long long INF = 1e18 + 19;

string s, t;

void read() {
    cin >> s >> t;
}

long long diff, ra, rb;
int a[N]; // s;
int b[N]; // t
string r1, r2;
int n;

void upd() {
    long long aa = 0, bb = 0;
    for (int i = 0; i < n; i++) {
        aa = aa * 10 + a[i];
        bb = bb * 10 + b[i];
    }
    //db(abs(aa - bb));
    if (diff > abs(aa - bb) || (diff == abs(aa - bb) && (ra > aa || (ra == aa && rb > bb)))) {
        diff = abs(aa - bb);
        ra = aa;
        rb = bb;
        r1 = r2 = "";
        for (int i = 0; i < n; i++) {
            r1 += '0' + a[i];
            r2 += '0' + b[i];
        }
    }
 

}

void solve() {
    diff = INF;
    ra = INF;
    rb = INF;
    n = s.size();
    for (int tt = 0; tt < 2; tt++) {
        bool flag = 1;
        for (int i = 0; i < n; i++)
            flag &= (s[i] == t[i] || s[i] == '?' || t[i] == '?');
        if (flag) {
            diff = 0;
            for (int i = 0; i < n; i++) {
                int ch = 0;
                if (s[i] != '?') ch = s[i] - '0';
                if (t[i] != '?') ch = t[i] - '0';
                a[i] = ch;
                b[i] = ch;
            }
            upd();
        }

        for (int i = 0; i < n; i++) {
            memset(a, -1, sizeof(a));
            memset(b, -1, sizeof(b));
            for (int j = 0; j < n; j++) {
                a[j] = b[j] = 0;
            }
            for (int j = 0; j < n; j++) {
                if (s[j] != '?') a[j] = s[j] - '0';
                if (t[j] != '?') b[j] = t[j] - '0';
            }

            if (s[i] == '?' && t[i] == '?') {
                a[i] = 1;
                b[i] = 0;
            }   
            if (s[i] == '?' && t[i] != '?') 
                a[i] = min(9, b[i] + 1);
            if (s[i] != '?' && t[i] == '?') 
                b[i] = max(0, a[i] - 1);

            for (int j = 0; j < i; j++) {
                if (s[j] == '?')
                    a[j] = b[j];
                if (t[j] == '?')
                    b[j] = a[j];
            }
            for (int j = i + 1; j < n; j++) {
                if (s[j] == '?')
                    a[j] = 0;
                if (t[j] == '?')
                    b[j] = 9;
            }
            upd();
        }

        swap(s, t);
        swap(r1, r2);
    }

    //{
        //int pw = 1;
        //for (int i = 0; i < n; i++)
            //pw *= 10;
        //int bestDiff = 1000;
        //int bestA = -1;
        //int bestB = -1;
        //string sa, sb;
        //for (int x = 0; x < pw; x++)
            //for (int y = 0; y < pw; y++) {
                //vector < int > xx;
                //vector < int > yy;
                //int x1 = x;
                //for (int i = 0; i < n; i++, x1 /= 10)
                    //xx.pb(x1 % 10);
                //reverse(xx.begin(), xx.end());
                //int y1 = y;
                //for (int i = 0; i < n; i++, y1 /= 10)
                    //yy.pb(y1 % 10);
                //reverse(yy.begin(), yy.end());

                //bool flag = 1;
                //for (int i = 0; i < n; i++)
                    //if (s[i] != '?')
                        //flag &= s[i] - '0' == xx[i];
                //for (int i = 0; i < n; i++)
                    //if (t[i] != '?')
                        //flag &= t[i] - '0' == yy[i];

                ////db(flag);
                //if (flag) {
                    //if (abs(x - y) < bestDiff|| (abs(x - y) == bestDiff && (bestA > x || (bestA == x && bestB > y)))) {
                        //bestDiff = abs(x - y);
                        //bestA = x;
                        //bestB = y;
                        //sa = "";
                        //sb = "";
                        //for (int i = 0; i < n; i++) {
                            //sa += '0' + xx[i];
                            //sb += '0' + yy[i];
                        //}
                    //}
                //}
            //}
        ////db(bestDiff);
        ////db2(s, t);
        ////db2(sa, r1);
        ////db2(sb, r2);
        //assert(sa == r1 && sb == r2);
        //db("OK");
    //}
    

    cout << r1 << " " << r2 << endl;
}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        scanf("%d", &k);
        for (int tt = 0; tt < k; tt++) {
            printf("Case #%d: ", tt + 1);
            read();
            solve();
        }
    }
    else {
        stress();
    }

    return 0;
}

