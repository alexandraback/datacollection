#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

long long ans[1000] = { 0 };
long long B, M;
long long w[51][51];

long long rec(long long i) {
	if (ans[i]) return ans[i];

	if (i == B-1) {
		ans[i] = 1;
		return 1;
	}
	else
	{
		long long sum = 1;
		for (int j = i + 1; j <= B-1; j++)
			sum += rec(j);
		return sum;
	}
}

void fillFull(long long p) {
	for (int i = 2; i <= p; i++)
		for (int j = i + 1; j <= p; j++)
			w[j][i] = 1;
	for (int i = 2; i <= p; i++)
		w[1][i] = 1;
	for (int i = 1; i <= p; i++)
		w[i][B] = 1;
}

void main() {

	FILE *str, *abc;
	freopen_s(&str, "input.txt", "r", stdin);
	freopen_s(&abc, "out.txt", "w", stdout);

	int t;
	cin >> t;
	
	for (int tt = 0; tt < t; tt++) {
		cout << "Case #" << tt + 1 << ": ";
		

		cin >> B >> M;
		long long sum = 1;

		for (int i = 1; i <= B - 2; i++)
			sum *= 2;

		if (M > sum) cout << "IMPOSSIBLE" << endl;
		else {
			cout << "POSSIBLE" << endl;
			memset(w, 0, sizeof(w));
			long long p2 = 1, p = 0;
			if (M > 0) {
				
				while (p2 <= M) {
					p2 *= 2;
					p++;
				}
				p--;
				p2 /= 2;
				//for (int i = 2; i <= B - 1; i++)
				//	w[1][i] = 1;

				M -= p2;
				p++;
				fillFull(p);
			}
			
			if (M > 0) {
				M--;
				w[p + 1][B] = 1;
				w[1][p + 1] = 1;
				while (M > 0) {

					long long dig = 1;
					long long num = 1;
					while (dig * 2 <= M) {
						dig *= 2;
						num++;
					}

					w[p + 1][num+1] = 1;
					M -= dig;
				}
			}


			for (int i = 1; i <= B; i++) {
				for (int j = 1; j <= B; j++)
					cout << w[i][j];
				cout << endl;
			}
				
		}
			
		

	}
		
}