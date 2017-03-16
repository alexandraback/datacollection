#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
using namespace std;

string s;

int work(int num,int k,int c,int s){
	printf("Case #%d:", num);
	for (int i = 1; i <=k ; ++i){
		long long x = i;
		for (int j = 1; j < c; ++j){
			x = (x-1) * k + i;
			
		}
		printf(" %lld", x);
	}
	printf("\n");
}

int main(){
	int n,k,c,s;
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	cin>>n;
	for (int i = 1; i <= n; ++i){
		cin>>k>>c>>s;
		work(i,k,c,s);
	}

	return 0;
}