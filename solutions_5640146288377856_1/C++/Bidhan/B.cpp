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
const int mx = 22;

bool oneW(int mask, int w, int c) {
	int cur = 0, ret = 0;
	int other = 0;
	
	for(int i = 0; i < c; i++) {
		if( mask & (1<<i) ) {
			ret += (cur == w);
			other += (cur > w);
			cur = 0;
		}
		else cur++;
	}
	ret += (cur == w);
	other += (cur > w);
	
	return ret == 1 && !other;
}

bool valid(int mask, int w, int c) {
	int tmask = mask;
	
	while(tmask) {
		int now = tmask & -tmask;
		
		if(oneW( mask^now, w, c)) return true;
		
		tmask -= now;
	}
	
	return false;
}

int main(){
    time_t start=clock();
    freopen("inBig","r",stdin);
    freopen("outBig","w",stdout);
    //write("out.txt");
    ios_base::sync_with_stdio(0);
    int test;
    cin>>test;
    while( test-- ){
		
		int R, C, W;
		
		cin >> R >> C >> W;
		
		//assert( R == 1 );
		
		int minP = C;
		
		for(int mask = 0; mask < (1<<C); mask++) {
			if(!valid(mask, W, C) ) continue;
			//cout << mask << endl;
			minP = min(minP, __builtin_popcount(mask) );
		}
		
        cout<<"Case #"<<++kas<<": ";
        cout << minP * R + W - 1 << endl;
        
         cerr<<"Case #"<<kas<<": ";
        cerr << minP * R + W - 1 << endl;
    }
    cerr << "\n\n=================================================================="<<endl;
    cerr << "Program has run "<< ( clock()-start ) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}

