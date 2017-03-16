#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
#define eps 1e-8
#define MAXN 40

bool di[100][100] ;
__int64 ans , tot ;
int n , x , y ;

void dfs( int cur , int high ){
	if(cur==n+1){
		tot ++ ;
		if( di[x][y] )
			ans ++ ;
		return ;
	}
	bool flag = false ;
	for( int i=high+2 ; i>=0 ; i ++ ){
		if( di[9][i-1] == false ){
			flag = true ;
			for( int j=0,s=10-i;j<=i;j++,s++){
				if(di[s][j]==false){
					di[s][j]=true;
					dfs(cur+1,high);
					di[s][j]=false;
					break;
				}
			}
		}
		if( di[11][i-1]==false){
			flag=true;
			for( int j=0,s=10+i;j<=i;j++,s--){
				if(di[s][j]==false){
					di[s][j]=true;
					dfs(cur+1,high);
					di[s][j]=false;
					break;
				}
			}
		}
		if(flag)
			return ;
	}
}

int main(){
	int cas ,casn = 1 ;
	freopen("B-small-attempt1.in","rt",stdin);
	freopen("out.out","wt",stdout);
	scanf("%d",&cas);
	while(cas--){
		scanf("%d%d%d",&n,&x,&y);
		ans = 0 , tot = 0 ;
		x+=10;
		int tmp ;
		if( x < 10 ){
			tmp = x - y ;
		}else{
			tmp = x + y ;
		}
		memset(di,false,sizeof(di));
		int num = ( tmp - 10 )/2 ;
		if( num < 0 ){
			num *= -1 ;
		}
		printf("Case #%d: ",casn++);
		if( num == 0 ){
			if( n >=1 ){
				printf("%lf\n",1.0);
				continue;
			}else{
				printf("%lf\n",0.0);
				continue ;
			}
		}
		if( num ==1 ){
			if( n >= 6 ){
				printf("%lf\n",1.0);
				continue ;
			}else if( x == 10 ){
				printf("%lf\n",0.0);
				continue ;
			}else{
				if( n <= 1+y ){
					printf("%lf\n",0.0);
					continue ;
				}else{
					di[10][0]=true ;
					dfs( 2,0 );
					printf("%lf\n",1.0*ans/tot);
				}
			}
		}else if( num==2 ){
			if( n >= 15 ){
				printf("%lf\n",1.0);
				continue ;
			}else if( x == 10 ){
				printf("%lf\n",0.0);
				continue ;
			}else{
				if( n <= 6 + y ){
					printf("%lf\n",0.0);
					continue ;
				}else{
					di[10][0]=di[10][2]=true;for(int i=1;i<=2;i++)di[10-i][2-i]=di[10+i][2-i]=true;
					dfs( 7 , 2 );
					printf("%lf\n",1.0*ans/tot);
				}
			}
		}else if(num==3){
			if( n <= 15 + y ){
				printf("%lf\n",0.0);
				continue ;
			}else{
				di[10][0]=di[10][2]=di[10][4]=true;
				for(int i=1;i<=2;i++)di[10-i][2-i]=di[10+i][2-i]=true;
				for(int i=1;i<=4;i++)di[10-i][4-i]=di[10+i][4-i]=true;
				dfs( 16 , 4 );
				printf("%lf\n",1.0*ans/tot);
			}
		}else{
			printf("%lf\n",0.0);
		}
	}
	return 0;
}