#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

int main(){

	long long r,t,T;
		
	scanf("%d",&T);
	for(int p=0;p<T;p++){
		printf("Case #%d: ",p+1);

		scanf("%lld %lld",&r,&t);
		int x,c=0;
		for(x=r+1;;x+=2,c++){
			if(x*x-(x-1)*(x-1)>t) break;


			t-=x*x-(x-1)*(x-1);
			

		}



		printf("%d",c);

		if(p!=T) printf("\n");
	}

	return 0;
}
