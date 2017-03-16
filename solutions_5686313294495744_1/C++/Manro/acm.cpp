#include <bits/stdc++.h>
#define ff first
#define ss second
#define D(x) cout << ">> " << #x << " = >" << x << "<\n"
#define FOR(i,a,b) for ( decltype( a ) i = (a); i < (b); ++i )
#define FORD(i,a,b) for ( int i = int(a); i >= (b); --i )
#define PB push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

typedef vector<int> VI;
typedef vector<VI> VVI;

bool FindMatch(int i, const VVI &w, VI &mr, VI &mc, VI &seen) {
  for (int j = 0; j < w[i].size(); j++) {
    if (w[i][j] && !seen[j]) {
      seen[j] = true;
      if (mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen)) {
        mr[i] = j;
        mc[j] = i;
        return true;
      }
    }
  }
  return false;
}

int BipartiteMatching(const VVI &w, VI &mr, VI &mc) {
  mr = VI(w.size(), -1);
  mc = VI(w[0].size(), -1);
  
  int ct = 0;
  for (int i = 0; i < w.size(); i++) {
    VI seen(w[0].size());
    if (FindMatch(i, w, mr, mc, seen)) ct++;
  }
  return ct;
}

int main( ) {
	int t, n;
	string a, b;

	cin >> t;
	FOR( caseNr, 1, t+1 ) {
		vector<string> firstW, secondW;;
		unordered_map<string,int> fid, sid;
		int fidn = 0, sidn = 0;
		cout << "Case #" << caseNr << ": " ;
		cin >> n;
		FOR( i, 0, n ) {
			cin >> a >> b;
			firstW.PB( a );
			secondW.PB( b );
			if ( !fid.count( firstW[i] ) )
				fid[firstW[i]] = fidn++;
			if ( !sid.count( secondW[i] ) )
				sid[secondW[i]] = sidn++;
		}
		VVI w( firstW.size( ) );
		VI mr( firstW.size( ) );
		VI mc( secondW.size( ) );

		FOR( i, 0, firstW.size( ) )
			w[i].resize( secondW.size( ) );

		FOR( i, 0, n ) {
			w[ fid[ firstW[i] ] ][ sid[ secondW[i] ] ] = 1;
		}
		int res = BipartiteMatching( w, mr, mc );
		cout << n - (fidn + sidn - res) << endl;
	}
	return 0;
}