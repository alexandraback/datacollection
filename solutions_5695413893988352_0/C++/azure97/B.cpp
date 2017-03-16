#include <bits/stdc++.h>
using namespace std;

long long getVal(string str) {
	long long res = 0;
	for(int i = 0 ; i < str.length() ; i++) {
		res = res * 10 + (str[i] - '0');
	}
	return res;
}

long long get(string &C,string &J,int beda) {
	for(int i = 0 ; i < beda ; i++) {
		if(C[i] == '?' && J[i] != '?')
			C[i] = J[i];
		else if(C[i] != '?' && J[i] == '?')
			J[i] = C[i];
		else if(C[i] == '?' && J[i] == '?')
			C[i] = J[i] = '0';
	}
	int opt = C[beda] > J[beda];
	for(int i = beda + 1 ; i < C.length() ; i++) {
		if(C[i] == '?') {
			if(opt) C[i] = '0';
			else C[i] = '9';
		}
		if(J[i] == '?') {
			if(opt) J[i] = '9';
			else J[i] = '0';
		}
	}
	long long a = getVal(C);
	long long b = getVal(J);
	return abs(a-b);
}

int main() {
	int t; cin >> t;
	for(int tc = 1 ; tc <= t ; tc++) {
		string C,J;
		cin >> C >> J;
		pair<long long,pair<string,string> > ans;
		ans.first = 4e18;
		bool adaBeda = 0;
		for(int i = 0 ; i <C.length() ; i++)
			if(C[i] != '?' && J[i] != '?' && C[i] != J[i]) {
				adaBeda = 1;
			}
		if(adaBeda) {	
			for(int beda = 0 ; beda < C.length() ; beda++) { 
				if(beda > 0 && C[beda-1] != '?' && J[beda-1] != '?' && C[beda-1] != J[beda-1]) {
					break;
				}
				for(int i = 0 ; i <= 9 ; i++)
					for(int j = 0 ; j <= 9 ; j++) {
						if(i == j) continue;
						if(C[beda] != '?' && C[beda] - '0' != i) continue;
						if(J[beda] != '?' && J[beda] - '0' != j) continue;
						string Cnow = C;
						string Jnow = J;
						Cnow[beda] = i + '0';
						Jnow[beda] = j + '0';
						//cout << Cnow << " " << Jnow << "\n";
						long long cur = get(Cnow,Jnow,beda);
						//cout << Cnow << " " << Jnow << "\n";
						pair<long long,pair<string,string> > now = {cur,{Cnow,Jnow}};
						//cout << cur << endl;
						ans = min(ans,now);
					}
			}	
		}	
		else {
			long long temp = get(C,J,C.length());
			ans = min(ans,{temp,{C,J}});
		}
		printf("Case #%d: %s %s\n",tc,ans.second.first.c_str(),ans.second.second.c_str());	
	}
	return 0;
}