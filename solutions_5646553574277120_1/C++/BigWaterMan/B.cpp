#pragma error(disable:4996)
#include<iostream>
#include<iomanip>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<queue>
using namespace std;
typedef long long LL;
LL c, d, v;

void addnew(LL &k) {
	k += k * c;
}
LL solve()
{
	cin >> c >> d >> v;
	LL a[10000];
	
	for (LL i = 0; i < d; i++)
		cin >> a[i];
	sort(a, a + d);
	LL ans = 0;
	long long temp = 1;
	for (LL i = 0; i < d; i++) {
		if (a[i] <= temp) {
			temp += a[i] * c;
		}
		else {
			ans++, i--;
			addnew(temp);
		}
		if (temp > v) break;
	}
	while (temp <= v) {
		ans++;
		addnew(temp);
	}
	return ans;
}
int main() {
	errno_t err1;
	errno_t err2;
	FILE *fin, *fout;
	err1 = freopen_s(&fin, "C-large.in", "r", stdin);
	//err1 = freopen_s(&fin, "A-small-attempt0 (1).in", "r", stdin);
	err2 = freopen_s(&fout, "out.txt", "w", stdout);
	//freopen("C.in","r",stdin);
	LL T;
	cin >> T;
	LL ans;
	for (LL z = 1; z <= T; z++) {
		cout << "Case #" << z << ": ";
		cout << solve() << endl;
	}
}
