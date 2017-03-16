//C++ Template

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
typedef map<int,int>::iterator ITmii;

#define EPS 1e-9
#define FOR1(x,y,z) for( int x = y; x < z ; ++x)
#define FOR(x,y) FOR1(x,0,y)
#define FOR2(x,y) for(int x = y; x >= 0; --x)
#define PB push_back
#define ALL(X) (X).begin(), (X).end()
#define SORT(X) sort(ALL(X))
#define SIZE(X) ((int)(X).size())

//------------------------------------------------------------------
LL B,M;

string bin(LL a){
	string s = "";
	for(int i = 0; i < B-1; ++i){
		s += a%2 + '0';
		a/=2;
	}
	return s+"0";
}

int main(){
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.txt","w",stdout);
	int T; cin >> T;
	FOR(I,T){
		cin >> B >> M;
		cout << "Case #" << I+1 << ": ";
		LL mx = 1;
		mx <<= B-2;
		if (mx < M) cout << "IMPOSSIBLE\n"; 
		else {cout << "POSSIBLE\n";
			VVI ans(B,VI(B,0));
			for (int i = 0; i < B-1; ++i){
				for (int j = i+1; j < B; ++j){
					ans[i][j] = 1;
				}
			}
			ans[0][B-1] = 0;
			string s = "";
			if (M == mx){
				FOR(i,B-1) s += "1";
			}
			else s ='0' + bin(M);
			FOR(i,B){
				FOR(j,B){
					if (j+1 == B and i != B-1) cout << s[i];
					else cout << ans[i][j];
				}
				cout << '\n';
			}
		}
	}
}
