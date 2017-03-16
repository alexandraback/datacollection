#include<stdio.h>
int exist[1000];
int now[1000];
int tmp[1000];
int coin,n,m;
int ans = 1000;
int rec(int k){
	if( k == 31 ){
		for(int i = 0 ;i < 31 ; i++ ) tmp[i] = 0;
		tmp[0] = 1;
		for(int i = 0 ; i < 31 ; i++ ){
			if( now[i] == 0 ) continue;
			for(int j = m ; j >= 0 ; j-- ){
				if( tmp[j] == 1 ) tmp[j+i] = 1;
			}
		}
		int chk = 1;
		for(int i = 0 ; i <= m ; i++ ){
			if( tmp[i] == 0 ) chk = 0;
		}
		if( chk ){
			int sum = 0;
			for(int i = 0 ; i < 31 ; i++ ){
				sum += now[i];
			}
			if( sum-n < ans ) ans = sum-n;
		}
		return 0;
	}
	if( exist[k] == 1 ){
		now[k] = 1;
		rec(k+1);
	}else if( k < 16 ){
		now[k] = 0;
		rec(k+1);
		now[k] = 1;
		rec(k+1);
	}else{
		now[k] = 0;
		rec(k+1);
	}
}
int main(){
	int t;
	scanf("%d",&t);
	for(int e = 0 ; e < t ; e++ ){
		scanf("%d %d %d",&coin,&n,&m);
		ans = 1000;
		for(int i = 0 ;i < 100 ; i++ ) exist[i] = 0;
		for(int i = 0 ; i < n ; i++ ){
			int x;
			scanf("%d",&x);
			exist[x] = 1;
		}
		rec(0);
		printf("Case #%d: %d\n",e+1,ans);
	}
}
