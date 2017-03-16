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

int maxbit(int x){
	int res;
	dforsn(i,0,31){
		if(1 << i & x){
			res = i;
			break;
		}
	}
	return res;
}

int main()
{
	int t, a, b, k;
	tint pot3[32];
	tint count[32][32][32];
	pot3[0] = 1LL;
	forsn(i,1,32){
		pot3[i] = 3LL*pot3[i-1];
	}
	forn(i,32) count[i][i][0] = pot3[i];
	
	forn(k,32){
		forsn(i,k,32){
			forsn(j,i+1,32){
				count[i][j][k] = 1 << (j+i-4+2*k);
			}
		}
	}


	cin >> t;
	forn(caso, t){
		cin >> a >> b >> k;
		tint res = 0LL;
		forn(i,a){
			forn(j,b){
				//cout << i << " " << j << " " << (i&j) << endl;
				if( (int)(i&j) < k){ res++; } //cout << i << " " << j << endl;}
			}
		}

		cout << "Case #" << (caso+1) << ": " << res << endl;
	}

	return 0;
}

