#include <bitset>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include <time.h>
#include <map>
#include <set>
#include <iostream>
#include <assert.h>
#include <string>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)n;i++)
#define forab(i,a,b) for(int i=(int)a;i<(int)b;i++) //WARNING!! long long
#define mp make_pair
#define pb push_back
#define all(a,n) a,a+n
#define dprintf if(DEBUG)printf
#define dputs if(DEBUG)puts
#define dassert if(DEBUG)assert
#define fi first
#define se second
#define j0 jqwerty
#define j1 jasdf
#define i0 iqwerty
#define i1 iasdf
#define sq(x) (x)*(x)

typedef long long ll;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int DEBUG=1;

int n;

int a[60][60];
void solve(){
	int b;ll m;
	cin >> b >> m;
	ll k = 0;
	while((1LL << k) < m ) k++;
	if(k + 2 > b){
		cout << "IMPOSSIBLE\n";
		return ;
	}
	memset(a, 0,sizeof a);
    
	for(int i = 0; i <= k; i++){
		for(int j = i + 1; j <= k; j++){
			a[i][j] = 1;
		}
		a[i][b - 1] = 1;
	}
	ll ans = (1LL << k);
	ans -= m;
	//	cerr << ans << endl;

 for(int i = 0; i < k; i++){
		if(ans & (1LL << (i)))
			a[0][k - i] = 0;
   	}
	cout << "POSSIBLE\n";
	forn(i, b){
		forn(j, b){
			cout << a[i][j];
		}
		cout << endl;
	}
	
}
int main()
{
	int t;
	cin >> t;
	forn(i, t){
		printf("Case #%d: ", i + 1);
		solve();
		
	}
	return 0;
}
