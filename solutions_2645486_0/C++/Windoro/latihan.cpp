#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <math.h>
#include <stack>
#include <bitset>

using namespace std;


#define ii pair<int,int>
#define iii pair<int,ii>
typedef long long ll;
typedef unsigned long long ull;

int e,r,n;
int v[100],dp[12][12];


int cari(int energy,int ke){

	//printf("%d %d\n",energy,ke);

	if(energy+r<=e)
	energy+=r;

	if(ke==n)return 0;

	if(dp[energy][ke]!=-1)return dp[energy][ke];


	int maks=-1<<30;

	for(int i=0;energy-i>=0;i++){

		int temp=cari(energy-i,ke+1)+i*v[ke];

		//printf("%d %d, %d %d = %d\n",energy,ke,i,v[ke],temp);

		if(maks<temp){
			maks=temp;

		}

	}

	dp[energy][ke]=maks;

	return maks;

}


int main (){

	//freopen("B-small-attempt0.in","r",stdin);	freopen("output.txt","w",stdout);

	int t;
	scanf("%d",&t);

	for(int kasus=1;kasus<=t;kasus++){

		scanf("%d %d %d",&e,&r,&n);

		for(int i=0;i<n;i++){
			scanf("%d",&v[i]);
		}

		for(int i=0;i<12;i++)
		for(int j=0;j<12;j++)dp[i][j]=-1;

		printf("Case #%d: ",kasus);

		printf("%d\n",cari(e,0));

	}


}
















