#include<iostream>
#include<bitset>
#include<cmath>
#include<vector>

using namespace std;

typedef long long ll;

ll fac(int n){
	ll x=1;
	for (int i = 2;i <= n; i++)	x *= i;
	return x;
}

bool is_legal(vector<int>& per, int bff[])
{
	int l = per.size();
	if (l<2) return false;
	for (int i = 0; i < l; i++) {
		if ( per[(i+1)%l] == bff[per[i]] || bff[per[i]] == per[(i-1+l)%l] ) {}
		else return false;
	}
	return true;
}

void generate_per(vector<int>& s) {
	int n = s.size();
	int i = n-1;
	while (s[i]<s[i-1]) i--;
	i--;
	int j = n-1;
	while (s[j]<s[i])	j--;
	int t = s[i];
	s[i] = s[j];
	s[j] = t;
	int k = i+1, m = n-1;
	while(k<m) {
		int t1 = s[k];
		s[k] = s[m];
		s[m] = t1;
		k++;
		m--;
	}
}

string convert2bin(int x, int n)
{
	string bin = "";
	while (x!=0) {
		bin = (char)(x%2+'0') + bin;
		x /= 2;
	}
	while (bin.length() < n)	bin = '0' + bin;
	return bin;
}

int main()
{
	int t; cin >> t;
	for (int i = 1; i <= t; i++) {
		int n; cin >> n;
		int bff[n+1];
		int max = 0;
		for (int j = 1; j <= n; j++ )	cin >> bff[j];
		for (int j = 0; j < pow(2,n); j++) {
			string foo = convert2bin(j,n);
			vector<int> group;
			for (int k = 0; k < n; k++) {
				if (foo[k]=='1')	group.push_back(k+1);
			}
			if (group.size()<2) continue;

			vector<int> permut(group);
			int len = permut.size();
			ll limit = fac(len-1);
			for (ll k = 1; k <= limit; k++) {
				if(is_legal(permut,bff) && len > max) max = len;
				generate_per(permut);
			}
		}
		cout << "Case #" << i << ": " << max << "\n";
	}
}
