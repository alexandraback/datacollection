//#define ONLINE_JUDGE
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <iomanip>
#include <list>
#include <stack>
#include <queue>
#include <bitset>
#include <numeric>
#include <functional>

#include <cstdio>
#include <cmath>
#include <climits>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef vector <int> vi;
typedef pair< int ,int > pii;
#define rep(i, n)       for(int i = 0; i < n; i++)
#define reps(i, a, n)   for(int i = a; i < n; i++)
#define foreach(it, v)  for( __typeof((v).begin())it = (v).begin() ; it != (v).end() ; it++ )
#define precout(a,b)    cout << fixed << setprecision((b)) << (a)
#define endl 			'\n'
#define pb              push_back
#define mp              make_pair
#define ff              first
#define ss              second
#define all(a)          a.begin(), a.end()
#define rall(a)			a.rbegin(), a.rend()
#define sz(x)			(int)x.size()
#define fastIO   		ios::sync_with_stdio(false); cin.tie(0);

string s[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
string o;
int n;
vi ans;

int main() {
#ifndef ONLINE_JUDGE
    const clock_t begin_time = clock();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    fastIO
   int t;
    cin >> t;
    for (int T = 1; T <= t; T++) {
        cout << "Case #" << T << ": ";
        cin >> o;
        ans.clear();
        n = sz(o);
        sort(all(o));
        map<int, int> m;
        
        for (int i = 0; i < n; i++) {
            m[o[i] - 65]++;
        }
        
        if (m[25]) {
            m['E' - 65] -= m[25];
            m['R' - 65] -= m[25];
            m['O' - 65] -= m[25];
            
            rep(i, m[25])
            ans.pb(0);
            m[25]  = 0;
        }
        
        
        if (m['G' - 65]) {
            m['E' - 65] -= m['G' - 65];
            m['I' - 65] -= m['G' - 65];
            m['H' - 65] -= m['G' - 65];
            m['T' - 65] -= m['G' - 65];
            rep(i, m['G' - 65])
            ans.pb(8);
            m['G' - 65]  = 0;
           
        }
        
        if (m['U' - 65]) {
            m['F' - 65] -= m['U' - 65];
            m['O' - 65] -= m['U' - 65];
            m['R' - 65] -= m['U' - 65];
            rep(i, m['U' - 65])
            ans.pb(4);
            m['U' - 65]  = 0;
            
        }
        
        if(m['X' - 65]) {
            m['S' - 65] -= m['X' - 65];
            m['I' - 65] -= m['X' - 65];
            rep(i, m['X' - 65])
            ans.pb(6);
            m['X' - 65]  = 0;
            
        }
        
        if (m['W' - 65]) {
            m['T' - 65] -= m['W' - 65];
            m['O' - 65] -= m['W' - 65];
            rep(i, m['W' - 65])
            ans.pb(2);

            m['W' - 65]  = 0;
        }
        
        if (m['F' - 65]) {
            m['I' - 65] -= m['F' - 65];
            m['V' - 65] -= m['F' - 65];
            m['E' - 65] -= m['F' - 65];
            rep(i, m['F' - 65])
            ans.pb(5);

            m['F' - 65]  = 0;
        }
        
        if (m['V' - 65]) {
            m['S' - 65] -= m['V' - 65];
            m['E' - 65] -= 2*m['V' - 65];
            m['N' - 65] -= m['V' - 65];
            
            rep(i, m['V' - 65])
            ans.pb(7);
            m['V' - 65] = 0;
        }
        
        if (m['T' - 65]) {
            m['H' - 65] -= m['T' - 65];
            m['E' - 65] -= 2*m['T' - 65];
            m['R' - 65] -= m['T' - 65];
            rep(i, m['T' - 65])
            ans.pb(3);
            m['T' - 65]  = 0;
           
        }	
        
        if (m['O' - 65]) {
            m['N' - 65] -= m['O' - 65];
            m['E' - 65] -= m['O' - 65];

            
            rep(i, m['O' - 65])
            ans.pb(1);
            m['O' - 65] = 0;
        }	
        
        if (m['I' - 65]) {
            m['N' - 65] -= 2 * m['I' - 65];
            m['E' - 65] -= 2 * m['I' - 65];

            rep(i, m['I' - 65])
            ans.pb(9);
            m['I' - 65] = 0;
          
        }	
        
        
    
        
        sort(all(ans));
        for (auto x : ans) cout << x;
        cout << endl;
        
    }
         
    
#ifndef ONLINE_JUDGE
   	cout << endl;
    cout << "Time : ";
    cout << float( clock () - begin_time ) / CLOCKS_PER_SEC << endl;
#endif
    
    return 0;
}
