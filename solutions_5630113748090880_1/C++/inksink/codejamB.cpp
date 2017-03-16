#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
using namespace std;

int sum[2555],x;

int main(){
	int n,m;
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	cin>>n;
	for (int i = 1; i <= n; ++i){
		cin>>m;
		printf("Case #%d:",i);
		for (int j = 0; j < 2501; ++j)
			sum[j]=0;
		for (int j = 1; j < 2*m; ++j)
			for (int k = 0; k < m; ++k){
				cin>>x;
				sum[x]++;
			}
		for (int j = 0; j < 2501; ++j)
			if (sum[j]%2==1)
				printf(" %d", j);
		printf("\n");
	}

	return 0;
}