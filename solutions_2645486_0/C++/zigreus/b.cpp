#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int e,r,n,v[100000];
int check[100000][10];

int f(int k, int cnt ) {
	if ( cnt==n-1 ) return k*v[cnt];
	if ( check[k][cnt]!=-1 ) return check[k][cnt];
	int tmp;
	for ( int i=0; i<=k; i++ ) {
		if ( k-i+r > e ) tmp=e;
		else tmp=k-i+r;
		check[k][cnt]=max(check[k][cnt],f(tmp,cnt+1) + i*v[cnt]);
	}
	return check[k][cnt];
}

int main() {
	int t,Z=1,i,j,res;
	freopen("B-small-attempt4.in","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&t);
	int sum;
	while(t--){
		sum=0;
		memset(check,-1,sizeof(check));
		scanf("%d %d %d",&e,&r,&n);
		for ( i=0; i<n; i++ ) {
			scanf("%d",&v[i]);
		}
		res=0;

		printf("Case #%d: %d\n",Z++,f(e,0));
	}

	return 0;
}