#include <iostream>
#include <fstream>

#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <functional>

#define All(v)			v.begin(),v.end()

#define REP(i,a,b)		for(i=(int)a ; i<=(int)b ; i++)
#define FOR(i,N)		REP(i,0,N-1)

#define VI				vector<long long>
#define VVI				vector<VI>
#define VVVI			vector<VVI>

#define VD				vector<double>
#define VVD				vector<VD>

#define x				first
#define y				second
#define II				pair<int,int>
#define VII				vector<II>
#define VVII			vector<VII>

using namespace std;

VI a;
VI b;
VI Na;
VI Nb;
int N,M;

long long Rec(int n, int m){
	long long ans = 0;
	long long Min;
	long long Max;
	if(n == N || m == M)
		return 0;
	if(a[n] == b[m]){
		if(Na[n] > Nb[m]){
			Max = Na[n];
			Min = Nb[m];

			Na[n] -= Min;
			Nb[m] -= Min;
			ans = max(ans,Min+Rec(n,m+1));
			Na[n] += Min;
			Nb[m] += Min;
		}
		else if(Na[n] < Nb[m]){
			Max = Nb[m];
			Min = Na[n];

			Na[n] -= Min;
			Nb[m] -= Min;
			ans = max(ans,Min+Rec(n+1,m));
			Na[n] += Min;
			Nb[m] += Min;
		}
		else{
			ans = max(ans,Na[n]+Rec(n+1,m+1));
		}
	}
	else{
		ans = max(ans,Rec(n+1,m));
		ans = max(ans,Rec(n,m+1));
	}
	return ans;
}

int main(){
	ifstream cin("input.txt");
	ofstream cout("c1.out");
	int T;
	cin >> T;
	int cnt;
	REP(cnt,1,T){
		int i,j,k;

		cin >> N >> M;
		a.resize(N); Na.resize(N);
		b.resize(M); Nb.resize(M);
		FOR(i,N)
			cin >> Na[i] >> a[i];
		FOR(i,M)
			cin >> Nb[i] >> b[i];

		cout <<"Case #"<<cnt<<": "<< Rec(0,0) << endl;
	}
}