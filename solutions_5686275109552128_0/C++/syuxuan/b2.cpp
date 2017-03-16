#include <iostream>
using namespace std;
int tmp[2000];
int calc(int top, int n) {
	int i, count=0;
	if (top <= 0)
		return 1000000000;
	for(i=0;i<n;i++)
		count += (tmp[i]-1)/top;
	return top+count;
}
int main(){
	int t, p;
	cin >> t;
	for (p=1; p<=t; p++) {
		int n;
		cin >> n;
		int i, max = 0;
		for (i=0; i<n; i++) {
			cin >> tmp[i];
			if (tmp[i] > max)
				max = tmp[i];
		}
		if (max == 1) {
			cout << "Case #" << p << ": 1" << endl;
			continue;
		}
		int l=1,r=max+1;
		int ans=12312310, k;
		for (k=1;k<=max+1;k++) {
			int v=calc(k, n);
			if (v<ans) {
				ans = v;
			}
		}
		cout << "Case #" << p << ": " << ans << endl;
	}
	return 0;
}
