#include<bits/stdc++.h>

using namespace std;
#define For(i,l,r) for (int i = l; i <= r; ++i)

char A[1111];
int n;
int main() {
	int T; cin >> T;
	For(TK,1,T) {
		printf("Case #%d: ", TK);
		scanf("%s", A + 1);
		n = strlen(A + 1);
		string cur(1, A[1]);
		For(i,2,n) {
			string n1 = cur + A[i];
			string n2 = string(1,A[i]) + cur;
			cur = max(n1, n2);
		}
		cout << cur << endl;
	}
	return 0;
}
