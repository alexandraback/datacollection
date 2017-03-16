#include <bits/stdc++.h>
using namespace std;
typedef long long Long;
Long power(Long b, Long p) {
	if(p == 0) return 1;
	if(p % 2 == 1) return (power(b, p - 1) * b);
	Long r = power(b, p / 2);
	return r * r;
} 

int main(int argc, char const *argv[])
{
	freopen("sublime-in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	int t, cs = 0;
	cin >> t;
	while(t--) {
		int K, C, S;
		cin >> K >> C >> S;
		int cnt = 0;
		for(int i = 1; i <= K; i += 2) {
			cnt += 1;
		}
		cout << "Case #" << ++cs << ": ";
		if(C == 1) {
			if(S == K) {
				for(int i = 1; i <= K; i++) cout << i << " ";
				cout << endl;
			} else {
				cout << "IMPOSSIBLE" << endl;
			}
			continue;
		}
		if(cnt > S) {
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		for(int i = 1; i <= K; i += 2) {
			Long Q = power(K, C - 1) * Long(i - 1) + i;
			if(i + 1 <= K) Q += 1;
			cout << Q << " ";
		}
		cout << endl;
	}
	return 0;
}