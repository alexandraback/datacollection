#include <bits/stdc++.h>
using namespace std;
int main(){
	int test;
	scanf("%d", &test);
	for (int w = 1; w <= test; w++) {
		int n, q;
		cin>>n>>q;
		printf("Case #%d:\n", w);
		int x = (n - 2) / 2;
		int a[n];
		for (int i = 0; i < q; i++) {
			a[0] = a[n - 1] = 1;
			for (int j = 1; j <= n - 2; j++) a[j] = 0;
			int tmp = i, t = 0;
			while (tmp > 0){
				t++;
				if(tmp % 2 == 1) a[t] = a[n - 1 - t] = 1;
				tmp /= 2;     
			} 
			for (int j = 0; j < n; j++) cout<<a[j];
			for (int j = 2; j <= 10; j++) cout<<" "<<j + 1;
			cout<<endl;
		}
	}
}