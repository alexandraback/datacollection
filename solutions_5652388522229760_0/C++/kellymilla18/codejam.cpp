#include <bits/stdc++.h>
#define ll long long
#define int ll
#define mod 1000000007
using namespace std;

main(){
	ios::sync_with_stdio(0);
	freopen("output.txt", "w", stdout);
	int t, c= 1;
	cin >> t;
	while(t--) {
		int i;
		cin >> i;
		cout << "Case #" << c++ << ": ";
		if(i == 0) {
			cout << "INSOMNIA\n";	
		} else {
			int b[10] = {0,0,0,0,0,0,0,0,0,0};
			int rem = 10;
			int num = i;
			while(rem) {
				int cpy = num;
				while(cpy) {
					if(b[cpy%10] == 0) {
						b[cpy%10] = 1;
						rem--;
					}
					cpy/=10;
				}
				num += i;
			}
			cout << num-i << endl;
		}
	}
}

