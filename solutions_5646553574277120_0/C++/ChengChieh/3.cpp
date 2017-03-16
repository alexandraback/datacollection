#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int T, C, D, V;
int S[143];
bool F[143];

int main() {
	freopen("input3.txt", "r", stdin);
	freopen("output3.txt", "w", stdout);
	cin >> T;
	for (int test = 1; test <= T; test++) {
		cin >> C >> D >> V;
		int ans = 0;
		for (int i = 0; i < D; i++) cin >> S[i];
		while (1) {
			for (int i = 0; i <= V; i++) F[i] = false;
			F[0] = true;
			for (int i = 0; i < D; i ++) {
				for (int k = 1; k <= C; k++) {
        			for (int j = V; j >= 0; j --) {
            			if(j >= S[i] * k)
                			F[j] = F[j-S[i] * k] || F[j];
                	}
            	}
            }
            int flag = true;
            for (int j = 1; j <= V; j++)
            	if (F[j] == false) {
            		flag = false;
            		ans ++;
            		S[D++] = j;
            		break;
            	}
            if (flag == true) break;
		}
		cout << "Case #" << test << ": " << ans << endl;
	}
	return 0;
}
