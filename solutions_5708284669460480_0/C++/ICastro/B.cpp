#include <bits/stdc++.h>
using namespace std;

#define size(v) int(v.size())
#define MOD 1000003
#define INF 1e9
#define ulint unsigned long long int
#define lint long long int
#define mp make_pair
#define pb push_back
#define pop pop_back
#define st first
#define nd second
#define all(X) (X).begin(),(X).end()
#define E12 1000000000000

struct min_heap_comparator{
	bool operator()(const long& a,const long& b) const{
		return a>b;
	}
};
#define mh_min(X) make_heap(all(X), min_heap_comparator());
#define poph_min(X) {pop_heap(all(X), min_heap_comparator()); (X).pop();}
#define pushh_min(X, Y) {(X).pb(Y); push_heap(all(X), min_heap_comparator());}
#define sorth_min(X) sort_heap(all(X), min_heap_comparator());

#define mh_max(X) make_heap(all(X));
#define poph_max(X) {pop_heap(all(X)); (X).pop();}
#define pushh_max(X, Y) {(X).pb(Y); push_heap(all(X));}
#define sorth_max(X) sort_heap(all(X));

vector<string> func(const vector<lint> &vet, lint p){
	if (p == 0){
		vector<string> aux;
		aux.pb("");
		return aux;
	}
	vector<string> aux = func(vet, p-1);
	vector<string> sai;
	for (lint i = 0; i < 26; ++i){
		lint v = vet[i];
		while (v > 0){
			for (lint j = 0; j < size(aux); ++j){
				sai.pb(char('A' + i) + aux[j]);
			}
			v--;
		}
	}
	return sai;
}

lint conta(string target, string s){
	lint cont = 0;
	for (lint i = 0; i < size(s) - size(target) + 1; ++i){
		lint j = 0;
		lint k = i;
		while (j < size(target) && s[k] == target[j]){
			j++;
			k++;
		}
		if (j == size(target)){
			cont ++;
		}
	}
	return cont;
}

int main(void){
	lint T;
	cin >> T;
	for (lint t = 0; t < T; ++t){
		lint K, L, S;
		cin >> K >> L >> S;
		string keyboard, target;
		cin >> keyboard;
		cin >> target;
		vector<lint> vet(26, 0);
		for (lint i = 0; i < size(keyboard); ++i){
			vet[keyboard[i] - 'A']++;
		}
		bool possivel = true;
		for (lint i = 0; i < size(target); ++i){
			if (vet[target[i] - 'A'] == 0){
				possivel = false;
				break;
			}
		}
		if (!possivel){
			cout << "Case #" << t+1 << ": 0.0" << endl;
			continue;
		}
		vector<string> todas = func(vet, S);
		lint cont = 0;
		lint max = 0;
		for (lint i = 0; i < size(todas); ++i){
			//cout << todas[i] << endl;
			lint v = conta(target, todas[i]);
			/*if (v == 3 && i < 100000){
				cout << todas[i] << " "<< v << endl;
			}*/
			//cout << v << endl;
			cont += v;
			if (v > max) max = v;
		}

		/*string aux = target;
		int a = size(aux);
		int j = 1;
		int k = 0;
		int cont = 1;
		while (a < S){
			do {
				k = 0;
				while (j < size(aux) && aux[j] != target[k]){
					++j;
				}
				while (j < size(aux) && aux[j] == target[k]){
					++j;
					++k;
				}
			} while (j != size(aux));
			while (k < size(target) && a < S){
				aux.pb(target[k]);
				++k;
				++a;
			}
			if(k == size(target)) cont++;
			j++;
		}
		cout << aux << " " << cont << endl;
		for (int i = 0; i < size(target); ++i){
			ld += 1.0/vet[target[i] - 'A'];
		}
		vector<int> pd(S + 1);
		for (int i = 0; i < size(target); ++i){
			pd[i] = 0;
		}
		for (int i = size(target); i <= S; ++i){
			pd[i] = pd[i - size(target)] + ld;;
		}

		long double ld = 0;
*/

		//cout << "Case #" << t+1 << ": " << max << " " << cont << " " << size(todas) << endl;
		cout << "Case #" << t+1 << ": " << max - 1.0*cont/size(todas) << endl;
	}
	return 0;
}
