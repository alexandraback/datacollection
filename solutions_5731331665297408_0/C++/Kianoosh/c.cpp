// In the Name Of God

#include <iostream>
#include <fstream>

#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstring>
#include <istream>
#include <queue>
#include <stack>

#define inf (int)(~0u/2)
#define ll_inf (long long)1ll << 62
#define int long long
#define float long double
#define eps (1e-8)
#define for2(i, a, b) for ( int (i) = (a); (i)<(b); (i)++ )
#define mp make_pair
#define f1 first
#define f2 second
#define pb push_back
#define pii pair<int,int>
#define vpii vector <pii>
#define vi vector<int>
#define sz(a) (int) a.size( )
#define fillArr(n, a) for2(i, 0, n) cin >> a[i];
#define print(a) cout << #a << endl;
#define umax(a,b) a = max ( a, b )
#define umin(a,b) a = min ( a, b )
#define all(k) k.begin ( ), k.end( )
#define rall(k) k.rbegin ( ), k.rend( )
#define clean(k) memset( k, 0, sizeof(k) )
using namespace std;

vector <int> adlist[2000];
string s[2000], final, final2;
bool visited[2000];

int n, m;
int khar[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

bool check ( ){
	final2 = "";
	int now = khar[0];
	clean ( visited );
	stack <int> st;
	st.push (now);
	int ind = 0;
	while ( ind < n-1 && st.size ( ) ){
		int now = st.top ( );
		bool f = 0;
		for2( i, 0, sz(adlist[now]) ){
			int j = adlist[now][i];
			if ( j == khar[ind+1] ){
				st.push ( j );
				f = 1;
				ind++;
				break;
			}
		}
		if ( !f )
			st.pop ( );
	}
	if ( ind >= n-1 ){
		for2 ( i, 0, n )
			final2 += s[khar[i]];
		return true;
	}
	return false;
}



main ( ){
	int GG;
	cin >> GG;
	for2 ( rr, 0, GG ){
		cout << "Case #" << rr+1 << ": ";
		cin >> n >> m;
		for2 ( i, 0, n )
			adlist[i].clear ( ), cin >> s[i];
		sort ( khar, khar + n );
		for2 ( i, 0, m ){
			int a, b;
			cin >> a >> b;
			a--, b--;
			adlist[a].pb ( b );
			adlist[b].pb ( a );
		}
		string final = "";
		do{
			if ( check ( ) ){
				if ( final == "" || final > final2 )
					final = final2;
			}

		}while ( next_permutation( khar, khar + n ) );;
		cout << final << endl;
	}

}
