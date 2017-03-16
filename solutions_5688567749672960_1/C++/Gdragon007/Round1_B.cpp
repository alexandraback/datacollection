#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

#define Maxn 1000000

int a[Maxn + 1];

int rev(int c) {
	if (c % 10 == 0) return c + 1;
	int cc = 0;
	while (c != 0) {
		cc = cc * 10 + c % 10;
		c = c / 10;
	}
	return cc;
}

void prepare() {
	a[0] = 0;
	for (int i = 1; i <= Maxn; i ++ ) {
		if (rev(i) < i)
			a[i] = min(a[i - 1], a[rev(i)]) + 1;
		else a[i] = a[i - 1] + 1;
	}
	//cout<<rev(4343)<<endl;
}

long long len(int cnt) {
	if (cnt == 0) {
		return 0;
	}
	long long po = 1;
	for (int i = 0; i < cnt / 2; i ++ )
		po *= 10;
	if (cnt & 1) po = po * 9 + po * 2 - 1;
	else po = po * 2 - 1;
	return po + len(cnt - 1);
}

long long cal(long long n) {
	int d[20];
	int cnt = 0;
	while (n) {
		d[cnt ++ ] = n % 10;
		n /= 10;
	}
	bool flag = false;
	for (int i = 1; i < cnt / 2; i ++ )
		if (d[cnt - i - 1] != 0) flag = true;
	long long ans = 0;
	if (!flag && d[cnt - 1] == 1 && cnt != 1)
		ans = -1;
	else ans = 0;
	for (int i = 0; i < cnt / 2; i ++ )
		d[i] += d[cnt - i - 1];
	long long po = 1;
	for (int i = 0; i < (cnt + 1) / 2; i ++ ) {
		ans = ans + d[i] * po;
		po *= 10;
	}
	return ans + len(cnt - 1);
}

int main() {
	int t;
	freopen("A-large.in", "r", stdin);
	freopen("A-small.out", "w", stdout);
	prepare();
	long long n;

	cin>>t;
	for (int ca = 1; ca <= t; ca ++ ) {
		cin>>n;
		//if (a[n] != cal(n)) while (1);
		//cout<<n<<endl;
		long long ans = 0;
		if (n % 10 == 0)
			ans = ans + cal(n - 1) + 1;
		else
			ans = cal(n);
		cout<<"Case #"<<ca<<": "<<ans<<endl;
	}
	//while (1);
	return 0;
}