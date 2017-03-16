#include<stdio.h>
#include<algorithm>
using namespace std;
int b[1100];
int main(){
	int T;scanf("%d",&T);
	for(int t=1;t<=T;t++){
		int a;scanf("%d",&a);
		for(int i=0;i<a;i++)scanf("%d",b+i);
		int ret=0;
		for(int i=0;i<a;i++)ret=max(ret,b[i]);
		printf("Case #%d: ",t);
		for(int i=1;i<=1000;i++){
			int tmp=i;
			for(int j=0;j<a;j++){
				if(i<b[j])tmp+=(b[j]-1)/i;
			}
			ret=min(ret,tmp);
		}
		printf("%d\n",ret);
	}
}