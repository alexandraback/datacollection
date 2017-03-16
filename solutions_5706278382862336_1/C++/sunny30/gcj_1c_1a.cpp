#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string>
#include<string.h>
#include<set>
#include<map>
#include<fcntl.h>
#include<stack>
#include<queue>
#include<iostream>

using namespace std ;
typedef long long LL ;
map< LL,LL > s ;
 
LL p,q ;

LL gcd(LL a,LL b){
	
	if(!b)
		return a ;
	return gcd(b,a%b) ;

}


int find_p(LL p){
	
	int i=0;
	LL val =1 ;
	if(p==1)return 0 ;
	while(val<p){
		val*=2 ;
		i++ ;
	}
	return i-1 ;
	
}

int logic(){
	
	if(p>q)
		return -1 ;
	LL g = gcd(q,p) ;
	q/=g ;
	p/=g ;
	if(s[q]){
		
		int x = find_p(p ) ;
		return s[q]-x ;
		
		
	}
	//else if(!q%p && s[q/p])
		return -1 ;
}


int read_inp(){
	
	scanf("%lld/%lld",&p,&q) ;
	

}
 

int pre(){
	LL val = 1 ;
	for(int i=0;i<=40;i++){
		
		s[val<<i]=i ;
		
	}
	
}



int main(){
	FILE *fp = freopen("3.in","r",stdin) ;
	FILE *fp1 =freopen("3.out","w",stdout) ;
	int test ;
	scanf("%d",&test) ;
	pre() ;
	for(int i=1;i<=test;i++){
		printf("Case #%d: ",i) ;
		read_inp() ;
		int x = logic() ;
		if(x!=-1)
		cout<<x<<endl ;
		else
			cout<<"impossible"<<endl ;
		
	}
}
