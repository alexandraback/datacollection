#include<stdio.h>

int normal( int n ){
	for(int i=10;i>=0;i--){
		if( i + i + i == n ) return i;
		if( i + i + i-1 == n && i-1 >= 0 ) return i;
		if( i + i - 1 + i -1 == n && i-1 >= 0) return i;
	}
	return 0;
}
int surprise( int n ){
	for(int i=10;i>=0;i--){
		if( i + i + i == n ) return i;
		if( i + i + i-1 == n && i-1 >= 0) return i;
		if( i + i + i-2 == n && i-2 >= 0) return i;
		if( i + i-1 + i-1 == n && i-1 >=0 ) return i;
		if( i + i-1 + i-2 == n && i-1 >=0 && i-2 >=0 ) return i;
		if( i + i-2 + i-2 == n && i-2 >=0 ) return i;
	}
}

int main(){
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	int T,S,P,N;
	scanf("%d",&T);
	for(int k=1;k<=T;k++){
		scanf("%d %d %d",&N,&S,&P);
		int cnt = 0;
		for(int i = 0;i < N ; i++ ){
			int d;
			scanf("%d",&d);
			if( normal(d) >= P ){
				cnt++;
			}else if(S && surprise(d)>=P){
			    cnt++;
			    S--;
			}
		}
		printf("Case #%d: %d\n",k,cnt);
	}	
	return 0;
}
