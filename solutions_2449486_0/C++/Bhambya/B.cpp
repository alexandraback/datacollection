#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<cmath>
#include<list>
#include<deque>

using namespace std;

int main() {
	int t,n ,m;
	
	int a[200][200];
	
	scanf("%d",&t);
	
	for(int caseCount = 1; caseCount <= t; ++caseCount) {
		
		scanf("%d%d",&n,&m);
		
		for(int i = 0;i < n; ++i) {
			for(int j = 0;j < m;++j) {
				scanf("%d",&a[i][j]);
			}
		}
		
		int finalFlag = 0;
		
		for(int i = 0;i < n; ++i) {
			for(int j = 0;j < m;++j) {
				int flag = 0;
				for(int k = 0; k < n; ++k) {
					if(i != k && a[k][j] > a[i][j]) {
						flag = 1;
						break;
					}
				}
				
				if(flag == 1)
					for(int k = 0; k < m; ++k) {
						if(j != k && a[i][k] > a[i][j]) {
							finalFlag = 1;
							break;
						}
					}
					
				if(finalFlag)
					break;
			}
			
			if(finalFlag)
					break;
		}
		
		if(finalFlag)
			printf("Case #%d: NO\n", caseCount);
		else
			printf("Case #%d: YES\n", caseCount);
	}
	
	return 0;
}
