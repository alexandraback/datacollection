#include <map>
#include <vector>
#include <iostream>
using namespace std;

int main() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case #" << t << ":" << endl;
		bool flag = false;
		int N;
		cin >> N;
		int vec[N];
		map <int, vector< int > > Map;
		for (int i = 0; i < N; i++) {
			cin >> vec[i];
		}
		for (int i = 1; i < 1<<N; i++) {
			vector< int > V;
			int sum = 0;
			for (int j = 0; j < N; j++) {
				if (i & 1<<j) {
				   	  sum += vec[j];
				   	  V.push_back(vec[j]);
	   			}
			}
			if (Map.find(sum) != Map.end()) {
   			   for (int k = 0; k < V.size(); k++) {
		   	   	   if (k) cout << " ";
	   	   		   cout << V[k];
   				}
   				cout << endl;
   				V = Map[sum];
   				for (int k = 0; k < V.size(); k++) {
		   	   	   if (k) cout << " ";
	   	   		   cout << V[k];
   				}
   				cout << endl;
   				flag = true;
   				break;
			}
			else {
				 Map[sum] = V;
		 	}
		}
		if (!flag) cout << "Impossible" << endl;
	}

	return 0;
}
