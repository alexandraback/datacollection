#include<iostream>
#include<cmath>
#include<queue>


using namespace std;

int v[10010];

int main() {
	int t;
	cin >> t;
	int e, r, n;
	for(int i = 0;i<t;i++) {
		cin >> e >> r >> n;
		for (int j = 0; j < n; j++) {
			cin >> v[j];
		}
		int lookAhead = ceil(e / r);
		long long sum = 0;
		int remain = e;
		for (int j = 0;j<n;){
			for (int k = j+1;k<n && k < j+lookAhead+1;k++) {
				if(v[k] > v[j]) {
					int regainTotal = (k - j) * r;
					if(remain + regainTotal > e) {
						sum += (remain + regainTotal - e) * v[j];
						remain = e;
						j = k;
					}
					else {
						remain = remain + regainTotal;
						j = k;
					}
goto aaa;
				}
			}
			sum += remain * v[j];
			remain = r;
			j++;
aaa:;
		}
		cout << "Case #" << i+1 << ": ";
		cout << sum << endl;
	}
	return 0;
}
