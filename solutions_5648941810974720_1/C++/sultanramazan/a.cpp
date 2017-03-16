#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define sqr(x) (x) * (x)
#define forn(i, l, r) for(int i = l; i < r; i ++)
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define y1 salnk
#define N 200100              
#define sz(a) (int)a.size()
#define ll long long
const int inf = (int)1e9;
const double pi = acos(-1.0);
const double eps = 1e-9;


int d[N], p[N], t;
string s;

int main () {
    //freopen("in", "r", stdin);
    cin >> t;
    int qq = 0;

    while (t--) {
     	cin >> s;
     	int n = s.size();
    	for (int i = 0; i < 26; i++)
    		d[i] = 0, p[char(i+'A')] = 0;

    	for (int i = 0; i < n; i++) {
    	 	p[s[i]]++;
    	}

    	int z = p['W'];//gmin(p['O'], p['T'], p['W']);
    	p['O'] -= z;
    	p['T'] -= z;
    	p['W'] -= z;
    	d[2] += z;
    	
    	z = p['Z'];
    	
    	d[0] += z;
    	p['O'] -= z;
    	p['E'] -= z;
    	p['Z'] -= z;
    	p['R'] -= z;

    	z = p['X'];
    	d[6] += z;
    	p['X'] = 0;
    	p['I'] -= z;
    	p['S'] -= z;

    	z = p['S'];
    	d[7] += z;
    	p['S'] -= z;
    	p['E'] -= 2 * z;
    	p['V'] -= z;
    	p['N'] -= z;

    	z = p['V'];
    	d[5] += z;
    	p['F'] -= z;
    	p['I'] -= z;
    	p['V'] -= z;
    	p['E'] -= z;
    	z = p['F'];
    	d[4] += z;
    	p['F'] -= z;
    	p['O'] -= z;
    	p['U'] -= z;
    	p['R'] -= z;



    	z = p['O'];
    	d[1] += z;
    	p['N'] -= z;
    	p['O'] -= z;
    	p['E'] -= z;

    	
        	z = p['R'];
    	d[3] += z;
    	p['R'] -= z;
    	p['T'] -= z;
    	p['H'] -= z;
    	p['E'] -= 2 * z;

    	z = p['N']/2;
    	d[9] += z;
    	p['N'] -= z * 2;
    	p['I'] -= z;
    	p['E'] -= z;
    	
    	z = p['E'];
    	
    	d[8] += z;
    	p['E'] -= z;
    	p['I'] -= z;
    	p['G'] -= z;
    	p['H'] -= z;
    	p['T'] -= z;

    	
    	qq++;
    	cout << "Case #"<<qq<<": " ;
    	for (int i = 0; i < 10; i++)
    		for (int c = 1; c <= d[i]; c++)
    			cout << i;
    	cout << endl;
    }
    return 0;
}