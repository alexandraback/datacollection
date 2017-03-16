/*
 * Bidhan Roy
 * University of Dhaka
 */

using namespace std;
#include <bits/stdc++.h>

#define mem(x,val) memset((x),(val),sizeof(x));
#define write(x) freopen(x,"w",stdout);
#define read(x) freopen(x,"r",stdin);
#define sz(x) ((int)x.size())

typedef long long i64;
typedef unsigned long long ui64;
typedef pair<int,int> pii;

const double pi = M_PI;
const double eps = 1e-9;
int kas = 0;
const int mx = 0;

int main(){
    time_t start=clock();
    freopen("cin", "r", stdin);
    freopen("cout", "w", stdout);
    //write("out.txt");
    ios_base::sync_with_stdio(0);
    int test;
    cin>>test;
    while( test-- ){
		int c, d, v;
		
		cin >> c >> d >> v;
		
		assert( c == 1 );
		assert( v <= 30 );
		
		vector<int> coin(d);
		
		for(int i = 0; i < d; i++) cin >> coin[i];
		
		unordered_set<int> ase;
		
		for(int mask = 0; mask < (1<<d); mask++){
			int tot = 0;
			for(int i = 0; i < d; i++ ){
				if( !(mask&(1<<i)) ) continue;
				tot += coin[i];
			}
			ase.insert( tot );
		}
		
		int ans = 0;
		
		for(int i = 0; i <= v; i++ ) {
			if( ase.count( i ) ) continue;
			ans++;
			
			vector<int> tmp;
			for(auto x : ase) tmp.push_back( x + i );
			for(auto x : tmp) ase.insert( x );
		}
		
		
        cout<<"Case #"<<++kas<<": ";
        cout << ans << endl;
    }
    cerr << "\n\n=================================================================="<<endl;
    cerr << "Program has run "<< ( clock()-start ) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}

