#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <queue>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <stdio.h>
#include <complex>

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<int, PII> TIII;
typedef long long LL;
typedef vector<LL> VLL;

//container util

//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define MT(a,b,c) MP(a, MP(b, c))
#define T1 first
#define T2 second.first
#define T3 second.second

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

double Comb[1000][1000];

void init(){
	Comb[1][0] = Comb[1][1]=1.0;
	Comb[1][2] = 0.0;
	FOR(i,2,1000){
		REP(j,i+1){
			if(j==0)Comb[i][j]=1.0;
			else if(j==i)Comb[i][j] = 1.0;
			else Comb[i][j]=Comb[i-1][j-1]+Comb[i-1][j];
		}
	}
}

int calcK(int n){
	int u=1000, l=0;
	while(u-l>1){
		int m =(u+l)/2;
		if((m+1)*(2*m+1)<=n)l=m;
		else u=m;
	}
	if((l+1)*(2*l+1)<n)return u;
	else return l;
}

int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	init();
	int T;
	cin>>T;
	REP(t,T){
		int n,x,y,k;
		cin>>n>>x>>y;
		double ans=0.0;
		k=calcK(n);
		if(t==16){
			cerr << "PPP"<< endl;
		}
		if(abs(x)+y<2*k){
			printf("Case #%d: %.8f\n", t+1, 1.0);
			continue;
		}
		if(abs(x)+y>2*k){
			printf("Case #%d: %.8f\n", t+1, 0.0);
			continue;
		}
		int p=n-k*(2*k-1);
		if(p-2*k-1>=y){
			printf("Case #%d: %.8f\n", t+1, 1.0);
			continue;
		}
		if(x==0){
			printf("Case #%d: %.8f\n", t+1, 0.0);
			continue;
		}
		FOR(i, y+1, p+1)ans += Comb[p][i];
		double ansv=pow(0.5, p);
		printf("Case #%d: %.8f\n", t+1, ans*ansv);
		
	}
	return 0;
}
