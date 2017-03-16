#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int i,T,j,k,N,tmp;


int main() {
	cin >> T;
	for(i=1;i<=T;++i) {
		cout << "Case #" << i << ": ";
		int Hash[2505]={0};
		cin >> N;
		for(j=0;j<2*N-1;++j) {
			for(k=0;k<N;++k) {
				cin >> tmp;
				++Hash[tmp];
			}
		}
		for(j=0;j<=2500;++j) {
			if(Hash[j]%2==1) cout << j << " ";
		}
		cout << endl;
	}
	return 0;
}
