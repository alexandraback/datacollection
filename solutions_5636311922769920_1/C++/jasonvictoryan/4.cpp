#include<cstdio>
#include<iostream>
#include<math.h>
using namespace std;

int Testcase,a,b,c;

int main(){
	//freopen("4.in","r",stdin);
	freopen("4.out","w",stdout);
	scanf("%d",&Testcase);
	for(int i=1;i<=Testcase;i++){
		scanf("%d%d%d",&a,&b,&c);
		int ma=a / b;
		if (a % b) ma++;
		if (ma>c) {
			printf("Case #%d: IMPOSSIBLE\n",i);
			continue;
		}
		printf("Case #%d:",i);
		long long last=ma*b;
		for(int i=1;i<=ma;i++){
			long long print=0;
			for(int j=1;j<=b;j++){
				long long w;
				if (last>a) w=a;
				else w=last;
				if (j>1) w--;
				print+=w*(long long)pow(a,j-1);
				last--;
			}
			printf(" %I64d",print);
		}
		puts("");
	}
	return 0;
}
