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
			contA++;
		}
		if (MB.find(b) == MB.end()) {
			MB[b] = contB;
			contB++;
		}
		tab[MA[a]][MB[b]]++;
		tab[MA[a]][0]++;
		tab[0][MB[b]]++;
	}
	
	int res = 0;
	
	// cancellazione degli uni singoli
	bool uscire = false;
	while (!uscire) {
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
				for (int k=1; k<contA; k++) {
					if (tab[k][j] > 0) {
						tab[k][j] = 0;
						tab[k][0]--;
					}
				}				
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
				for (int k=1; k<contB; k++) {
					if (tab[j][k] > 0) {
						tab[j][k] = 0;
						tab[0][k]--;
					}
				}				
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
}
