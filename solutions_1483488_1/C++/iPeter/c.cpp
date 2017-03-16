#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int main(){
	int t,a,b;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		scanf("%d%d",&a,&b);
		int k, ans=0;
		for(k=1;k*10<=a;k*=10);
		for(int i=a;i<=b;i++){
			int x=i/10+i%10*k;
			for(;x!=i;x=x/10+x%10*k)
				if(x <= i && x >= a)
					ans++;
		}
		printf("Case #%d: %d\n", tt, ans);
	}
	return 0;
}

