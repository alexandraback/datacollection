#include <bits/stdc++.h>
using namespace std;

#define MAXK 110

int T, K, S, L;
char keyboard[ MAXK ], target[ MAXK ];
vector< int >banane;

int Conta(string p) {
	int ris=0;
	for(int i=0; i+L <= S; i++) {
		bool ok=true;
		for(int j=0; j<L && ok; j++) if(p[i+j]!=target[j]) ok=false;
		if(ok) ris++;
	}
	return ris;
}
void Prova(int indice, string appo) {
	if(indice == S) {
		banane.push_back( Conta(appo) );
		return;
	}
	for(int i=0; i < K; i++) {
		appo.push_back( keyboard[ i ] );
		Prova(indice+1, appo);
		appo.pop_back();
	}
}
int main() {
	ios::sync_with_stdio(false);
	ifstream in("input.txt");
	ofstream out("output2.txt");
	in >> T;
	for(int i=1; i<=T;i++) {
		in >> K >> L >> S;
		in >> keyboard >> target;
		banane.clear();
		string tmp;
		tmp.clear();
		Prova(0, tmp);
		int massimo = *max_element(banane.begin(), banane.end());
		long double ans = 0.0;
		for(int j=0;j<(int)banane.size(); j++) ans += (massimo - banane[j]);
		ans /= (long double)banane.size();
		out << fixed << setprecision(9) << "Case #"<<i<<": "<<ans<<endl;
	}
	return 0;
}
