#define _CRT_SECURE_NO_WARNINGS

#pragma comment(linker, "/STACK:167777216")
#include <cmath>
#include <math.h>
#include <complex>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <iostream>
#include <ccomplex>

#include <unordered_map> 
#include <stack> 
#include <time.h> 
#include <fstream> 
#include <queue> 
using namespace std;

#define pb push_back  
#define mp(a,b) make_pair(a,b)   
#define F first  
#define S second  

#define all(x) x.begin(), x.end() 
#define sqr(x) ((x)*(x)) 
#define eps 1e-8 
#define inf (int)(1e9+7) 
#define infll (ll)(1e18+3) 
#define sz(x) ((int)x.size()) 
#define M_PI     3.14159265358979323846  
#define PI       3.14159265358979323846   
typedef long long ll;
typedef  unsigned long long ull;
typedef  long double ld;
typedef vector < ll > vll;
typedef vector < int > vi;
typedef pair < ll, ll > pll;
typedef pair < int, int > pii;
typedef int huint;
typedef complex<double> base;
using polynome = vector<complex<double>>;
 

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout); 

    int test;
    cin >> test;
    for (int tt(1); tt <= test; tt++)
    {
        string s;
        cin >> s;
        string c = "";
        c.pb(s[0]);
        for (int i(1); i < s.size(); i++)
            if (s[i] >= c[0]) c = s[i] + c;
            else c = c + s[i];

            cout << "Case #" << tt << ": " << c << "\n";
    }

}