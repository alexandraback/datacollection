#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
#define eprintf(...) fprintf(stderr,__VA_ARGS__)

#define ran() ((long long)rand()<<48^(long long)rand()<<32^rand()<<16^rand())
inline long long gcd(long long a,long long b){
	long long c;
	while(b){
		c=a%b;
		a=b;
		b=c;
	}
	return a;
}
inline long long lmul(long long a,long long b,const long long p){
	long long c=0;
	for(;b;b>>=1,a<<=1,a%=p) if(b&1) c+=a,c%=p;
	return c;
}
bool is_Prime(long long p){ // Miller-Rabin
	const int sum=10,a[sum]={2,3,5,7,11,13,17,19,23,29};
	if(p==2) return true;
	if(p==1||!(p&1)) return false;
	long long D=p-1;
	while(!(D&1)) D>>=1;
	for(int i=0;i<sum&&a[i]<p;i++){
		long long d=D,t=1,s=a[i];
		for(long long k=d;k;k>>=1,s=lmul(s,s,p)) if(k&1) t=lmul(t,s,p);
		if(t==1) continue;
		while(d<p-1&&t!=p-1){
			t=lmul(t,t,p);
			d<<=1;
		}
		if(d==p-1) return false;
	}
	return true;
}
long long a[100],*newa;
void decomp(long long n){ // Pollard-Rho
	if(is_Prime(n)||n==1){ *newa++=n; return; }
	while(true){
		long long c=ran()%n,i=1,x=ran()%n,y=x,k=2;
		do{
			i++;
			long long d=gcd(n+y-x,n);
			if(d>1 && d<n){
				decomp(d);
				decomp(n/d);
				return;
			}
			if(i==k) y=x,k<<=1;
			x=(lmul(x,x,n)+c)%n;
		} while(y!=x);
	}
}

ll d[11];

int main(){
	freopen("CC.out","w",stdout);
	printf("Case #1:\n");
	int cnt=0;
	for(int s=1<<15|1;s<1<<16;s+=2){
		bool ok=true;
		for(int b=2;b<=10;b++){
			ll val=0;
			for(int i=15;i>=0;i--){
				val=val*b+(s>>i&1);
			}
			newa=a;
			decomp(val);
			if(newa-a==1){
				ok=false;
				break;
			}
			d[b]=a[0];
		}
		if(ok){
			++cnt;
			for(int i=15;i>=0;i--) putchar('0'+(s>>i&1));
			for(int b=2;b<=10;b++) printf(" %I64d",d[b]);
			printf("\n");
			if(cnt>=50) break;
		}
	}
}
