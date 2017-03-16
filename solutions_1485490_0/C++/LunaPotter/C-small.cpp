/*************************************************************************
    > File Name: C-small.cpp
    > Created Time: 日  5/ 6 17:34:40 2012
 ************************************************************************/

#include<iostream>
using namespace std;

long long A[3][2], B[100][2];

int main() {
	int Ncase;
	cin >> Ncase;
	for(int T = 1; T <= Ncase; T ++) {
		int n, m;
		long long ans = 0;
		cin >> n >> m;
		for(int i = 0; i < n; i ++)
			cin >> A[i][1] >> A[i][0];
		for(int i = 0; i < m; i ++)
			cin >> B[i][1] >> B[i][0];
		for(int i = 0; i <= m; i ++)
			for(int j = i; j <= m; j ++) {
				long long x, y, z, left0, left1;
				left0 = left1 = 0;
				x = y = z = 0;
				if(n >= 1) {
					for(int k = 0; k < i; k ++)
						if(A[0][0] == B[k][0]) x += B[k][1];
					if(x > A[0][1]) {
						left1 = x - A[0][1];
						x = A[0][1];
						left0 = A[0][0];
					}
					if(n >= 2) {
						if(left0 == A[1][0]) {
							y += left1;
						}
						for(int k = i; k < j; k ++)
							if(A[1][0] == B[k][0]) y += B[k][1];
						if(y > A[1][1]) y = A[1][1];
						if(y != 0) {
							left0 = left1 =0;
						}
						if(y > A[1][1]) {
							left1 = y - A[1][1];
							y = A[1][1];
							left0 = A[1][0];
						}
						if(n >= 3) {
							if(left0 == A[2][0]) {
								z += left1;
							}
							for(int k = j; k < m; k ++)
								if(A[2][0] == B[k][0]) z += B[k][1];
							if(z > A[2][1]) z = A[2][1];
						}
					}
				}
				if(ans < x + y + z) ans = x + y + z;
			}
		cout << "Case #" << T << ": " << ans << endl;
	}
	return 0;
}
