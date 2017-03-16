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

vector<char> consist[42];
vector<int> order = {0,2,6,8,7,5,4,1,3,9};

void solve(vector<char> check) {
	string s;
	cin>>s;
	//cout<<"s "<<s<<endl;
	vector<int> cnt;
	cnt.resize(142);
	FOR(i,s.size()) {
		cnt[s[i]-'A'] ++;
	}
	vector<int> res;
	FOR(i,order.size()) {
		int digit = order[i];
		while(cnt[check[digit] - 'A'] > 0) {
			res.pb(digit);
			FOR(j,consist[digit].size()) cnt[consist[digit][j] - 'A']--;
		}
	}
	//cout<<"res.size() "<<res.size()<<endl;
	sort(res.begin(), res.end());
	FOR(i,res.size())cout<<res[i];
	cout<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	consist[0] = {'Z','E','R','O'};
	consist[1] = {'O','N','E'};
	consist[2] = {'T','W','O'};
	consist[3] = {'T','H','R','E','E'};
	consist[4] = {'F','O','U','R'};
	consist[5] = {'F','I','V','E'};
	consist[6] = {'S','I','X'};
	consist[7] = {'S','E','V','E','N'};
	consist[8] = {'E','I','G','H','T'};
	consist[9] = {'N','I','N','E'};
	vector<char> check = {'Z','O','W','T','F','V','X','S','G','N'};
	int t;
	cin>>t;
	for(int i=1; i<=t; i++) {
		cout<<"Case #"<<i<<": ";
		solve(check);
	}	
	return 0;
}
