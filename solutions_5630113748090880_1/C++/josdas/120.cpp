#define _ijps 01
#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:667772160")
#include <iostream>
#include <cmath>
#include <vector>
#include <time.h>
#include <map>
#include <set>
#include <deque>    
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <algorithm>
#include <string>
#include <fstream>    
#include <complex>    
#include <assert.h>
#include <list>
#include <cstring>
using namespace std;

#define name ""
typedef unsigned long long ull;
typedef long long ll;
#define mk make_pair
#define forn(i, n) for(ll i = 0; i < (ll)n; i++)
#define fornn(i, q, n) for(ll i = ( ll)q; i < (ll)n; i++)
#define times clock() * 1.0 / CLOCKS_PER_SEC

struct __isoff{
	__isoff(){
		if (_ijps)
			freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);//, freopen("test.txt", "w", stderr);
		//else freopen(name".in", "r", stdin), freopen(name".out", "w", stdout);
		//ios_base::sync_with_stdio(0);
		srand('C' + 'T' + 'A' + 'C' + 'Y' + 'M' + 'B' + 'A');
		srand(time(0));
	}
	~__isoff(){
		//if(_ijps) cout<<' '<<times<<'\n';
	}
} __osafwf;
const ull p1 = 123123;
const ull p2 = 12321;
const double eps = 1e-6;
const double pi = acos(-1.0);

const ll inf = 1e18 + 7;
const int infi = 2e9 + 7;
const ll dd = 1e5 + 7;
const ll sh = 4501;
const ll mod = 1e9 + 7;
const ll mod2 = 175781251;

int main(){
	int fg;
	cin >> fg;
	forn(ii, fg){
		cout << "Case #" << ii + 1 << ": ";
		int n;
		cin >> n;
		vector<int> G(3000);
		forn(i, 2 * n - 1){
			forn(j, n){
				int t;
				cin >> t;
				G[t]++;
			}
		}
		forn(i, 3000){
			if(G[i] % 2 == 1){
				cout << i << ' ';
			}
		}
		cout << '\n';
	}
}