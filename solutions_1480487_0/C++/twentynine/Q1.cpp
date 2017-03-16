#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#define infns "A-small-attempt1.in"
#define outfns "A-small-attempt5555.out"
using namespace std;
FILE *fin, *fout;

int main(){
	fin = fopen(infns, "r"); fout = fopen(outfns, "w");
	int ii,t;
	scanf("%d",&t);
	for(ii=1;ii<=t;ii++){
		int n,i,j,a[1000],x=0,num,b[1000]={0},sum=0;
		double y;
		scanf("%d",&n);
		num=n;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			x+=a[i];
			sum+=a[i];
		}
		sum*=2;
		printf("Case #%d:",ii);
		y=2*x/n;
		for(i=1;i<=n;i++){
			if(a[i]>y){
				b[i]=1;
				num--;
				sum-=a[i];
			}
		}
		for(i=1;i<=n;i++){
			if(b[i]==1){printf(" 0.000000");}
			else{
		    	y=(double)sum/num;
	    		y-=a[i];
		     	y/=x;
		    	y*=100;
	    		printf(" %.6lf",y);
	    	}
		}
		printf("\n");
	}
	return 0;
}
			
