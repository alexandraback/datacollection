#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
using namespace std;

string s;
char ans[2222];

int main(){
	int n,x;
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	cin>>n;
	for (int i = 1; i <= n; ++i){
		cin>>s;		
		printf("Case #%d: ",i);

		int l=1000,r=1000;
		ans[l]=s[0];
		for (int i = 1; i < s.length(); ++i){
			if (s[i]>=ans[l])
				ans[--l]=s[i];
			else
				ans[++r]=s[i];
		}
		for (int i = l; i <=r; ++i)
			printf("%c", ans[i]);
		printf("\n");
	}
	return 0;
}