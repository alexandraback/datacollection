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
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t){
		int C, D, V;
		cin >> C >> D >> V;
		vector<int> vet(D);

		for (int i = 0; i < D; ++i){
			cin >> vet[i];
		}
		int aux = 0;
		int aux2 = 0;
		int j = 0;
		int cont = 0;
		for (int i = 1; i <= V; ++i){
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
			}
		}

		cout << "Case #" << t+1 << ": " << cont << endl;
	}
	return 0;
}
