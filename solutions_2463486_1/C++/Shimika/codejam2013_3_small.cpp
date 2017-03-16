#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
long long q,w,x,y,c[30],d,k,l,cnt;
long long b[10000005],n;

int main(){
	freopen("input.txt","r",stdin);
	FILE *fp2=fopen("output.txt","w");
	scanf("%lld",&q);
	long long i,flag;
	for(i=1;i<=10000000;i++){
		d=i; l=0;
		for(;d;d/=10){ c[++l]=d%10; }
		flag=1;
		for(k=1;k<=l/2;k++){
			if(c[k]!=c[l-k+1]){ flag=0; break; }
		}
		if(!flag){ continue; }

		d=i*i; l=0;
		for(;d;d/=10){ c[++l]=d%10; }
		flag=1;
		for(k=1;k<=l/2;k++){
			if(c[k]!=c[l-k+1]){ flag=0; break; }
		}
		if(flag){ b[++n]=i*i; }
	}

	for(w=1;w<=q;w++){
		scanf("%lld %lld",&x,&y);
		cnt=0;
		for(i=1;i<=n;i++){
			if(b[i]>=x && b[i]<=y){ cnt++; }
		}
		fprintf(fp2,"Case #%lld: %lld\n",w,cnt);
	}
	return 0;
}
