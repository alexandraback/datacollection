#include<cstdio>
#include<iostream>
#include<string>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int main() {
	long long test,z=1,i,j,res;
	long long a,b;
	bool impossible;
	long long two[50]={1};
	for ( i=1; i<50; i++ ) {
		two[i]=two[i-1]*2;
	}
	long long a_cnt=0;

	freopen("A-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);

	scanf("%lld",&test);
	while(test--) {
		impossible=false;
		scanf("%lld/%lld",&a,&b);
		long long k=2; a_cnt=0;
		long long aa=a,bb=b;
		bool check=true;
		if ( a==1 ) check=false;
		while(check) {
			while(a%k==0) {
				a/=k;
				if ( b%k==0 ) {
					b/=k;
					if ( b%2!=0 ) {
						check=false;
						break;
					}
				}
			}
			k++;
			if ( a==1 ) check=false;
		}

		impossible=true;
		for ( i=1; i<=40; i++ ) {
			if ( (double)aa/bb>=1.0/(double)two[i] ) {
				for ( j=0; j<=40; j++ ) {
					if ( two[j]==b ) {
						impossible=false;
						res=i; break;
					}
				}
			}
			if ( !impossible ) break;
		}

		printf("Case #%lld: ",z++);
		if ( impossible ) printf("impossible\n");
		else printf("%lld\n",res);
	}
	return 0;
}