#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<set>
#include<unordered_set>
#include<algorithm>
using namespace std;


void work() {
	int n;
	scanf("%d",&n);
	vector<int> f(3000, 0);
	int t;
	for(int i=0;i<2*n-1;i++) {
		for(int j=0;j<n;j++) {
			scanf("%d",&t);
			f[t]++;
		}
	}
	for(int i=0;i<f.size();i++) {
		if ((f[i] & 1) == 1) printf(" %d", i);
	}
	printf("\n");
}

int main() {
	// freopen("input.txt","r",stdin);
	freopen("B-small-attempt0.in","r",stdin);
	freopen("b-small.out","w",stdout);
	int t;
	scanf("%d\n", &t);
	for(int i=0;i<t;i++) {
		printf("Case #%d:", i+1);
		work();
	}

	return 0;
}

