#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stack>
using namespace std;
bool path[10][10] , vst[10] , used[10];
int T , N , M , sol[10] , C = 1;
bool flag , endflag;
struct XD{
	int code , pos;	
}Node[10];
bool cmp( XD A , XD B ){
	return A.code < B.code;	
}
void Try( int now , int left , int ptr , stack<int> S ){
	if ( flag ) return;
	if ( left == 0 ){
		flag = true;
		printf("Case #%d: ",C++);
		for ( int i = 1 ; i <= N ; i++ )
			printf("%d",Node[sol[i]].code);
		putchar('\n');
		return;	
	}
	if ( path[now][sol[ptr]] ){
		S.push( now );	
		//vst[sol[ptr]] = true;
		Try( sol[ptr] , left-1 , ptr+1 , S );
		//vst[sol[ptr]] = false;
		S.pop();
	}
	while ( !S.empty() ){
		int key = S.top(); S.pop();
		Try( key , left , ptr , S );
	}
	
	
}
void Generate( int x ){
	if ( endflag ) return;
	if ( x > N ){
		stack<int> S; 
		memset( vst , 0  , sizeof( vst ) );
		vst[sol[1]] = true;
		flag = false;
		Try( sol[1] , N-1 ,2 ,  S );
		if ( flag ){
			endflag = true;
			return;	
		}
	
	}
	else{
		for ( int i = 1 ; i <= N ; i++ )
			if ( !used[i] ){
				sol[x] = i;	 used[i] = true;
				Generate( x+1 );
				used[i] = false;
				
			}
	}
}
int main(){
	freopen("C-small-attempt0.in","r",stdin);
	freopen("out.out","w",stdout);
	int a , b , rev[10];
	scanf("%d",&T);
	while ( T-- ){
		scanf("%d%d",&N,&M);
		memset( path , 0 , sizeof( path ) );

		memset( used , 0 , sizeof( used ) );
		for ( int i = 1 ; i <= N ; i++ ){
			scanf("%d",&Node[i].code);
			Node[i].pos = i;
		}
		std::sort( Node+1 , Node+N+1 , cmp);
		
		for ( int i = 1 ; i <= N ; i++ )
			rev[Node[i].pos] = i;
		
		for ( int i = 1 ; i <= M ; i++ ){
			scanf("%d%d",&a,&b);
			path[rev[a]][rev[b]] = path[rev[b]][rev[a]] = true;
		}
		endflag = false;
		for ( int i = 1 ; i <= N ; i++ ){
			sol[1] = i;
			used[i] = true;
			Generate( 2 );
			used[i] = false;
		}
		
		
	}
	
	return 0;	
}
