#include <iostream>
#include <fstream>

#include <vector>
#include <algorithm>

#define All(v)			v.begin(),v.end()

#define REP(i,a,b)		for(i=(int)a ; i<=(int)b ; i++)
#define FOR(i,N)		REP(i,0,N-1)

#define VI				vector<int>
#define VVI				vector<VI>

#define VD				vector<double>
#define VVD				vector<VD>

#define x				first
#define y				second
#define II				pair<int,int>
#define VII				vector<II>
#define VVII			vector<VII>

using namespace std;

int main(){
	ifstream cin("input.txt");
	ofstream cout("a1.out");
	int T;
	cin >> T;
	int cnt;
	REP(cnt,1,T){
		int i,j,k;
		VII N;
		int n;
		int sum;
		VD ans;

		cin >> n;
		N.resize(n);
		ans.resize(n);
		sum = 0;
		FOR(i,n){
			cin >> N[i].x;
			N[i].y = i;
			sum += N[i].x;
		}

		sort(All(N));

		double psum = sum;
		int lim;
		FOR(lim,n){
			double val = psum + N[lim].x;
			val = val/(lim+1);
			double base = N[lim].x;
			if(base > val)
				break;
			psum += N[lim].x;
		}

		double des = psum/lim;
		FOR(i,lim){
			double pc = (des-N[i].x)/sum;
			ans[N[i].y] = pc*100;
		}

		cout << "Case #"<<cnt<<":";
		FOR(i,n){
			char out[100];
			sprintf(out,"%.6f",ans[i]);
			cout <<" "<<out;
		}
		cout << endl;
	}
}