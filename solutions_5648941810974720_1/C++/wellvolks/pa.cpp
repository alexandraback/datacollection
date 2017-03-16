#include <bits/stdc++.h>

using namespace std;

int qt[10000];
vector < string > vet;
string str, resp;
vector < int > obj;

bool solve( int ult, vector < int > qtd, string ans ){
	if( qtd == obj ){
		resp = ans;
		return true;
	}
	for(int i = ult; i < 10; i++){
		bool ok = true;
		vector < int > novo;
		for(int j = 0; j < 26; j++){
			int t = count(vet[i].begin(), vet[i].end(), char(j+'A'));
			if( qtd[j]+t > obj[j] ){
				ok = false;
				break;
			}
			novo.push_back(qtd[j]+t);
		}
		if( ok && solve( i, novo, ans + char(i+'0') ) ) return true;
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
		vector < int > novo;
		for(int i= 0; i < 26; i++){
			int q = count(str.begin(), str.end(), char(i+'A'));
			obj.push_back(q);
			novo.push_back(0);
		}
		solve(0, novo, "");
		cout << "Case #" << k++ << ": " << resp << '\n';
		obj.clear();
	}
	return 0;
}