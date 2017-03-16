#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int ar[1000010];

int Reverse(int n){
	int ans=0;
	while(n){
		ans=ans*10+n%10;
		n/=10;
	}
	return ans;
}

void Init(){
	memset(ar,0,sizeof(ar));
	for(int i=1; i<1000001; ++i){
		int tmp=Reverse(i);
		if(ar[i]==0) ar[i]=ar[i-1]+1;
		else ar[i]=min(ar[i],ar[i-1]+1);

		if(i<tmp){
			if(ar[tmp]!=0) ar[tmp]=min(ar[tmp],ar[i]+1);
			else ar[tmp]=ar[i]+1;
		}
	}
}

int main(){
	int T; scanf("%d",&T);
	Init(); int n;
	for(int Case=1; Case<=T; ++Case){
		int N; scanf("%d",&N);
		printf("Case #%d: %d\n",Case,ar[N]);
	}
	return 0;
}
