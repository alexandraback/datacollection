#include <iostream>

using namespace std;

int solve(){
	int C, D, V;
	cin >> C >> D >> V;
	cerr << "CDV " << C << D << V << endl;
	int i = 0;
	int max = 0;
	int added = 0;

	for (; i < D; i++){
		int b;
		cin >> b;
		while (max + 1 < b && max < V){
			cerr << "ADD " << max + 1 << endl;
			max += C * (max + 1);
			added++;
		}
		max += C * b;
		if (max >= V) break;
	}
	for (i++ ; i < D; i++){
		int b;
		cin >> b;
	}
	while (max < V){
		cerr << "ADD " << max + 1 << endl;
		max += C*(max + 1);
		added++;
	}

	return added;
}

int main(){
	int T;
	cin >> T;

	for (int i = 0; i < T; i++){
		cout << "Case #" << i + 1 << ": " << solve() << "\n";
	}

	cout << flush;

	return 0;
}