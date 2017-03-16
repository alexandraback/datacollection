#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

int x[30] = {0};
int a[30] = {0};
int i1 = 0;
int i2 = 0;
bool flag = false;
int T;
int N;

void print() {
	flag = true;
	for(int i=0;i<20;i++) {
		if(x[i]==1) {
			printf("%d",a[i]);
			if(i !=i1) printf(" ");
		}
	}
	printf("\n");
	for(int i=0;i<20;i++) {
		if(x[i]==2) {
			printf("%d",a[i]);
			if(i !=i2) printf(" ");
		}
	}
	printf("\n");
}

void check() {
	int sum1 = 0, sum2 = 0;
	i1 = 0;i2 = 0;
	for(int i=0;i<20;i++) {
		if(x[i]==1) {sum1 += a[i];i1=i; }
		if(x[i]==2) {sum2 += a[i];i2=i; }
	}
	if(sum1 == sum2 && sum1 != 0) print();
	else return;
}

void dfs(int t) {
	for(int k = 0;k<3;k++) {
		if (flag) break;
		x[t] = k;
	
		if(t == 20) check();
		else dfs(t+1);
	}
}

int main() {
	freopen("result.in","r",stdin);
	freopen("result.out","w",stdout);

	scanf("%d",&T);
	
	for(int k=0;k<T;k++) {
		scanf("%d",&N);
		for(int i=0;i<N;i++) {
			scanf("%d",&a[i]);
		}

		flag = false;
		printf("Case #%d:\n",k+1);
		dfs(0);
		if(!flag) printf("Impossible\n");
	}
}