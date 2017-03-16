#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
using namespace std;

int n, tt;
long long s[600], sum[600];
bool ans;
int m1, m2;
long long q1[600], q2[600];
void dfs(int i, long long a, long long b){
	if(ans) return;
	if(a == b && a>0){
		for(int i=0;i<m1;i++)
			printf("%I64d ", q1[i]);
		puts("");
		for(int i=0;i<m2;i++)
			printf("%I64d ", q2[i]);
		puts("");
		ans=1;
		return;
	}
	if(a-b > sum[i] || b-a > sum[i])
		return;
	for(;i>=0;i--){
		dfs(i-1, a, b);
		if(a == 0 && b == 0);
		else{
			q2[m2++] = s[i];
			dfs(i-1, a, b+s[i]);
			m2--;
		}
		q1[m1++] = s[i];
		dfs(i-1, a+s[i], b);
		m1--;
	}
}
int main(void){
	int t;
	scanf("%d",&t);
	for(tt=1;tt<=t;tt++){
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%I64d",&s[i]);
		sort(s, s+n);
		for(int i=0;i<n;i++)
			sum[i]=s[i]+(i>0?sum[i-1]:0);
		ans = false;
		printf("Case #%d:\n", tt);
		dfs(n-1, 0, 0);
		if(ans == 0)
			puts("Impossible");
	}
	
	return 0;
}
