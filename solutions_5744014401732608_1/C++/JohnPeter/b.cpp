#include <bits/stdc++.h>

using namespace std;
long long ex(int base, int expo) {
	long long ret = 1;
	if(expo<=0) return 1;
	for(int i=1;i<=expo;i++) {
		ret*=base;
	}
	return ret;
}
int main() {
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int test;
	scanf("%d",&test);
	int cnt = 1;
	while(test--) {
		int n, tot = 0, m;
		scanf("%d %d",&n, &m);
		
		char arr[n][n];
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				if(i>=j)
				arr[i][j]='0';
				else arr[i][j]='1';
			}
		}
		arr[n-1][n-1]='0';
		
		printf("Case #%d: ", cnt++);
		if(m>pow(2,n-2)) {
			printf("IMPOSSIBLE\n");
		}
		else {
			int now = 0;
			for(int i=n-2;i>=0;i--) {
		//		cout<<i<<"   "<<m<<endl;
				if(m<ex(2, i-1)) {
					arr[i][n-1]='0';
				}
				else {
					m-=ex(2, i-1);
				}
		//		cout<<i<<"  "<<m<<endl;
				
			}
			printf("POSSIBLE\n");
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {
					printf("%c",arr[i][j]);
				}
				printf("\n");
			}
		}
		
	}
	
	return 0;
}
