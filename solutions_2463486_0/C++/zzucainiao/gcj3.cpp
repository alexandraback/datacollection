#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX(a, b) ((a)>(b)?(a):(b))
#define MIN(a, b) ((a)>(b)?(b):(a))
#define N 10000000

using namespace std;

int flag[N + 10];

int ok(long long a){
	int p[20];
	int num = 0;
	while(a != 0){
		p[num++] = (int)(a % 10);
		a /= 10;
	}
	/*for(int i=0; i<num; i++){
		printf("%d", p[i]);
	}
	printf("\n");*/
	int l = (num+1)/2;
	for(int i=0; i<l; i++){
		if(p[i] != p[num-1-i])
			return 0;
	}
	return 1;
}
int main ()
{
	int t, cases=1;
	memset(flag, 0, sizeof(flag));
	long long n = N;
	for(long long i=1; i<=n; i++){
		if(ok(i) && ok(i*i)){
			flag[i] = flag[i-1] + 1;
		}else{
			flag[i] = flag[i-1];
		}
	}
	scanf("%d", &t);
	while(t--){
		long long a, b;
		cin >> a >> b;
		
		int aa = (int)ceil(pow(a, 0.5));
		int bb = (int)floor(pow(b, 0.5));
		
		printf("Case #%d: ", cases++);
		
		printf("%d\n", flag[bb]-flag[aa-1]);
	}
    return 0;
}
