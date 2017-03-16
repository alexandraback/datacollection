#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

long long r,b;

int main() {
	int t,Z=1,i,j,res;
	freopen("A-small-attempt1.in","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&t);
	while(t--){
		res=0;
		scanf("%lld %lld",&r,&b);
		// pi = 355/113
		while(b>=2*r+1) {
			b = b - (2*r+1) ;
			res++; r=r+2;
		}
		printf("Case #%d: %d\n",Z++,res);
	}

	return 0;
}