// Problem C

#include <iostream>
#include <string.h>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <math.h>
#include <fstream>
#include <set>
#include <map>
#include <string>

using namespace std;

typedef long long int ll;
typedef vector<int> vi;

void TestCase(int t);

int main() {
	int T;
	cin >> T;
	for (int t=1; t<=T; t++)
		TestCase(t);
	
	return 0;
}

void TestCase(int t) {
	map<string, int> MA, MB;
	string ma[1100], mb[1100];
	set<pair<string, string> > S;
	int tab[1100][1100];
	bool righe[1100], colonne[1100];
	
	for (int i=0; i<1100; i++) {
		righe[i] = false;
		colonne[i] = false;
	}
	
	for (int i=0; i<1100; i++)
		for (int j=0; j<1100; j++)
			tab[i][j] = 0;
	int N;
	cin >> N;
	int contA = 1; // righe
	int contB = 1; // colonne
	for (int i=0; i<N; i++) {
		string a, b;
		cin >> a >> b;
		if (MA.find(a) == MA.end()) {
			MA[a] = contA;
			ma[contA] = a;
			contA++;
		}
		if (MB.find(b) == MB.end()) {
			MB[b] = contB;
			mb[contB] = b;
			contB++;
		}
		tab[MA[a]][MB[b]]++;
		tab[MA[a]][0]++;
		tab[0][MB[b]]++;
		S.insert(make_pair(a, b));
	}
	
	int res = 0;
	
	// cancellazione degli uni singoli
	bool cont = 0;
	
	bool uscire = false;
	while (!uscire) {
		cont++;
		uscire = true;
		// righe
		for (int i=1; i<contA; i++)
			if (!righe[i] && tab[i][0] == 1) {
				uscire = false;
				int j = 1; // sarà la colonna
				while (tab[i][j] != 1) {
					assert(j < contB);
					j++;
				}
				righe[i] = true;
				colonne[j] = true;
				tab[i][0] = 0;
				tab[0][j] = 0;
				res++;
				// aggiorno quelli sulla colonna di j
				string strj = mb[j];
				vector< set<pair<string, string> >::iterator > rimuovere;
				for (set<pair<string, string> >::iterator it = S.begin(); it != S.end(); it++)
					if ((*it).second == strj) {
						int k = MA[(*it).first]; // riga
						tab[k][j] = 0;
						tab[k][0]--;
						
						rimuovere.push_back(it);
					}
				for (int k=0; k<rimuovere.size(); k++)
					S.erase(rimuovere[k]);
							
			}
		// colonne
		for (int i=1; i<contB; i++)
			if (!colonne[i] && tab[0][i] == 1) {
				uscire = false;
				int j = 1; // sarà la riga
				while (tab[j][i] != 1) {
					assert(j < contA);
					j++;
				}
				colonne[i] = true;
				righe[j] = true;
				tab[j][0] = 0;
				tab[0][i] = 0;
				res++;
				// aggiorno quelli sulla riga di j
				string strj = ma[j];
				vector< set<pair<string, string> >::iterator > rimuovere;
				for (set<pair<string, string> >::iterator it = S.begin(); it != S.end(); it++)
					if ((*it).first == strj) {
						int k = MB[(*it).second]; // colonna
						tab[j][k] = 0;
						tab[0][k]--;
						
						//S.erase(it);
						rimuovere.push_back(it);
					}
				for (int k=0; k<rimuovere.size(); k++)
					S.erase(rimuovere[k]);
			}
	}
	
	// conto le righe/colonne vuote e quelle piene ancora da sistemare
	int col = 0, rig = 0;
	for (int i=1; i<contA; i++) {
		if (tab[i][0] <= 0 && !righe[i]) res++;
		else if (!righe[i]) rig++;
	}
	for (int i=1; i<contB; i++) {
		if (tab[0][i] <= 0 && !colonne[i]) res++;
		else if (!colonne[i]) col++;
	}
	res += max(rig, col);
	cout << "Case #" << t << ": " << N-res << endl;
	//cout << "Cont = " << cont << endl;
}
