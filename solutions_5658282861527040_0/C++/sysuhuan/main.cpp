#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstring>
using namespace std;
char str[101][200];

void f(int n){
	int c = 0;
	int a[100];
	while(n){
		a[c++] = n%2;
		n/=2;
	}
	if(c==0)printf("0");

	for(int i = c-1;i>=0;i--)printf("%d",a[i]);

}

int main(){
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int casenum = 1;casenum<=t;++casenum){
		int n1,n2;int k;
		cin >>n1 >>n2>>k;
		int c = 0;
		for(int i = 0;i<n1;i++)
			for(int j = 0;j<n2;j++)if((i & j)<k){
				c++;

			}
		printf("Case #%d: %d\n",casenum, c);
	}
	return 0;
}