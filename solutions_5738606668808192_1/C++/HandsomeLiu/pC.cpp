#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef unsigned long long int lint;
const int maxn=1<<17;
int main(){
	freopen("outputC.out","w",stdout);
	int n=32,j=500;
	int p=0;
	puts("Case #1:");
	for(int i=0;i<j;i++){
		printf("11");
		int tmp=p;
		for(int i=0;2*i<n-4;i++){
			printf("%d%d",tmp%2,tmp%2);
			tmp/=2;
		}
		p++;
		printf("11");
		for(int i=2;i<=10;i++)printf(" %d",i+1);
		puts("");
	}
}
