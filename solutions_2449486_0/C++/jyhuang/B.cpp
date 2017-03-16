#include <iostream>

using namespace std;

int n, m;
int a[128][129];

bool check()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			bool c1 = true, c2 = true;
			for (int k = 0; k < m && c1; k++)
				if (a[i][k] > a[i][j]) c1 = false;
			for (int k = 0; k < n && c2; k++)
				if (a[k][j] > a[i][j]) c2 = false;
			if (!(c1 || c2)) return false;
		}
	return true;
}

int main(int argc, char *argv[])
{
	int T;
	cin >> T;

	for (int ti = 0; ti < T; ti++) {
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) cin >> a[i][j];
		cout << "Case #" << (ti + 1) << ": " << (check() ? "YES" : "NO") << endl;
	}
	return 0;
}
