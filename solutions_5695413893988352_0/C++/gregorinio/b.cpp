#include "bits/stdc++.h"

using namespace std;

#define REP(i,a,b) for (int i = (a); i <= (b); ++i)
#define FOR(i,n) REP(i,0,int(n)-1)
#define vi vector<int>
#define fi first
#define se second
#define mp make_pair
#define real long double
#define pb push_back
#define pii pair<int,int>
#define vr vector<real>
#define ll long long 

/*ll dp[42], dpC[42], dpJ[42];

void solve(vector<char> check) {
	string C,J;
	cin>>C>>J;
	int n = C.size();
	ll pot = 1;
	dp[n] = 0; dpJ[n] = 0; dpC[n]=0;
	for(int i=n-1; i>=0; i--) {
		if(C[i] != '?' && J[i] != '?') {
			dpC[i] = 1LL * ((C[i] - '0') - (J[i] - '0'))* pot + dpC[i+1];
			dpJ[i] = 1LL * ((J[i] - '0') - (C[i] - '0'))* pot + dpJ[i+1];
			if(C[i] == J[i]) dp[i] = dp[i+1];
			else if(C[i] > J[i]) dp[i] = 1LL * ((C[i] - '0') - (J[i] - '0'))* pot - dpJ[i+1];
			else dp[i] = 1LL * ((J[i] - '0') - (C[i] - '0'))* pot - dpC[i+1];
		}
		else if(C[])
		pot *= 10;
	}
}*/

vector<ll> generate(string s) {
	vector<ll> res;
	if(s.size() == 1) {
		if(s[0] != '?') res.pb(s[0]-'0');
		else FOR(i,10) res.pb(i);
		return res; 
	}
	else {
		vector<ll> temp = generate(s.substr(0,s.size()-1));
		if(s[s.size()-1] != '?') {
			FOR(i,temp.size()) res.pb(temp[i]*10 + (s[s.size()-1]-'0'));
		}
		else {
			FOR(j,10)
				FOR(i,temp.size()) res.pb(temp[i]*10 + j);
		}
		return res;
	}
}

void solve() {
	string C, J;
	cin>>C>>J;
	vector<ll> v1 = generate(C), v2 = generate(J);
	//FOR(i,v1.size()) cout<<v1[i]<<" ";
	//cout<<endl;
	//FOR(i,v2.size()) cout<<v2[i]<<" ";
	//cout<<endl;
	ll best = 9999999, Cmin = 9999999, Jmin = 9999999;
	pair<ll,ll> kand;
	FOR(i,v1.size()) {
		FOR(j,v2.size()) {
			if(abs(v1[i]-v2[j]) < best ||
			   (abs(v1[i]-v2[j]) == best && v1[i] < Cmin) ||
			   (abs(v1[i]-v2[j]) == best && v1[i] == Cmin && v2[j] < Jmin)) {
				best = abs(v1[i]-v2[j]);
				Cmin = v1[i];
				Jmin = v2[j];
			}
		}
	}
	string Cres = "", Jres = "";
	FOR(i,C.size()) {
		Cres += (char)(Cmin%10 + '0');
		Jres += (char)(Jmin%10 + '0');
		Cmin/=10; Jmin/=10;
	}
	reverse(Cres.begin(), Cres.end());
	reverse(Jres.begin(), Jres.end());
	cout<<Cres<<" "<<Jres<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(0);

	int t;
	cin>>t;
	for(int i=1; i<=t; i++) {
		cout<<"Case #"<<i<<": ";
		solve();
	}	
	return 0;
}
