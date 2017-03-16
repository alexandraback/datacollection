#include <bits/stdc++.h>
#define M 32

using namespace std;

int n,j;
bool ck[M+1];

void input(void){
	scanf("%d %d",&n,&j);
}

void printInt(int k){
	int i;
	long long cnt=0;
    for(i=0;i<n/2;i++){
		cnt*=k;
		if(ck[i]) cnt+=1ll;
    }
	printf(" %lld",cnt);
}

void process(void){
	int i,cnt;

	for(i=(1<<(n/2-1))+1,cnt=0;cnt<j;i+=2,cnt++){
		for(int k=0;k<n/2;k++){
			if(i&(1<<k)) ck[k]=true;
			else ck[k]=false;
		}
		for(int k=0;k<n/2;k++) printf("%d",ck[k]);
		for(int k=0;k<n/2;k++) printf("%d",ck[k]);
		for(int k=2;k<=10;k++) printInt(k);
		printf("\n");
	}
}

int main(void){
	freopen("input.txt","r",stdin);

	scanf("%*d");
	printf("Case #1:\n");
	input();
	process();

	return 0;
}
