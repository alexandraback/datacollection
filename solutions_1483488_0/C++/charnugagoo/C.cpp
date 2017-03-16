#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define see(x) cout<<#x<<" "<<x<<endl
#define sp system("pause")

typedef long long ll;

int main() {
	freopen("Cin.txt", "r", stdin);
	freopen("Cout.txt", "w", stdout);
	
	int t, T, n, m, ans;
	cin>>T;
	for(t = 1; t <= T; ++t) {
		ans = 0;
		cin>>n>>m;
		for(int i = n; i <= m; ++i) {
			int k;//di yi wei 233 -> 100
			for(k = 1; k <= i; k*=10)
				;
			k/=10;
			//see(k);sp;
			for(int j = i/10 + k*(i%10); j != i; j = j/10 + k*(j%10)) {
				//see(j);sp;
				if(j >= n && j <= m)
					++ans;
			}
		}
		cout<<"Case #"<<t<<": "<<ans/2<<endl;
	}	
}
