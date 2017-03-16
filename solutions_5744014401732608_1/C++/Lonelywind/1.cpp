#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

int a[55][55];

int main(){
	int tt;
	cin>>tt;
	long long m;
	int b;

	for (int cs=1;cs<=tt;cs++){
		printf("Case #%d: ",cs);
		scanf("%d%lld",&b,&m);
		if (m>( (long long)1 << (b-2) )){
			puts("IMPOSSIBLE");
			continue;
		}
		bool first=true;
		memset(a,0,sizeof(a));
		for (int i=b-2;i>=0;i--){
			if ( ((m>>(long long)i)& (long long)1) == 1 ){
				if (first){
					first=false;
					int st=b-i;
					for (int j=st;j<=b;j++){
						a[1][j]=1;
						for (int k=j+1;k<=b;k++)
							a[j][k]=1;
					}
				}
				else{
					int t=b-i-1;
					a[1][2]=1;
					a[2][t]=1;
				}
			}
		}
		puts("POSSIBLE");
		for (int i=1;i<=b;i++){
			for (int j=1;j<=b;j++)
				printf("%d",a[i][j]);
			printf("\n");
		}
	}

	return 0;
}