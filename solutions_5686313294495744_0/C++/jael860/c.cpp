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

int n;
int fre1[4000],fre2[4000];
vector<ii > lista;
map<string, int> mapa;
int id;
int getId(string a){
	if(mapa.count(a) != 0) return mapa[a];
	
	mapa[a] = id; id++;
	return id-1;
}

int main(){
	fastio;
	int T;
	cin >> T;
	for(int test = 1; test <= T; test++){
		cin >> n;
		id = 0;
		lista.clear();
		mapa.clear();
		REP(i,0,3*n) {fre1[i] = fre2[i] = 0;}
		REP(i,0,n){
			string a,b;
			cin >> a >> b;
			int a1 = getId(a);
			int b1 = getId(b);
			lista.pb(mp(a1,b1));
			fre1[a1]++;
			fre2[b1]++;
		}
		
		int res = 0;
		REP(i,0,n){
			int a = lista[i].fst;
			int b = lista[i].snd;
			if(fre1[a] > 1 && fre2[b] > 1){
				res++;
			}
		}
		cout<<"Case #"<<test<<": "<<res<<endl;

	}

	return 0;
}

