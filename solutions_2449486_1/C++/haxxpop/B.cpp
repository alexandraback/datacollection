#include<stdio.h>
int a[1000][1000];
int b[1000][1000];
int main(){
	int t;
	scanf("%d",&t);
	for(int e = 0 ; e< t ;e++ ){
		int n,m;
		scanf("%d %d",&n,&m);
		for(int i = 0 ;i < n ;i++ ){
			for(int j= 0; j < m ;j++ ){
				scanf("%d",&a[i][j]);
				b[i][j] = 100;
			}
		}
		for(int i =0 ; i < n ;i++ ){
			int maxx = 0;
			for(int j = 0 ;j < m; j++ ){
				if( a[i][j] > maxx ) maxx = a[i][j];
			}
			for(int j = 0;j < m ;j++ ){
				if( b[i][j] > maxx ) b[i][j] = maxx;
			}
		}
		for(int i = 0 ; i < m; i++ ){
			int maxx = 0;
			for(int j = 0 ; j< n; j++ ){
				if( a[j][i] > maxx ) maxx = a[j][i];
			}
			for(int j = 0;j < n ;j++ ){
				if( b[j][i] > maxx ) b[j][i] = maxx;
			}
		}
		int chk = 1;
		for(int i = 0 ;i < n;i++ ){
			for(int j = 0;j < m ;j++ ){
				if( a[i][j] != b[i][j] ) chk = 0;
			}
		}
		if( chk ) printf("Case #%d: YES\n",e+1);
		else printf("Case #%d: NO\n",e+1);
	}
}

		

