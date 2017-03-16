#include <stdio.h>
#include <string.h>
#include <algorithm>
int N , M , K , T , ans , allkind;
bool map[21][21] ;
int save[21] , C = 1;
bool check( int y , int x ){
	return  y - 1 >= 0 && y + 1 < N && x - 1 >= 0 && x + 1 < M && map[y-1][x] &&map[y][x-1] &&map[y+1][x] && map[y][x+1]; 	
	
}
void DFS( int ptr , int str ){
	if ( ptr > K ){
		int tmp = K;
		for ( int i = 1 ; i <= K ; i++ ){
		
			int y = save[i] / M , x = save[i] % M;	
			if ( check( y , x ) ) tmp--;
			
		}
		if ( tmp < ans ) ans = tmp;
	
	}
	else{
		for ( int i = str ; i <= allkind -(K-ptr+1) ; i++ )	{
			int y = i / M , x = i % M;	
			save[ptr] = i;
			map[y][x] = true;
			DFS( ptr+1 , i+1 );
			map[y][x] = false;		
		
		}
		
	}
	
}
int main(){
	freopen("C-small-attempt0.in","r",stdin);
	freopen("output.out","w",stdout);
	scanf("%d",&T);
	while ( T-- ){
		scanf("%d%d%d",&N,&M,&K);
		allkind = N * M; // 20
		ans = K;
		for ( int i = 0 ; i <= allkind-K ; i++ ){
			int y = i / M , x = i % M;	
			save[1] = i;
			map[y][x] = true;
			DFS( 2 , i+1 );
			map[y][x] = false;
		}
		printf("Case #%d: %d\n",C++,ans);
	
	}
	
	return 0;	
}
