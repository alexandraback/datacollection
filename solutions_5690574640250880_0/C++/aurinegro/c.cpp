#include <algorithm>
#include <numeric>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <complex>
#include <cassert>
#include <bitset>
#include <cstring>
using namespace std;


#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define si(c) ((int)(c).size())
#define forsn(i,s,n) for(int i = (int)(s); i<((int)n); i++)
#define dforsn(i,s,n) for(int i = (int)(n)-1; i>=((int)s); i--)
#define decl(v, c) typeof(c) v = c
#define forall(i, c) for(decl(i, c.begin()); i!=c.end(); ++i)
#define dforall(i, c) for(decl(i, c.rbegin()); i!=c.rend(); ++i)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define D(a) cerr << #a << "=" << a << endl;
#define pb push_back
#define mp make_pair


typedef long long int tint;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<tint> vt;
typedef vector<vt> vvt;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;
typedef pair<int,int> pii;

const int MAXN = 50 + 5;
char res[MAXN][MAXN];


int main() {
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);

        int ncas; cin >> ncas;
        forn(cas, ncas) {
        	cout << "Case #" << cas+1 << ":" << endl;
        	int r,c,m; cin >> r >> c >> m;
        	int e = r*c - m;



        	fill(res[0], res[r], '*');
        	bool pos = false;
        	if (e == 1) {
        		pos = true;
        		res[0][0] = 'c';
        	}
        	else if (min(r,c) == 1) {
        		pos = true;
        		forn(i,r) forn(j,c) {
        			if (e) { res[i][j] = '.'; e--; }
        			else break;
        		}
        		res[0][0] = 'c';
        	}
        	else {
        		forsn(a,2,r+1) forsn(b,2,c+1) {
        			int mn = 2*(a+b) - 4, mx = a*b;
        			if (mn <= e && e <= mx) {
        				pos = true;
        				forn(i,a) res[i][0] = res[i][1] = '.';
        				forn(j,b) res[0][j] = res[1][j] = '.';

        				int rest = e - mn;
        				forsn(i,2,a) forsn(j,2,b) {
        					if (rest) { res[i][j] = '.'; rest--; }
        					else goto hell;
        				}
        				hell:;
        				res[0][0] = 'c';

        				goto done;
        			}
        		}
        		done:;

        	}

        	if (pos) 
        		forn(i,r) { forn(j,c) cout << res[i][j]; cout << endl; }
        	else
        		cout << "Impossible" << endl;
        }


        return 0;
}
