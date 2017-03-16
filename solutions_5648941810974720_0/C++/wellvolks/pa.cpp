#include <bits/stdc++.h>

using namespace std;

int qt[10000];
vector < string > vet;
string str, resp;

bool solve( int ult, string at, string ans ){
	if( at.size() == str.size() ){
		sort(at.begin(), at.end());
		if( at != str ) return false;
		resp = ans;
		return true;
	}
	if( at.size() > str.size() ) return false;
	for(int i = ult; i < 10; i++){
		if( solve( i, at + vet[i], ans + char(i+'0') ) ) return true;
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	int t, k = 1;
	cin >> t;
	vet.push_back("ZERO");
	vet.push_back("ONE");
	vet.push_back("TWO");
	vet.push_back("THREE");
	vet.push_back("FOUR");
	vet.push_back("FIVE");
	vet.push_back("SIX");
	vet.push_back("SEVEN");
	vet.push_back("EIGHT");
	vet.push_back("NINE");
	while( t-- ){
		cin >> str;
		sort(str.begin(), str.end());
		solve(0, "", "");
		cout << "Case #" << k++ << ": " << resp << '\n';
	}
	return 0;
}