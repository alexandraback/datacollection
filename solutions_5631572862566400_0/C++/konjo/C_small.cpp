#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		int N;
		int ans = 0;
		vector<int> F;
		cin >> N;
		F.resize(N);
		for(int i = 0; i < N; i++) {
			cin >> F[i];
			F[i]--;
		}

		/*
		cout << N << endl;;
		for(int i = 0; i < F.size(); i++)
			cout << F[i] << " ";
		cout << endl;
		// */
		
		vector<int> v;
		v.resize(N);
		for(int i = 0; i < N; i++) {
			v[i] = i;
		}
		sort(v.begin(), v.end());

		do {
			for(int i = 1; i < v.size(); i++) {
				if((F[v[i]] == v[i-1] || F[v[i]] == v[0]) && (F[v[0]] == v[1] || F[v[0]] == v[i]))
					ans = max(i+1, ans);

				if(v[i-1] != F[v[i]] && v[(i+1)%v.size()] != F[v[i]])
					break;
			}
		} while(next_permutation(v.begin(), v.end()));

		cout << "Case #" << t << ": " << ans << endl;
	}
}
