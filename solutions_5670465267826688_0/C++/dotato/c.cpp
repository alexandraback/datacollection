#include <stdio.h>
#include <algorithm>
using namespace std;

inline int mult(int a,int b){
	int sign=((a<0)^(b<0))?-1:1;
	a=abs(a);
	b=abs(b);
	if( a==1 ) return b*sign;
	if( b==1 ) return a*sign;
	if( a==b ) return -1*sign;
	
	if( a==2 ){
		if( b==3 ) return 4*sign;
		if( b==4 ) return -3*sign;	
	}
	
	if( a==3 ){
		if( b==2 ) return -4*sign;
		if( b==4 ) return 2*sign;
	}
	
	if( a==4 ){
		if( b==2 ) return 3*sign;
		if( b==3 ) return -2*sign;
	}
}

int main(){

	freopen("C-small-attempt1.in","r",stdin);
	freopen("C-small-attempt1.out","w",stdout);
	
	int test,tc=1,ans,l,x,i,j;
	char in[160002];
	int temp;
	
	for( scanf("%d",&test) ; test-- ; printf("Case #%d: %s\n",tc++,ans?"YES":"NO") ){
		scanf("%d%d",&l,&x);
		scanf("%s",in);
		temp=1;
		for( i=0 ; in[i] ; i++ ){
			if( in[i]=='1' ) in[i]=1;
			else if( in[i]=='i' ) in[i]=2;
			else if( in[i]=='j' ) in[i]=3;
			else if( in[i]=='k' ) in[i]=4;
			temp = mult(temp,in[i]);
			
		}
		
		j=x&3;
		ans=1;
		for( i=0 ; i<j ; i++ ) ans = mult(ans,temp);
		
		if( ans!=-1 ){
			ans=0;
			continue;			
		}
		else{
			j=l;
			
			for( x=(x&7)+(x>=8?8:0) ; --x ;){
				for( i=0 ; i<l ; i++,j++ ){
					in[j]=in[i];
				}
			}
			in[j]=0;
			
			ans=0;
			temp=1;
			for( i=0 ; in[i] ; i++ ){
				temp = mult(temp,in[i]);
				if( ans==0 ){
					if( temp==2 ) ans=1;
				}
				else if( ans==1 ){
					if( temp==4 ){
						ans=2;
						break;
					}
				}		
		//		printf("%d %d\n",ans,temp);
			}
			
			if( ans<2 ) ans=0;
			
		}
	}

	return 0;
}

