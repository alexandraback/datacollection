#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int i,T,j,K,C,S;

int main() {
	cin >> T;
	for(i=1;i<=T;++i) {
		scanf("%d %d %d",&K,&C,&S);
		cout << "Case #" << i << ": ";
		for(j=1;j<=K;++j) cout << j << ' ';
		cout << endl;
	}
	return 0;
}
