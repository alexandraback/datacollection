#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <cassert>

#define FOR(i,n) for(int i=0,_n=n;i<_n;i++)
#define FORR(i,s,n) for(int i=s,_n=n;i<_n;i++)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pli pair<ll,int>
#define vi vector<int>
#define fs first
#define sec second

#define maxn 100000

using namespace std;
typedef long long ll;

const ll MOD = 1000000007LL;


void solve(int zap){
	int r;
	int n;
	cin >> n;
	vector <double> st;
	vector <double> w;
	FOR(i,n){
		double poz,t;
		int s;
		cin >> poz >> s >> t;
		FOR(j,s){
			st.pb(poz);
			w.pb(360.0/t);
			t=t+1;
		}
	}
	double t1 = (360-st[0])/w[0];
	double t2 = (360-st[1])/w[1];
	if(t1>t2){
		swap(t1,t2);
		swap(st[0],st[1]);
		swap(w[0],w[1]);
	}
	double t3 = (720-st[0])/w[0];
	if(t3<=t2)r=1;
	else r = 0;
	cout << "Case #" << zap << ": " << r << "\n";
}


int main(){
	int t;
	cin >> t;
	FORR(i,1,t+1){
		solve(i);
	}
	return 0;
}
