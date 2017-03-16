#include<cstdio>
#include<iostream>
#include<string>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

int n,m,k;

int main() {
	int test,i,j,z=1,res;
	
	freopen("C-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);

	scanf("%d",&test);
	while(test--) {
		res=1;
		scanf("%d %d %d",&n,&m,&k);
		if ( n==1 || n==2 || m==1 || m==2 || k<5 ) res=k;
		else if ( n==3 || m==3 ) {
			if ( n==3 && m==3 ) {
				res=k-1;
			}
			else if ( n==4 || m==4 ) {
				res=k-1;
				if ( k>=8 ) res=k-2;
			}
			else if ( n==5 || m==5 ) {
				res=k-1;
				if ( k>=8 ) res=k-2;
				if ( k>=11 ) res=k-3;
			}
			else if ( n==6 || m==6 ) {
				res=k-1;
				if ( k>=8 ) res=k-2;
				if ( k>=11 ) res=k-3;
				if ( k>=14 ) res=k-4;
			}
		}
		else if ( n==4 || m==4 ) {
			if ( n==5 || m==5 ) {
				if ( k>=16 ) res=k-6;
				else if ( k>=14 ) res=k-5;
				else if ( k>=12 ) res=k-4;
				else if ( k>=10 ) res=k-3;
				else if ( k>=8 ) res=k-2;
				else if ( k>=5 ) res=k-1;
			}
			else {
				if ( k>=12 ) res=k-4;
				else if ( k>=10 ) res=k-3;
				else if ( k>=8 ) res=k-2;
				else if ( k>=5 ) res=k-1;
			}
		}
		printf("Case #%d: %d\n",z++,res);
	}
	return 0;
}