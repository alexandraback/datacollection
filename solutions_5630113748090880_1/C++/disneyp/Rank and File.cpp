#include <iostream>
#include<algorithm>
using namespace std;
int a[10000];
int ans[1000];
int r;
int main() {
	freopen("A.in","r",stdin);
	freopen("B.txt","w",stdout);
	int t,n,x;
	cin >> t;
	for(int ii=0;ii<t;ii++) {
		cin >> n;
		r = 0;
		for(int i=0;i<3000;i++) a[i] = 0;
		for(int i=0;i<2*n-1;i++) for(int i=0;i<n;i++){
			scanf("%d",&x);
			a[x] ++;
		}
		for(int i=0;i<3000;i++) {
			if(a[i] & 1) ans[r++] = i;
		}
		sort(ans, ans+n);
		cout << "Case #" << ii+1 << ": ";
		for(int i=0;i<n;i++) printf("%d ",ans[i]);
		cout << endl;
	}
	
}