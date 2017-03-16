#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int tt, n, a[1000000];

int findmax(int* a, int n){
	int ret = 0;
	for (int i=1; i<n; i++)
	if (a[i] > a[ret]){
		ret = i;
	}

	return ret;
}

int main(){
	freopen("B-large.in", "r", stdin);
	freopen("a.out", "w", stdout);

	scanf("%d", &tt);
	for (int task=1; task<=tt; task++){
		scanf("%d", &n);
		for (int i=0; i<n; i++) scanf("%d", a+i);
		
		int ind = findmax(a, n);
		int mx = a[ind];
		int ret = mx;

		for (int b=1; b<=ret; b++){
			int num = 0;
			for (int i=0; i<n; i++){
				num += (a[i]-1)/b;
			}

			ret = min(ret, num+b);
		}

		printf("Case #%d: %d\n", task, ret);
	}
	return 0;
}
