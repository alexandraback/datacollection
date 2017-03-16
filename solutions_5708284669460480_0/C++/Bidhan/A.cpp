/*
 * Bidhan Roy
 * University of Dhaka
 */

using namespace std;
#include <bits/stdc++.h>

#define mem(x,val) memset((x),(val),sizeof(x));
#define write(x) freopen(x,"w",stdout);
#define sz(x) ((int)x.size())

typedef long long i64;
typedef unsigned long long ui64;
typedef pair<int,double> pid;

const double pi = M_PI;
const double eps = 1e-9;
int kas = 0;
const int mx = 105;


void failure(string &p,int *F,int M){
	F[0]=F[1]=0;
	for(int i=2;i<=M;i++){
		int j=F[i-1];
		for(;;){
			if(p[j]==p[i-1]) { F[i]=j+1; break; }
			if(j==0) { F[i]=0; break; }
			j=F[j];
		}
	}  
}
 
string key, target;
int F[ mx ];

pid dp[ mx ][ mx ];
bool vis[ mx ][ mx ];

int newMatch(int oldMatch, char ch) {
	
	for(;;){
		if(oldMatch < sz(target) && ch == target[ oldMatch ]) {
			 oldMatch++;
			 break;
		}
		else if( oldMatch > 0 ) oldMatch = F[ oldMatch ];
		else break;
	}
	
	return oldMatch;
}

pid call(int length, int match) {
	
	if(!length) 
		return {0,0};
	
	auto &ret = dp[ length ][ match ];
	if( vis[ length ][ match ] ) return ret;
	vis[ length ][ match ] = true;
	
	ret = {0,0};
	
	for(char &ch : key) {
		auto nm = newMatch(match, ch);
		
		int add = (nm == sz(target));
		
		auto temp = call(length - 1, nm);
		
		temp.first += add;
		temp.second += add;
		
		temp.second /= (double) sz(key);
		
		ret.first = max(ret.first, temp.first);
		ret.second += temp.second;
	}
		
	return ret;
}

int main(){
    time_t start=clock();
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0);
    int test;
    cin>>test;
    while( test-- ){
		int k, l, s;
		cin >> k >> l >> s;
		cin >> key >> target;
		
		failure(target, F, sz(target));
		
		mem(vis, 0);
		auto ret = call(s, 0);
		
        cout<<"Case #"<<++kas<<": ";
        cout<<fixed<<setprecision(9)<< double(ret.first) - ret.second << endl;
    }
    cerr << "\n\n=================================================================="<<endl;
    cerr << "Program has run "<< ( clock()-start ) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}

