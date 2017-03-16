#include <iostream>

using namespace std;
long long pow[60];
int a[10000];

void base2(int n) {
	for(int i=0;i<100;i++) {
		a[i] = n % 2;
		n /= 2;
	}
}


int main() {
	
	pow[0] = 1;
	for(int i=1;i<=50;i++) pow[i] = pow[i-1] * 2;
	freopen("A.in","r",stdin);
	freopen("A.txt","w",stdout);
	long long t,n,m;
	cin >> t;
	for(int aa=0;aa<t;aa++) {
		cin >> n >> m;
		printf("Case #%d: ",aa+1);
		if(m > pow[n-2]) {
			printf("IMPOSSIBLE\n");
			continue;
		}
		printf("POSSIBLE\n");
		int ch = 0;
		if(m == pow[n-2]) {ch = 1; m--;}
		base2(m);
		// first row
		cout << "0";
		for(int i=0;i<n-2;i++) {
			printf("%d",a[n-3-i]);
		}
		cout << ch << endl;
		// the rest
		for(int i=2;i<=n;i++) {
			for(int j=1;j<=i;j++) printf("0");
			for(int j=i+1;j<=n;j++) printf("1");
			printf("\n");
		}
		
	}
}