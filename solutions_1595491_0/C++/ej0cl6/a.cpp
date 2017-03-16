#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 110
using namespace std;
int in;
int n,s,p;
int a,b;
int can1,can2;
int main(){
	int T;
	int ca=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&s,&p);
		can1=3*p-2;
		can2=3*p-4;
		if(p==1)
			can1=can2=1;
		a=0;
		b=0;
		for(int i=0;i<n;i++){
			scanf("%d",&in);
			if(in>=can1)
				a++;
			else if(in>=can2)
				b++;
		}
		b=b<s ? b:s;
		printf("Case #%d: %d\n",ca++,a+b);
	}
	return 0;
}
