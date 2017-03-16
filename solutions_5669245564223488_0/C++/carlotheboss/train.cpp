#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>
#include <cstdio>
using namespace std;

#define MAXN 110
#define MOD 1000000007

int T, N;
unsigned long long sol;
bool connesse[MAXN];
char stringhe[MAXN][MAXN];
int occorrenze[30];
int spec[MAXN][30];

void Prova(int fatte, char last, int ultima) {
	
	if(fatte== N) { sol = (sol+1) % MOD; return; }
	for(int i=0; i < N; i++) {
		
		if(!connesse[i]) {
			//cout<<"Fatte: "<<fatte<<" Ultima: "<<stringhe[ultima]<<" Last: "<<last<<endl;
			//cout<<"Controllo "<<stringhe[i]<<endl;
			bool posso=true;
			if(fatte > 0) {
				if(occorrenze[ last - 'a' ] > 0) {
					if(stringhe[i][0] != last) {
						//cout<<"Non la posso accodare.\n";
						 continue;
					 }
				}
			}
			int prova[30];
			memset(prova, 0, sizeof(prova));
			//cout<<"Ultimo carattere esatto.\n";
			for(int j=0; j < (int)strlen(stringhe[i]) - 1 && posso; j++) {
				prova[ stringhe[i][j] - 'a']++;
				if(stringhe[i][j]==stringhe[i][j+1]) continue;
				if( spec[i][stringhe[i][j] - 'a'] < occorrenze[ stringhe[i][j] - 'a']) posso=false;
				if(j>0 && prova[stringhe[i][j-1] - 'a'] < spec[i][stringhe[i][j-1] - 'a']) posso=false;
			   
		    }
			if(!posso) {
				//cout<<"Caratteri interni incompatibili.\n";
				continue;
			}
			//cout<<"Caratteri interni esatti.\n";
			//cout<<"Accodo.\n";
			connesse[i]=true;
			for(int j=0; j < (int)strlen(stringhe[i]); j++) occorrenze[ stringhe[i][j] - 'a']--;
			Prova(fatte+1, stringhe[i][ (int)strlen(stringhe[i]) - 1], i );
			connesse[i]=false;
			for(int j=0; j < (int)strlen(stringhe[i]); j++) occorrenze[ stringhe[i][j] - 'a']++;
		}
	}
}
int main() {
	//ofstream out("output.txt");
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for(int i=0; i < T; i++) {
		
		memset(occorrenze, 0, sizeof(occorrenze) );
		memset(spec, 0, sizeof(spec));
		memset(connesse, 0, sizeof(connesse));
		cin >> N;
		sol=0;
		for(int j=0; j < N; j++) { 
			cin >> stringhe[j]; 
			for(int k=0; k < (int)strlen(stringhe[j]); k++) {
				spec[j][stringhe[j][k] - 'a']++;
				occorrenze[ stringhe[j][k] - 'a']++;
			}
		}
		//cout<<"Caso "<<i+1<<endl;
		Prova(0, '\0', 0);
		cout<<"Case #"<<i+1<<": "<<sol%MOD<<endl;	
	}
	return 0;
}
