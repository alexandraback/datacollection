#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > Graph ;
vector<int> Test ;

int explore(int k) {
	if (Test[k]) {
		return 1 ;
	}
	else {
		Test[k] = 1 ;
		int a = 0 ;
		for (int i = 0 ; i < Graph[k].size() ; i++) {
			if (explore(Graph[k][i])) {
				a = 1 ;
				break ;
			}
		}
		return a ;
	}
}

int main() {

	int T ;
	
	cin >> T ;
	for (int _i = 1 ; _i <= T ; _i++ ) {
		int N ;
		cin >> N ;
		Graph.resize(N) ;
		for (int i = 0 ; i < N ; i++) {
			Graph[i].resize(0) ;
		}
		for (int i = 0 ; i < N ; i++) {
			int t ;
			cin >> t ;
			for (int j = 0 ; j < t ; j++) {
				int tt ;
				cin >> tt ;
				Graph[tt-1].push_back(i) ;
			}
		}
		Test.resize(N) ;
		int result = 0 ;
		
		for (int i = 0 ; i < N ; i++) {
			for (int j = 0 ; j < N ; j++) {
				Test[j] = 0 ;
			}
			if (explore(i)) {
				result = 1 ;
			}
			
		}
		
		cout << "Case #"<< _i<<": ";
		if (result) {
			cout << "Yes" << endl ;
		}
		else {
			cout << "No" << endl ;
		}
		
	}
	
	return 0 ;
}
