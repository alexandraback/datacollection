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

struct hiker{
	double st;
	double w;
	double t;
	double obhod;
};

bool comp(hiker h1, hiker h2){
	return h1.t>h2.t;
}

void solve(int zap){
	int r=0;
	int n;
	cin >> n;
	vector <hiker> h;
	hiker tmp;
	FOR(i,n){
		double poz,t;
		int s;
		cin >> poz >> s >> t;
		FOR(j,s){
			tmp.st = poz;
			tmp.w = (360/t);
			tmp.obhod = t;
			tmp.t = (360-poz)/tmp.w;
			h.pb(tmp);
			t=t+1;
		}
	}
	sort(h.begin(),h.end(),comp);
	int najr = 10000000;
	FOR(i,h.size()){
		int tr=0;
		double cajt = h[i].t;
		FOR(j,h.size()){
			if(i==j)continue;
			if(j<i){//pocasnejsi
				tr++;
				continue;
			}//hitrejsi
			double cas = cajt-h[j].t;
			int st = (int)(cas/h[j].obhod);
			tr+=st;
		}
		if(tr<najr)najr=tr;
	}
	cout << "Case #" << zap << ": " << najr << "\n";
}


int main(){
	int t;
	cin >> t;
	FORR(i,1,t+1){
		solve(i);
	}
	return 0;
}
