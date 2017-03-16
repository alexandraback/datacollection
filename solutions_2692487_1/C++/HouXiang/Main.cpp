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

int C[1000][1000]; 
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

    for (int cases=0; cases<number; cases++) 
    {
        __int64 iA = 0; 
        int n = 0; 

        inf >> ln; sscanf(ln.c_str(), "%I64d", &iA); 
        inf >> ln; n = atoi(ln.c_str()); 

        vector<__int64> v; 
        for (int i=0; i<n; i++) {
            inf >> ln; 
            __int64 ti = 0; 
            sscanf(ln.c_str(), "%I64d", &ti); 
            v.push_back(ti); 
        }

        sort(v.begin(), v.end()); 

        __int64 res_add = 0, res_min = v.size();
        for (int i=0; i<v.size(); i++) {
            if (iA > v[i]) {
                iA += v[i]; 
                if (res_min > (res_add + v.size() - i - 1))
                    res_min = res_add + v.size() - i - 1;
            }
            else {
                do {
                    res_add++; 
                    iA = 2 * iA - 1; 
                } while (iA <= v[i] && res_min > res_add); 
                
                if (iA > v[i])
                    iA +=  v[i]; 

                if (res_min > (res_add + v.size() - i - 1))
                    res_min = res_add + v.size() - i - 1;
            }

            if (res_min <= res_add) break;
        }


        // print result
        cout << "Case #" << (cases + 1) << ": " << (res_add < res_min ? res_add : res_min) << endl;
    }

    return 0;
}