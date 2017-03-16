#include<bits/stdc++.h>
using namespace std;
 int T, N, J, P, S, K, cnt;
	
 
int main() {
	freopen("C-small-attempt3.in","r",stdin);
    freopen("fil.out","w",stdout);
    
	cin >> T;
 
	for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		cin >> J >> P >> S >> K;
		cout << J*P*min(S, K) << "\n";
		int** ary = new int*[J];
		for(int i = 0; i < J; ++i)
    		ary[i] = new int[P];
		for (int j=0; j<J; j++) {
			for (int p=0; p<P; p++) {
				for (cnt = 0; cnt < min(K, S); cnt++) {
					cout << j+1 << " " << p+1 << " " << (ary[j][p])%S + 1 << "\n";
					ary[j][p] ++;
				}
			}
		} 
	}
	return 0;
}