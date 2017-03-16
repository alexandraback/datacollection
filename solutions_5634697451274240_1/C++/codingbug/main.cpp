#include <bits/stdc++.h>
#define M 100

using namespace std;

char a[M+2];
int n;

void input(void){
	scanf("%s",a+1);
	n=strlen(a+1);
}

void process(void){
	int i,cnt=1;
	char x=a[1];
	for(i=2;i<=n;i++){
		if(a[i]!=x) x=a[i],cnt++;
	}
	printf("%d\n",cnt-(a[n]=='+'));
}

int main(void){
	freopen("input.txt","r",stdin);

	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		input();
		printf("Case #%d: ",i);
		process();
	}

	return 0;
}
