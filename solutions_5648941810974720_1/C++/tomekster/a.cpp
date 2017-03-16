#include "headers.h"
string a[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
string s;
int tab[40];
vector <int> res;
int main(){
	int T;
	cin >> T;
	REP(t, T){
		res.clear();
		cin >> s;
		REP(i,s.size()){
			tab[s[i]-'A']++;
		}

		while(tab['Z' - 'A']){
			res.PB(0);
			REP(i,a[0].size()){
				tab[a[0][i] - 'A']--;
			}
		}
		while(tab['X' - 'A']){
			res.PB(6);
			REP(i,a[6].size()){
				tab[a[6][i] - 'A']--;
			}
		}
		while(tab['W' - 'A']){
			res.PB(2);
			REP(i,a[2].size()){
				tab[a[2][i] - 'A']--;
			}
		}
		while(tab['S' - 'A']){
			res.PB(7);
			REP(i,a[7].size()){
				tab[a[7][i] - 'A']--;
			}
		}
		while(tab['V' - 'A']){
			res.PB(5);
			REP(i,a[5].size()){
				tab[a[5][i] - 'A']--;
			}
		}
		while(tab['F' - 'A']){
			res.PB(4);
			REP(i,a[4].size()){
				tab[a[4][i] - 'A']--;
			}
		}
		while(tab['O' - 'A']){
			res.PB(1);
			REP(i,a[1].size()){
				tab[a[1][i] - 'A']--;
			}
		}
		while(tab['N' - 'A']){
			res.PB(9);
			REP(i,a[9].size()){
				tab[a[9][i] - 'A']--;
			}
		}
		while(tab['I' - 'A']){
			res.PB(8);
			REP(i,a[8].size()){
				tab[a[8][i] - 'A']--;
			}
		}
		while(tab['T' - 'A']){
			res.PB(3);
			REP(i,a[3].size()){
				tab[a[3][i] - 'A']--;
			}
		}
		sort(res.begin(), res.end());
		cout << "Case #" << t+1 << ": ";
		REP(i,res.size()) cout << res[i];
		cout << endl;
	}
}
