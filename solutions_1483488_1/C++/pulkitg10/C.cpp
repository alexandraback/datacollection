#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<string.h>
#include<cstring>
#include<stack>
#include<queue>
#include<cassert>

using namespace std;

#define LL long long int 
#define PII pair<int,int> 
#define PB push_back
#define MP make_pair
#define INF 1000000000


int count2(int x,int a,int b){
	int cx=x,ten=1,cans=0,dig,px=x;
	while(cx/10){
		cx/=10;
		ten*=10;
	}
	cx=x;
	while(cx/10){
		cx/=10;
		dig=x%10;
		x/=10;
		x+=(ten*dig);
		if(px==x)break;
		if(dig!=0){
			if((a<=x) && (x<=b) && (x>px)){
				cans++;
//				printf("%d %d\n",px,x);
			}
		}
	}
	return cans;
	
}
int main(){
	int test,t,a,b,cnt,i;
	scanf("%d",&test);
	for(t=1;t<=test;t++){
		scanf("%d %d",&a,&b);
		cnt=0;
		for(i=a;i<=b;i++)
			cnt+=count2(i,a,b);
		printf("Case #%d: %d\n",t,cnt);	
	}
	return 0;
}

