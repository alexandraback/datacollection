#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
long long a[11];
int  n,m;
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	for (int TT=1;TT<=t;TT++){
		scanf("%d%d",&n,&m);
		for (int i=2;i<=10;i++){
			a[i]=i;
			for (int j=0;j<n/2-1;j++) a[i]*=i;
		}
		printf("Case #%d:\n",TT );
		for (int j=0;j<m;j++){
			int k=j;
			printf("1");
			for (int p=0;p<n/2-2;p++){
				printf("%d",k%2);
				k/=2;
			}
			printf("1");
			k=j;
			printf("1");
			for (int p=0;p<n/2-2;p++){
				printf("%d",k%2);
				k/=2;
			}
			printf("1");
			for (int i=2;i<=10;i++) printf(" %I64d",a[i]+1 );
			printf("\n");
		}
	}
	return 0;
}