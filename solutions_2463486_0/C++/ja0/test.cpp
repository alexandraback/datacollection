#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int N = 1000;
int a[N+10], p[N+10], is[N+10], b[11];

int pal(int n){
	b[0] = 0;
	while(n){
		b[++b[0]] = n % 10;
		n /= 10;
	}
	for(int i = 1, j = b[0]; i < j; i++, j--)
		if(b[i] != b[j])return 0;
	return 1;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	for(int i = 1; i <= N; i++)is[i] = pal(i);
	for(int i = 1; i * i <= N; i++)
		if(is[i] && is[i * i])p[i * i] = 1;
	for(int i = 1; i <= N; i++)a[i] = a[i - 1] + p[i];
	
	int t;
	scanf("%d", &t);
	for(int tc = 1; tc <= t; tc++){
		printf("Case #%d: ", tc);
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", a[r] - a[l - 1]);
	}
	
	return 0;
}
