#include<stdio.h>
#include<algorithm>
//#define DEBUG
#ifdef DEBUG
#define CASE(T) printf("Case #%d: \n",T)
#define eprintf(...) printf(__VA_ARGS__)
#else
#define CASE(T) printf("Case #%d: ",T)
#define eprintf(...) 
#endif
long long lowbit(long long c){
	return c&-c;
}
long long p64(long long x,int y){
	char s[111];
	int i,j,k;
	for(i=63;i>=0;i--){
		if(i<y)putchar('*');
		else putchar('0'+(x&(1ll<<i)?1:0));
	}
	puts("");
}
long long smallthan(long long x,long long mask){
	return 0;
}
struct DIV {
	long long val[64];
	int any[64];
	int cnt;
} a,b,k;
DIV getx(long long x){
	int i,j,k;
	DIV ret;
	long long low,y;
	ret.cnt=0;
	while(x){
		low=(lowbit(x));
		y=__builtin_ctz(low);
		x&=~low;
		ret.val[ret.cnt]=x;
		ret.any[ret.cnt++]=y;
		//p64(x,y);
	}
	return ret;
}
bool is1(DIV &d,int k,int r){
	return d.val[k]&(1ll<<r) || d.any[k]>r;
}
bool is0(DIV &d,int k,int r){
	return !(d.val[k]&(1ll<<r)) || d.any[k]>r;
}
void solve(){
	int i,j,k,r;
	long long A,B,K,low,lowmask,x,y,z;
	long long total=0;
	scanf("%I64d%I64d%I64d",&A,&B,&K);
	DIV a=getx(A),b=getx(B),c=getx(K);
	for(i=0;i<a.cnt;i++){
		for(j=0;j<b.cnt;j++){
			for(k=0;k<c.cnt;k++){
				long long ans=1;
				for(r=0;r<32;r++){
					int vv=0;
					if(is1(c,k,r)){
						if(is1(a,i,r)&&is1(b,j,r)){
							vv++;
						}
					}
					if(is0(c,k,r)){
						if(is0(a,i,r)&&is0(b,j,r)){
							vv++;
						}
						if(is0(a,i,r)&&is1(b,j,r)){
							vv++;
						}
						if(is1(a,i,r)&&is0(b,j,r)){
							vv++;
						}
					}
					ans*=vv;
				}
				total+=ans;
			}
		}
	}
	printf("%I64d\n",total);	
}
int main(){
	int T,TN=1000000;
	scanf("%d",&TN);
#ifndef DEBUG
//	scanf("%d",&TN);
#endif
	for(T=1;T<=TN;T++){
		CASE(T);
		solve();
		//break;
	}
}
