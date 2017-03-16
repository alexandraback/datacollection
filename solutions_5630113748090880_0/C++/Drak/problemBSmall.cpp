#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
int main() {
	int T, sum[3010], n, data;
	scanf("%d", &T);
	for(int caso=1 ; caso<=T ; caso++) {
		memset(sum, 0, sizeof(sum));
		scanf("%d", &n);
		for(int i=0 ; i<(2 * n - 1) ; i++) {
			for(int k=0 ; k<n ; k++) {
				scanf("%d", &data);
				sum[data]++;
			}
		}
		cout<<"Case #"<<caso<<":";
		for(int i=0 ; i<3000 ; i++) if( sum[i] % 2 == 1 ) cout<<" "<<i;
		cout<<endl;
	}
	return 0;
}