#include<stdio.h>
int ini[405];
int use[202];
int hav[202][402];
int num[202];
int stat[202];
int keyn[405];
int dp[4000000];
int ans[202];
int main(){
	int t;
	scanf("%d",&t);
	for(int e = 0 ; e < t ;e++ ){
		int n,m;
		for(int i = 0;i < 202 ;i++ ) ini[i] = 0;
		scanf("%d %d",&m,&n);
		for(int i = 0;i < m; i++ ){
			int x;
			scanf("%d",&x);
			ini[x]++;
		}
		for(int i = 0 ; i < n ;i++ ){
			scanf("%d",&use[i]);
			scanf("%d",&num[i]);
			for(int j =0 ; j <num[i] ; j++ ) scanf("%d",&hav[i][j]);
		}
		for(int i = 0; i< (1<<n) ;i++) dp[i] =-1;
		dp[0] = 0;
		for(int k = 1; k< (1<<n) ;k++ ){
			int tmp = k;
			for(int i = 0 ; i < n ;i++ ){
				stat[i] = tmp%2;
				tmp/=2;
			}
			for(int i = 0 ;i <202 ;i++ ) keyn[i] = ini[i];
			for(int i =0 ; i < n ;i++ ){
				if( stat[i] == 0 ){
					keyn[use[i]]--;
					for(int j =0; j < num[i] ; j++ ){
						keyn[hav[i][j]]++;
					}
				}
			}
			for(int i = 0 ; i < n ;i++ ){
				if( stat[i] == 1 && dp[k-(1<<i)] != -1 && keyn[use[i]] > 0 ){
					dp[k] = i;
					break;
				}
			}
		}
		int tmp = (1<<n)-1;
		int chk = 1;
		int nans = 0;
		for( ; tmp != 0 ; ){
			if( dp[tmp] == -1 ){
				chk = 0 ;
				break;
			}
			ans[nans++] =dp[tmp] ;
			tmp -= (1<<dp[tmp]);
		}
		printf("Case #%d: ",e+1);
		if( chk ){
			for(int i =0; i< nans; i++ ){
				printf("%d",ans[i]+1);
				if( i != nans-1 )printf(" ");
			}
		}else printf("IMPOSSIBLE");
		printf("\n");
	}
}






		
