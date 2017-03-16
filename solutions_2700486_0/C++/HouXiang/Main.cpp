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

__int64 C[10000][10000]; 
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

//////////////////////////////////////////////////////

int main(int argc, char* argv[]) {
    srand(time(0));

    if (argc != 2) {
        cerr << "wrong number of parameter" << endl;
        return -1;
    }

    ifstream inf(argv[1]);
    if (!inf) {
        cerr << "cannot open file " << argv[1] << endl;
        return -1;
    }

    string ln;  
    inf >> ln;

    int number = atoi(ln.c_str());

    buildC(10000);

    for (int cases=0; cases<number; cases++) 
    {
        int n = 0; 
        inf >> ln; n = atoi(ln.c_str()); 
        int x = 0, y = 0; 
        inf >> ln; x = atoi(ln.c_str()); 
        inf >> ln; y = atoi(ln.c_str()); 

        int m = 1;
        __int64 dNum = 1; 
        while (dNum <= n) {
            m += 2; 
            dNum = (m+1) * m / 2; 
        }

        m -= 2; 
        dNum = (m+1) * m / 2; 

        int left = n - dNum; 

        double resRate = 0; 
        bool bFinish = false; 

        

        // (x, y) included?
        if (y <= (m-1)) {
            if (y % 2 == 0) {
                // even 
                if (abs(x) % 2 == 0 && abs(x) <= ((m - 1) - y * 2)) {
                    resRate = 1; 
                    bFinish = true; 
                }
                else {
                    if (abs(x) % 2 == 1) {
                        resRate = 0;
                        bFinish = true;
                    }
                    else if (abs(x) - ((m - 1) - y * 2) > 2) {
                        resRate = 0; 
                        bFinish = true; 
                    }
                }
            }
            else {
                // odd 
                if (abs(x) % 2 == 1 && abs(x) <= ((m + 1) - y * 2 - 1)) {
                    resRate = 1; 
                    bFinish = true; 
                }
                else {
                    if (abs(x) % 2 == 0) {
                        resRate = 0;
                        bFinish = true;
                    }
                    else if (abs(x) - ((m + 1) - y * 2 + 1) > 2) {
                        resRate = 0; 
                        bFinish = true; 
                    }
                }
            }
        }
        else if (y > m){
            bFinish = true; 
        }

        if (!bFinish && left != 0) {
            int half = m + 1; 
            if (left > half && y <= (left - half - 1)) {
                resRate = 1; 
            }
            else {
                __int64 total = pow(double(2), left); 
                __int64 possible = 0; 
                for (int i = y+1; i<=left; i++) {
                    possible += C[left][i]; 
                }

                resRate = double(possible) / total;
            }
        }


        // print result
        cout << "Case #" << (cases + 1) << ": ";
        printf("%.6lf\n", resRate);
    }

    return 0;
}