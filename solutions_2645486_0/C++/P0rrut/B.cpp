#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;
int e,r,n,v[15];

int memo[20][10];

int dp(int ind, int ene){
	if(ind > n || ene<0) return 0;

	int &ref = memo[ind][ene];

	if(ref!=-1) return ref;

	for(int x=1;x<=ene;x++)
		ref=max(ref,v[ind]*x+dp(ind+1,min(e,ene-x+r)));	
	
	ref=max(ref,dp(ind+1,ene));
	
	return ref;


}

int main(){

	int T;
	

	scanf("%d",&T);
	for(int p=0;p<T;p++){
		memset(memo,-1,sizeof(memo));
		printf("Case #%d: ",p+1);
		scanf("%d %d %d",&e,&r,&n);
		for(int x=0;x<n;x++)
			scanf("%d",&v[x]);
		

		printf("%d\n",dp(0,e));

	}


	return 0;
}
