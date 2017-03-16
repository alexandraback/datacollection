#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
long long q,w,x,y,c[30],d,k,l,cnt;

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%lld",&q);
	long long t1,t2;
	for(w=1;w<=q;w++){
		scanf("%lld %lld",&x,&y);
		t1 = (long long)sqrt(x); t2 = (long long)sqrt(y);
		if(t1*t1<x){ t1++; }
		if(t2<t1){ swap(t1,t2); }
		
		long long i,flag; cnt=0;
		for(i=t1;i<=t2;i++){
			d=i; l=0;
			for(;d;d/=10){
				c[++l]=d%10;
			}
			flag=1;
			for(k=1;k<=l/2;k++){
				if(c[k]!=c[l-k+1]){ flag=0; break; }
			}
			if(!flag){ continue; }

			d=i*i; l=0;
			for(;d;d/=10){
				c[++l]=d%10;
			}
			flag=1;
			for(k=1;k<=l/2;k++){
				if(c[k]!=c[l-k+1]){ flag=0; break; }
			}
			if(flag){ cnt++; }
		}
		printf("Case #%lld: %lld\n",w,cnt);
	}
	return 0;
}
