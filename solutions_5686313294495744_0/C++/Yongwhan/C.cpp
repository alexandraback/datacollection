#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin>>t;
	for (int c=1; c<=t; c++) {
		int n; cin>>n;
		vector<string> a(n), b(n);
		for (int i=0; i<n; i++) cin>>a[i]>>b[i];

		int ret=0;
		for (int i=0; i<n; i++) {
			bool u=false, v=false;
			for (int j=0; j<n; j++) if(j!=i && a[i]==a[j]) u=true;
			for (int j=0; j<n; j++) if(j!=i && b[i]==b[j]) v=true;
			if(u&&v) ret++;
		}
		cout << "Case #" << c << ": " << ret << endl;
	}
	return 0;
}
