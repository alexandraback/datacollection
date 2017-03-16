#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

#define cin fin
#define cout fout
int n, m, T;
int a[100], f[4000];
int dp(){
	memset(f, 0, sizeof(f));
	f[0] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = m; j >= a[i]; --j)
			f[j] |= f[j - a[i]];
	for (int i = 1; i <= m; ++i)
		if (!f[i])
			return i;
	return m + 1;
}

int main() {
	ifstream fin("haha.in");
	ofstream fout("output.out");
	int T;
	cin >> T;
	for (int i = 0; i<T; i++) {
			int x, t;
			cin >> x >> n >> m;
			t = n;
			for (int j = 1; j <= n; ++j)
				cin >> a[j];
			while (1){
				x = dp();
				printf("%d\n", x);
				if (x > m)break;
				a[++n] = x;
			}
			int ans = n - t;
		cout << "Case #" << i + 1 << ": " << ans << endl;

	}
	fin.close();
	fout.close();
	system("pause");
	return 0;
}
