#include <bits/stdc++.h>

#define NDEBUG
#ifdef NDEBUG
#include "debug.h"
#endif

#define mp make_pair
#define pb push_back
#define all(x) (x).begin() , (x).end()
#define rall(x) (x).rbegin() , (x).rend()
#define REP(i,x,y) for(int i=x;i<y;i++)
#define REPIT(it,A) for(typeof(A.begin()) it = (A.begin()); it!=A.end();it++)
#define fst first
#define snd second
#define sqr(x) ((x)*(x))

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define ones(x) __builtin_popcount(x)
using namespace std;

typedef pair<int,int> ii ;
typedef long long ll ;
typedef vector<int> vi;
typedef vector<ii> vii;

#define mt(x,y,z) mp(mp((x),(y)), (z))
#define tfst fst.fst
#define tsnd fst.snd
#define ttri snd
typedef pair<ii,int> tri;

vi ans;

int n;
int fre[28];
void add(int cant, int number){
	REP(i,0,cant) ans.pb(number);

}

int check(char c, string p){
	int id = c-'A';
	int cant = fre[id];
	
	REP(i,0,p.length()){
		char e = p[i];
		fre[e-'A'] -= cant;
	}
	return cant;
}

int main(){
	fastio;
	int T;
	cin >> T;
	for(int test = 1; test <= T; test++){
		ans.clear();
		string s; cin >> s;
		n = s.length();
		REP(i,0,26) fre[i] = 0;
		REP(i,0,n) fre[s[i]-'A']++;
		int cant;
		cant = check('Z', "ZERO");
		add(cant,0);
		cant = check('W', "TWO" );
		add(cant,2);
		cant = check('U',"FOUR");
		add(cant,4);
		cant = check('G', "EIGHT");
		add(cant,8);
		cant = check('X', "SIX");
		add(cant,6);
		cant = check('O',"ONE");
		add(cant,1);
		cant = check('T',"THREE");
		add(cant,3);
		cant = check('F',"FIVE");
		add(cant,5);
		cant = check('V',"SEVEN");
		add(cant,7);
		cant = check('I', "NINE");
		add(cant,9);

		/*REP(i,0,26) if(fre[i] != 0){
			char e= 'A'+i;
			cerr<<e<<endl;
		}*/	
		sort(all(ans));
		
		cout<<"Case #"<<test<<": ";
		REP(i,0,ans.size()){
			cout<<ans[i];
		}
		cout<<endl;

	}

	return 0;
}

