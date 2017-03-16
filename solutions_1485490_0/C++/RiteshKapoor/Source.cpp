#include<iostream>
#include<cmath>
#include<set>
#include<vector>
#include<list>
#include<map>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<stack>
#include<queue>
#include<climits>
#include <string>
#include <sstream>

typedef unsigned long long int ULONG;
typedef long long int LONG;
typedef unsigned int UINT;

using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;++i)

#ifndef ONLINE_JUDGE
#include <time.h>
#endif

#include<stdio.h>
#include<iostream>
#include<math.h>


ULONG N,M;
ULONG NN[102],NT[102],MM[102],MT[102];

ULONG DP(int i,int j){
	if(i==N || j==M)return 0;
	ULONG t,m;
	if(NT[i]==MT[j]){
		t=DP(i+1,j+1)+min(NN[i],MM[j]);
		if(NN[i]>MM[j]){
			m=NN[i];
			NN[i]=NN[i]-MM[j];
			t=max(t,DP(i,j+1)+MM[j]);
			NN[i]=m;
		}else if(NN[i]<MM[j]){
			m=MM[j];
			MM[j]=MM[j]-NN[i];
			t=max(t,DP(i+1,j)+NN[i]);
			MM[j]=m;
		}
		return t;
	}else{
		return max( DP(i,j+1)  , DP(i+1,j)  );
	}
}


int main(){
	freopen("input.in","r",stdin);
#ifndef _DEBUG 
	freopen ("output.txt","w",stdout);
#endif
	clock_t start = clock();
		
	int T;
	scanf("%d",&T);	
	FOR(tT,0,T){
		scanf("%d%d",&N,&M);
		FOR(i,0,N)cin>>NN[i]>>NT[i];
		FOR(i,0,M)cin>>MM[i]>>MT[i];

		printf("Case #%d: ",tT+1);
		cout<<DP(0,0)<<"\n";
	}
	//printf("Case #%d: ",tT+1);
	
#ifdef _DEBUG 	
	printf("Time elapsed: %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);
#endif
	return 0;
}






