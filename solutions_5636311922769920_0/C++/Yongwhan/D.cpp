#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t; cin>>t;
	for (int c=1; c<=t; c++) {
		int K,C,S; cin>>K>>C>>S;
		cout << "Case #" << c << ":";
		for (int i=0; i<S; i++)
			cout << " " << i+1;
		cout << endl;
	}
	return 0;
}
