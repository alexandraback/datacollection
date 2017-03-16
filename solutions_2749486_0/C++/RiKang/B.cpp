#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<vector>

using namespace::std;

int ca,la;
int x,y;

void input(){
	scanf("%d %d",&x,&y);
}

void process(){
}

void output(){
	int i;
	printf("Case #%d: ",ca);
	if(x>0){
		for(i=1;i<=x;i++)
			printf("WE");
	}
	else{
		for(i=1;i<=-x;i++)
			printf("EW");
	}
	if(y>0){
		for(i=1;i<=y;i++)
			printf("SN");
	}
	else{
		for(i=1;i<=-y;i++)
			printf("NS");
	}
	printf("\n");
}

int main(){
	int i,t;
	freopen("B-small-attempt0.in","rt",stdin);
	freopen("B-small-attempt0.out","wt", stdout);
	scanf("%d",&t);
	while(t--){
		la=0;
		ca++;
		input();
		process();
		output();
	}
	return 0;
}