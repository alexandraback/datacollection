#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#define X first
#define Y second
#define N 100050

typedef long long LL;

int m,n,T;
double p,q;
double C(int a,int b){
	int i,j,k;
	double x=1;
	for(i=1;i<=b;i++){
		x/=i;
		x*=(a-i+1);
	}
	return x;
}
int min(int a,int b){return a<b?a:b;}
int max(int a,int b){return a>b?a:b;}
int main(){
	freopen("PB.in","r",stdin);
	freopen("PB.txt","w",stdout);
	int i,j,k,x,y,z,xx,yy;
	scanf("%d",&T);
	for(int aa=1;aa<=T;aa++){
		p=q=0;
		scanf("%d%d%d",&n,&xx,&yy);
		if(xx<0) xx=-xx;
		if(yy<0) yy=-yy;
		x=xx+yy;i=(xx+yy)/2;y=(2*i+1)*(i+1);
		z=(2*i-1)*(i);

//		printf("%d %d %d\n",x,y,z);
		if(y<=n){p=1;}
		else if(n<=z){p=0;}
		else{
			n-=z;
			xx=x-xx;
			if(x+xx<n) p=1;
			else if(xx>=n) p=0;
			else{
				for(i=xx+1;i<=min(n,x);i++){
					p+=C(n,i);
				}
				for(i=max(0,n-x);i<=min(n,x);i++){
					q+=C(n,i);
				}
				p/=q;
			}
				
				 
		}
		printf("Case #%d: %.8lf\n",aa,p);
	}
	getchar();getchar();
}
