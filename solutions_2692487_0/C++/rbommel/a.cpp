#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("a.in");
ofstream fout("a.out");

int T, A, N;
long long int grootte[101];

int tryit(int k) {
	long long int h = (long long int) A;
	int i = 0;
	int ans = k;
	while (i < N-k) {
		if (h > grootte[N-k-1]) {
			return ans;
		}
		if (h > grootte[i]) {
			h += grootte[i];
			i++;
		} else {
			if (h-1 == 0)
				return (N+1);
			h += h-1;
			ans++;
		}	
		//cout << "h = " << h << " and ans = " << ans << '\n';
		if (ans > N)
			return ans;
	}
	return ans;
}

int main () {
	fin >> T;
	//cout << T << " cases\n";
	for (int i = 0; i < T; i++) {
		fin >> A >> N;
		for (int j = 0; j < N; j++) {
			fin >> grootte[j];
		}
		sort(grootte, grootte+N);
		int ans = 1234567;
		for (int j = 0; j <= N; j++) {
			if (j >= ans)
				break;
			//cout << "j = " << j << '\n';
			ans = min(ans, tryit(j));
		}
		//cout << "ANS: " << ans << '\n';
		fout << "Case #" << i+1 << ": " << ans << '\n';		
	}
	
	return 0;
}
