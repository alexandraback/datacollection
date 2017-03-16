#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <algorithm>
#include <sstream>

#define F(i,n) for(int i=0, n_=(n); i<n_; i++)
#define FS(i,s,n) for(int i=(s), n_=(n); i<n_; i++)
#define FR(i,n) for(int i=(n)-1; i>=0; i--)

#define AA first
#define BB second
#define XX first.first
#define YY first.secomd
#define ZZ second

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<double> VF;
typedef pair<int, int> PRI;
typedef pair<PRI, int> TRI;

template<typename T> inline void updatemin(T &a, T b) { if(a>b) a=b; }
template<typename T> inline void updatemax(T &a, T b) { if(a<b) a=b; }
template<typename T> inline T gcd(T a, T b) { 
	T d; 
	while(b!=0) d=a, a=b, b=d%b; 
	return a;
}


int main(){
	int N, T, p, S, totalscore;
	cin>>T;
	F(test,T){
		cin>>N>>S>>p;
		int sure = 0, notsure = 0;
		F(i,N){
			cin>>totalscore;
			if(totalscore == 1) if(p==1) sure++;
			if(totalscore <= 1) continue;
			if((totalscore+2)/3 >= p) sure++;
			else if((totalscore+4)/3 >= p) notsure++;
		}
		updatemin(notsure, S);
		if(p==0) cout<<"Case #"<<test+1<<": "<<N<<endl;
		else cout<<"Case #"<<test+1<<": "<<sure + notsure<<endl;
	}
	return 0;
}