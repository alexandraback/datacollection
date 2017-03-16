#include<algorithm>
#include<cstdio>
#include<ctime>
#include<iostream>
#include <cassert>
#include <string>
#include <bitset>

using namespace std;

bitset<2000001> bt;

int ten[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};

int shift(int x, bitset<2000001> &bt, int low, int high)
{
	int len = 0, xx = x, last = x % 10, cnt = 0;
	while (xx > 0) {
		len ++;
		if (last ==  xx % 10) cnt ++;
		last = x % 10;
		xx /= 10;
	}
	//cout<<len<<" "<<cnt<<endl;
	if (cnt == len) return 0;
	int ans = 0;
	for (int i = 0, zero = 0; i < len; i++) {
		if (!zero && x <= high && x >= low && !bt[x]) { //!«∞÷√0
			ans ++;
			//assert(!bt[x]);
			bt.set(x);
		}
		zero = (x % 10 == 0);
		x = x / 10 + x % 10 * ten[len - 1];
	}
	return ans;
}

int main()
{
	//cout<<shift(22, bt, 1, 100);
	//return 0;
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T, t = 1;
	for (scanf("%d", &T); T--; ) {
		printf("Case #%d: ", t++);
		int A, B;
		scanf("%d%d", &A, &B);
		bt.reset();
		long long sum = 0;
		for (int i = A; i <= B; i++) {
			if (bt[i]) continue;
			int n = shift(i, bt, A, B);
			//cout<<i<<" "<<n<<endl;
			sum += n * (n-1) / 2;
		}
		cout<<sum<<endl;
	}
	return 0;
}
