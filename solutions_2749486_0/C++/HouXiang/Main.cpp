#include <assert.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <list>
#include <string>
#include <queue>
#include <algorithm>
#include <time.h>
#include <utility>
#include <numeric>

using namespace std;

////////////////////////////////////////////////////
// bign
////////////////////////////////////////////////////
struct bign {
    static const int maxn = 1000; 
    int len, s[maxn]; 
    
    bign() { 
        memset(s, 0, sizeof(s)); 
        len = 1; 
    }

    bign(int num) {
        *this = num; 
    }

    bign(const char* num) {
        *this = num;
    }

    bign operator = (const char* num) {
        len = strlen(num); 
        for (int i=0; i<len; i++)
            s[i] = num[len-i-1] - '0'; 
        return *this; 
    }

    bign operator = (int num) {
        char s[maxn]; 
        sprintf(s, "%d", num); 
        *this = s; 
        return *this; 
    }

    string str() const {
        string res = "";
        for (int i=0; i<len; i++)
            res = (char)(s[i] + '0') + res; 
        if (res == "") res = "0";
        return res; 
    }
};

istream& operator >> (istream &in, bign& x) {
    string s; 
    in >> s; 
    x = s.c_str(); 
    return in;
}

ostream& operator << (ostream &out, const bign& x) {
    out << x.str(); 
    return out; 
}

bign operator + (const bign& a, const bign& b) {
    bign c; 
    c.len = 0; 
    for (int i=0, g=0; g || i < max(a.len, b.len); i++) {
        int x = g; 
        if (i<a.len) x += a.s[i]; 
        if (i<b.len) x += b.s[i]; 
        c.s[c.len++] = x % 10; 
        g = x / 10; 
    }
    return c; 
}

bool operator < (const bign& a, const bign& b) {
    if (a.len != b.len) return a.len < b.len; 
    for (int i= a.len-1; i>=0; i--) {
        if (a.s[i] != b.s[i]) return a.s[i] < b.s[i]; 
    }
    return false; 
}

bool operator > (const bign& a, const bign& b) { return b < a; }

bool operator <= (const bign& a, const bign& b) { return !(b < a); }

bool operator >= (const bign& a, const bign& b) { return !(a < b); }

bool operator != (const bign& a, const bign& b) { return a<b || b<a; }

bool operator == (const bign& a, const bign& b) { return !(a<b) && !(b<a); }

///////////////////////////////////////////////////////

bool is_prime(int x) {
    int i; 
    for (i=2; i*i<=x; i++) 
        if (x % i == 0) return false;
    return true; 
}

int vis[1000] = {0}; 
void getPrimes(int n, vector<int> &v) {
    memset(vis, 0, sizeof(vis)); 
    int m = sqrt(n+0.5); 
    int c = 0; 
    for (int i=2; i<=m; i++) {
        if (!vis[i]) {
            for (int j=i*i; j<=n; j+=i)
                vis[j] = 1; 
        }
    }

    for (int i=2; i<=n; i++) {
        if (vis[i] == 0) v.push_back(i); 
    }
}

double random() { return (double)rand() / RAND_MAX; }
// random in [m1, m2]
int random(int m1, int m2) {
    return m1 + (int)(random() * (m2 - m1) + 0.5);
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b); 
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b; 
}

int C[10000][10000]; 
void buildC(int n) {
    memset(C, 0, sizeof(C)); 
    C[0][0] = 1; 
    for (int i=1; i<=n; i++) {
        C[i][0] = 1; 
        for (int j=1; j<=n; j++)
            C[i][j] = C[i-1][j-1] + C[i-1][j]; 
    }
}

int P[1000] = {0}; 
void getP(int n, vector<int> &v) {
    if (v.size() == n) {
        for (int i=0; i<n; i++) {
            cout << v[i] << " "; 
        }
        cout << endl; 
    }
    for (int i=1; i<=n; i++) {
        if (P[i] == 0) {
            P[i] = 1; 
            v.push_back(i); 
            getP(n, v); 
            v.erase(v.end() - 1); 
            P[i] = 0; 
        }
    }
}

void getSet(int n, vector< vector<int> > &v) {
    v.push_back(vector<int>()); 
    for (int i=1; i<=n; i++) {
        int n = v.size(); 
        for (int j=0; j<n; j++) {
            vector<int> tv = v[j]; 
            tv.push_back(i); 
            v.push_back(tv); 
        }
    }
}

typedef long long ll; 

struct Rec {
    string str; 
    __int64 n; 

    Rec():n(-1) {}
};

Rec a[500][500]; 

bool getSolution(int x, int y, string& str, int n, int dx, int dy) {
    if (n > 500) 
        return false;

    /*
    if (abs(x) > abs(dx) || abs(y) > abs(dy))
        return false;
    */

    if (x == dx && y == dy) 
        return true;

    if (n >0) {
        if (a[x+100][y+100].n < 0) {
            a[x+100][y+100].n = n; 
        }
        else {
            if (a[x+100][y+100].n > n) {
                a[x+100][y+100].n = n;
            }
            else {
                return false;
            }
        }
        
    }
    

    n++; 
    string tr = ""; 

    // e
    {
    if (getSolution(x + n, y, tr, n, dx, dy)) {
        str = "E";
        str.append(tr);
        return true;
    }
    }

    // w
    if (getSolution(x - n, y, tr, n, dx, dy)) {
        str = "W";
        str.append(tr);
        return true;
    }
    // s
    if (getSolution(x, y-n, tr, n, dx, dy)) {
        str = "S";
        str.append(tr);
        return true;
    }
    // n
    if (getSolution(x, y+n, tr, n, dx, dy)) {
        str = "N";
        str.append(tr);
        return true;
    }
        
    return false;
}



//////////////////////////////////////////////////////
int main(int argc, char* argv[]) {
    srand(time(0));

    ifstream inf(argv[1]);

    string ln;  
    inf >> ln;

    int number = atoi(ln.c_str());

    for (int cases=0; cases<number; cases++) 
    {
        int x, y; 
        inf >> x >> y; 

        string res; 
        /*
        getSolution(0, 0, res, 0, x, y); 
        
        for (int i=0; i<500; i++) {
            for (int j=0; j<=500; j++) {
                a[i][j].n = -1; 
            }
        }
        */

        if (x > 0) {
            for (int i=0; i<2*x-1; i++) {
                if (i % 2 == 0) {
                    res = res + "E"; 
                }
                else {
                    res = res + "W"; 
                }
            }
        }
        else {
            for (int i=0; i<2*abs(x)-1; i++) {
                if (i % 2 == 0) {
                    res = res + "W"; 
                }
                else {
                    res = res + "E"; 
                }
            }
        }

        if (y > 0) {
            for (int i=0; i<y; i++) {
                res += "S"; 
                res += "N"; 
            }
        }
        else {
            for (int i=0; i<abs(y); i++) {
                res += "N"; 
                res += "S"; 
            }
        }

        // print result
        cout << "Case #" << (cases + 1) << ": " << res << endl;
    }

    return 0;
}