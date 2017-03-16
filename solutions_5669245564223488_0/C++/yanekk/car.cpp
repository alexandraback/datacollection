#include <iostream>
#include <vector>
#include <string>

using namespace std;

int Odw[40];
vector <string> W[40];
pair <int,int>  PO[40];
long long Silnia[120];
long long Sp[120];

bool SprawdzCzySieDa(){
	int i,j,k;
	int wch,wych,wsrodku;
	int a_litera,p_lit,o_lit,roznych,ost;
	string slowo;
	for(i=0; i<27; i++){
		wch = 0;
		wych = 0;
		p_lit = i;
		o_lit = i;
		roznych = 0;
		for(j=0; j<W[i].size(); j++){
			slowo = W[i][j];
			ost = (int)slowo[0]-(int)'a';
			//cout << slowo << " ";
			if( ost != i ) {
				wch++;
				p_lit = ost;
			}
			wsrodku = -1;
			for(k=0; k<slowo.size(); k++){
				a_litera = (int)slowo[k]-(int)'a';
				if( a_litera != ost ) {
					wsrodku++;
					if( wsrodku >= 1 ) Odw[ ost ] = 1;
					ost = a_litera;
				}
				
			}
			if(wsrodku >= 1) roznych++;
			if( a_litera != i ) {
				wych++;
				o_lit = a_litera;
			}
			//cout << i << "->" << a_litera << " || " << wych << " " << wch << " " << roznych << "\n";
			if( wych>1 || wch>1 || roznych > 1) return false;
			Sp[i] = Silnia[ W[i].size()-wych-wch ];
			PO[i].first = p_lit;
			PO[i].second = o_lit; 
		}
		//cout << "\n";
	}
	return true;
}

int main(){
	string slowo;
	bool czy;
	int t,n;
	int v,blok,i,j,k,ile;
	long long komb,wynik;
	Silnia[0] = 1;
	Silnia[1] = 1;
	for(i=2; i<=110; i++){
		Silnia[i] = Silnia[i-1]*(long long)i;
		Silnia[i] %= 1000000000+7;
	}
	cin >> t;
	for(i=0; i<t; i++){
		cin >> n;
		for(k=0; k<30; k++) {
			W[k].clear();
			Odw[k] = 0;
			PO[k].second = 0;
			Sp[k] = 0;
		}
		for(j=0; j<n; j++){
			cin >> slowo;
			for(k=0; k<30; k++) Odw[k] = 0;
			for(k=0; k<slowo.size(); k++){
				if( Odw[(int)slowo[k]-(int)'a'] == 0 ) {
					W[ (int)slowo[k]-(int)'a' ].push_back( slowo );
					Odw[(int)slowo[k]-(int)'a'] = 1;
				}
			}
		}
		for(k=0; k<30; k++) {
			if( W[k].size() > 0 ) Odw[k] = 0;
			else Odw[k] = 1;
		}
		czy = SprawdzCzySieDa();
		if( czy ){
			blok = 0;
			wynik = 1;
			for(j=0; j<28; j++){
				v = j;
				komb = 1;
				if( !Odw[v] ) blok++;
				while( !Odw[v] ){
					komb *= Sp[v];
					komb %= 1000000000+7;
					Odw[v] = 1;
					v = PO[v].second;
				}
				wynik *= komb;
				wynik %= 1000000000+7;
			}
			//cout << blok << "\n";
			cout << "Case #" << i+1 << ": " << (Silnia[blok]*wynik)%(1000000000+7) << "\n";
		}
		else{
			cout << "Case #" << i+1 << ": 0\n";
		}
	}
	return 0;
}
