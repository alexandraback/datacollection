#include <bits/stdc++.h>
#define ll long long
#define mst(a,x) memset(a,x,sizeof(a))
#define For(i, t) for(int i = 0; i < t; i++)
#define Debug(x) cerr << #x << " = "  << x << endl;
using namespace std;

string ans, a, A, B;

int main() {
	int T;

	freopen("out.txt", "w", stdout);
	scanf("%d", &T);
	For(cas, T) {
		cin >> a;
		int n = a.length();
		ans = "";
		For(i, n) {
			A = ans + string(1, a[i]);
			B = string(1, a[i]) + ans;
			//cout << "A = " << A << "\n";
			//cout << "B = " << B << "\n";
			if(A > B) ans = A;
			else ans = B;
		}
		printf("Case #%d: ", cas + 1);
		cout << ans << "\n";
	}

	return 0;
}
