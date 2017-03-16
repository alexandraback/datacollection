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


int main(void){
	lint T;
	cin >> T;
	for (lint t = 0; t < T; ++t){
		lint C, D, V;
		cin >> C >> D >> V;
		vector<lint> vet(D);

		for (lint i = 0; i < D; ++i){
			cin >> vet[i];
		}
		lint aux = 0;
		lint aux2 = 0;
		lint j = 0;
		lint cont = 0;
		for (lint i = 1; i <= V; ++i){
			if(aux2 < i){
				if (j == D || vet[j] > i){
					cont++;
					aux += i;
					aux2 += C*i;
				} else {
					aux += vet[j];
					aux2 += C*vet[j];
					++j;
				}
				i = aux2;
			}
		}

		cout << "Case #" << t+1 << ": " << cont << endl;
	}
	return 0;
}
