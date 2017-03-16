#include <iostream>
using namespace std;

long a, n;
long t[105];
long op;

int check(long s1, long s2, int &ns) {
	int k = 0;
	if(s1 <= 1) ns = -1;
	else {
		while(s1 <= s2) {
			s1 = s1 * 2 - 1;
			k++;
		}
		ns = k;
	}
	return s1;
}

int dfs(int pos, int s) {
	if(pos > n) return 0;
	
	int i, x = 0;
	for(i = pos; i <= n; ++i) 
		if(s > t[i]) s += t[i];
		else break;

	int res;
	long p = check(s, t[i], res);
	if(res >= (n - i + 1) || res == -1) x = (n - i + 1);
   	else {
		int res2 = dfs(i + 1, p + t[i]);
		x = ((res + res2) < n - i + 1) ? (res + res2) : (n - i + 1);
	}
	return x;
}

int main(int argc, char *argv[]) {
	int t1, t2;
	cin >> t1;
	t2 = t1;
	while(t2--) {
		cin >> a >> n;
		long tmp;
		for(int i = 1; i <= n; ++i) cin >> t[i];
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				if(t[i] < t[j]) {tmp = t[i]; t[i] = t[j]; t[j] = tmp;}

		op = dfs(1, a);

		cout << "Case #" << t1 - t2 << ": ";
		cout << op << endl;
	}
	return 0;
}
