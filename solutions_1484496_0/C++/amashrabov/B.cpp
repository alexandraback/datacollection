#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cassert>
#include <map>
#include <set>
#include <ctime>

using namespace std;

///-------------Interface------------/// 

typedef stringstream SS;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double ld;

typedef vector <int> vi;
typedef vector <uint> vui;
typedef vector <ld> vd;
typedef vector <ll> vll;
typedef vector <ull> vull;
typedef vector <pair <int, int> > vii;
typedef vector <pair <uint, uint> > vuii;
typedef vector <pair <ld, ld> > vdd;
typedef vector <pair <ll, ll> > vllll;
typedef vector <pair <ull, ull> > vullll;

typedef pair<int, int> pi;
typedef pair<uint, uint> pui;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;
typedef pair<ld, ld> pd;

const ld eps = 1e-7;

#define eq(a, b) (fabs((a) - (b)) < eps)
#define ls(a, b) ((a) < (b) - eps);
#define lseq(a, b) ((a) < (b) + eps);
#define gr(a, b) ((a) > (b) + eps);
#define greq(a, b) ((a) > (b) - eps);

#define pb push_back
#define mp make_pair
#define sz size
#define e1 first
#define e2 second
#define ins insert
#define ers erase
#define all(x) (x).begin(),(x).end()
#define sub substr
#define rsz resize

const string nl = "\n";

#define NL printf("\n")
#define out(x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i) cout << *i << " ";
#define dbg(x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i) cerr << *i << " ";

template <typename T>
string convtos (T a)
{
    SS ss;
    ss << a;
    return ss.str();
}

template <typename T>
T convtot (string s)
{
    T x;
    SS ss;
    ss << s;
    ss >> x;
    return x;
}

void printtime ()
{
    cerr << double(clock()) / CLOCKS_PER_SEC << nl;
}

///------------Algorithms------------///

void zfunc (const string &s, vector <int> &z)
{
    int n = s.sz();
    z.resize(n);
    z[0] = 0;
    for (int l = 0, r = 0, i = 1; i < n; ++i)
    {
        z[i] = (i <= r ? min(r - i + 1, z[i - l]) : 0);
        while (i + z[i] < n && s[z[i]] == s[z[i] + i])z[i]++;
        if (i + z[i] > r) r = z[i] + i - 1, l = i;
    }
}

void pfunc (const string &s, vector <int> &p)
{
    int n = s.sz();
    p.resize(n);
    p[0] = 0;
    for (int i = 1; i < n; ++i)
    {
        int l = p[i - 1];
        while (l > 0 && s[l] != s[i]) l = p[l - 1];
        if (l == 0) p[i] = (s[i] == s[0]);
        else p[i] = l + 1;
    }
}

template <typename T>
T xgcd (T a, T b, T &x, T &y)
{
    if (a == 0)
    {
        x = 0, y = 1;
        return b;
    }
    T x1, y1, ans;
    ans = xgcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return ans;
}

void prime (int N, vector <int> &pr)
{
    pr.resize(0);
    vector <int> lp(N, 0);
    for (size_t i = 2; i < N; ++i)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.pb(i);
        }
        else
            for (size_t j = 0; j < pr.sz() && pr[j] <= lp[i] && i * pr[j] < N; ++j)
                lp[i * pr[j]] = pr[j];
    }
}


void solve ();
int main ()
{
    ios_base::sync_with_stdio(0);
    
    freopen("Binput.txt", "r", stdin);
    freopen("Boutput.txt", "w", stdout);

    solve();
    return 0;
}   

const double T = 100;
double cT = T, dT = 0.99;

int Test, n;
ll c[1000];

const int NONE = 0;
const int A = 1;
const int B = 2;

int bans[1000], cans[1000];
ll bansc, cansc;
int a, b;

void solve ()
{
    cin >> Test;
    for (int t = 1; t <= Test; ++t)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> c[i];
            bans[i] = NONE;
        }
        
        a = 1;
        b = 1;
        bans[0] = A;
        bans[1] = B;
        bansc = abs(c[0] - c[1]);
    
        for (int it = 0; it < 100000000; ++it)
        {
            for (int i = 0; i < n; ++i)
                cans[i] = bans[i];
                
            int chg = 1 + n * (cT / T), pos, ca = a, cb = b;
            cT = T;
            
            for (int i = 0; i < chg; ++i)
            {
                pos = rand() % n;
                if (ca == 1 && cans[pos] == A) continue;
                if (cb == 1 && cans[pos] == B) continue;
                
                if (cans[pos] == A)
                    ca--;
                if (cans[pos] == B)
                    cb--;
                    
                cans[pos] = rand() % 3;
                
                if (cans[pos] == A)
                    ca++;
                if (cans[pos] == B)
                    cb++;
                    
                ll suma = 0, sumb = 0;
                for (int j = 0; j < n; ++j)
                {
                    if (cans[j] == A)
                        suma += c[j];
                    else if (cans[j] == B)
                        sumb += c[j];
                }
                
                cansc = abs(suma - sumb);
                
                if (cansc < bansc || 
                    ( (rand() / double(RAND_MAX)) < exp((bansc - cansc) / cT) + eps )
                    )
                {
                    bansc = cansc;
                    for (int j = 0; j < n; ++j)
                        bans[j] = cans[j];
                    a = ca, b = cb;
                }
            }
            
            if (bansc == 0)
                break;
            
            cT *= dT;
        }
        
        //ntf("Case #%d:\n", t);
        cout << "Case #" << t << ":" << endl;
        
        if (bansc == 0)
        {
            for (int i = 0; i < n; ++i)
                if (bans[i] == A)
                    cout << c[i] << " ";
            cout << endl;
            for (int i = 0; i < n; ++i)
                if (bans[i] == B)
                    cout << c[i] << " ";
            cout << endl;
        }
        else
        {
            //cerr << bansc << endl;
            printf("Impossible\n");
        }
    }
}

