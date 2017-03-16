#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define pb(x) push_back(x)
#define REP(i,x,y) for(int (i)=(x);(i)<(y);(i)++)
#define REPIT(it,A) for(typeof(A.begin()) it = (A.begin()); it!=A.end();it++)
#define sqr(x) ((x)*(x))
#define mp(x,y) make_pair((x),(y))
#define fast_io() ios_base::sync_with_stdio(0);cin.tie(0); 
//#define NDEBUG 1
#define fst first
#define snd second
#define sz(v) ((int)v.size())
typedef vector<int> vi;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int INF = 1e9;

int tc;
int n;

int b[60][60];

int mk[3000];

int main(){
	fast_io();
	cin >> tc;
	REP(q,1,tc+1){
		cout << "Case #" << q << ":";
		cin >> n;
		int m = 2*n -1;
		int x;
		REP(i,0,3000) mk[i] = 0;
		REP(i,0,m) REP(j,0,n) {
			cin >> x;
			mk[x]++;
		}
		REP(i,0,3000){
			if (mk[i] % 2){
				cout << " " << i;
			}
		}
		cout << endl;
	}
	return 0;
}

