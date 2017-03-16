#include<iostream>
#include<sstream>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cassert>

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
#define mp make_pair
#define pb push_back
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define dbg(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int inf = (int)1e9;
const double INF = 1e12, EPS = 1e-9;

bool win(string in[4], char c){
	bool ok = 1;
	rep(i, 4) if(in[i][i] != c && in[i][i] != 'T') ok = 0;
	if(ok) return 1;
	ok = 1;
	rep(i, 4) if(in[i][3 - i] != c && in[i][3 - i] != 'T') ok = 0;
	if(ok) return 1;
	
	rep(i, 4){
		ok = 1;
		rep(j, 4) if(in[i][j] != c && in[i][j] != 'T') ok = 0;
		if(ok) return 1;
		ok = 1;
		rep(j, 4) if(in[j][i] != c && in[j][i] != 'T') ok = 0;
		if(ok) return 1;
	}
	return 0;
}

int main(){
	int CS;
	cin >> CS;
	rep(cs, CS){
		cout << "Case #" << cs + 1 << ": ";
		
		string in[4];
		rep(i, 4) cin >> in[i];
		if(win(in, 'O')) cout << "O won" << endl;
		else if(win(in, 'X')) cout << "X won" << endl;
		else{
			bool draw = 1;
			rep(i, 4) rep(j, 4) if(in[i][j] == '.') draw = 0;
			cout << (draw ? "Draw" : "Game has not completed") << endl;
		}
	}
	return 0;
}
