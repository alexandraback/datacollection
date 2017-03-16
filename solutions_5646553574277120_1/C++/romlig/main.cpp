#include <iostream>

using namespace std;

unsigned long solve(){
	unsigned long C, D, V;
	cin >> C >> D >> V;
	cerr << "CDV " << C << " " << D << " " << V << " " << endl;
	unsigned long i = 0;
	unsigned long max = 0;
	unsigned long added = 0;

	for (; i < D; i++){
		unsigned long b;
		cin >> b;
		while (max + 1 < b && max < V){
			//cerr << "ADD " << max + 1 << endl;
			max += C * (max + 1);
			added++;
		}
		max += C * b;
		if (max >= V) break;
	}
	for (i++ ; i < D; i++){
		unsigned long b;
		cin >> b;
	}
	while (max < V){
		//cerr << "ADD " << max + 1 << endl;
		max += C*(max + 1);
		added++;
	}

	return added;
}

int main(){
	unsigned long T;
	cin >> T;

	for (unsigned long i = 0; i < T; i++){
		cout << "Case #" << i + 1 << ": " << solve() << "\n";
	}

	cout << flush;

	return 0;
}