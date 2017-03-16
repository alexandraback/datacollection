#include <iostream>
using namespace std;

int main() {
	int x; cin >> x;
	
	for(int i=0;i<x;i++){
		cout << "Case #" << i+1 << ": ";
		int n; cin >> n;

		int cnt[2500];
		for(int i=0;i<2500;i++) cnt[i] = 0;

		for(int j=0;j<2*n*n-n;j++){
			int a; cin >> a;
			cnt[a]++;
		}
		int first=0;
		for(int j=1;j<2500;j++){
			if(cnt[j]%2 ==1)
				if(first++ > 0) cout << " " << j;
				else cout << j;
		}
		cout << endl;
	}

	return 0;
}