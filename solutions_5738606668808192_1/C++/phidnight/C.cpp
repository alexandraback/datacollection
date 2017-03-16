#include <cstdio>

long long seed=999991;
long long myrand(void) {
	seed=((seed*127+123456)/2);
	long long x=(1<<22);
	x*=x;
	return seed%x;
}
long long gen(int nw,int len,long long ret) {
	if(nw==len) return ret;
	if(nw==0||nw+1==len) {
		return gen(nw+1,len,ret+ret+1);
	}
	if(myrand()%2) {
		return gen(nw+1,len,ret+ret+1);
	} else {
		return gen(nw+1,len,ret+ret);
	}
}
int T,N,J;
int sj=0;
long long lst[999];
int divs[999][18];
int plen;
long long primes[99999];
long long calcb(long long vl,int base) {
	long long ret=0;
	long long addv=1;
	while(vl) {
		if(vl%2) ret+=addv;
		addv*=base;
		vl/=2;
	}
	return ret;
}
int isp(long long vl) {
	if(vl==3) return 0;
	for(int i=0;i<plen;i++) {
		if(primes[i]*primes[i]>=vl) return 0;
		if(vl%primes[i]==0) return (int)primes[i];
	}
	return 0;
}
void saydig(long long vl) {
	char calls[99];
	for(int i=0;i<N;i++) {
		if(vl%2) {
			calls[i]='1';
		} else {
			calls[i]='0';
		}
		vl/=2;
	}
	for(int i=N-1;i>=0;i--) printf("%c",calls[i]);
}
int main() {
	scanf("%d%d%d",&T,&N,&J);
	printf("Case #1:\n");
	plen=2;
	primes[0]=2;
	primes[1]=3;
	for(int j=5;j<70000;j+=2) {
		int ok=1;
		for(int i=1;i<plen;i++) {
			if(j%primes[i]==0) {
				ok=0;
				break;
			}
		}
		if(ok) primes[plen++]=j;
	}
	while(sj<J) {
		lst[sj]=gen(0,N,0);
		int ok=1;
		for(int i=0;i<sj;i++) {
			if(lst[i]==lst[sj]) ok=0;
		}
		if(ok) {
			for(int i=2;i<11;i++) {
				long long cb=calcb(lst[sj],i);
				int vl=isp(cb);
				if(vl) {
					divs[sj][i]=vl;
				} else {
					ok=0;
					break;
				}
			}
		}
		if(ok) {
			saydig(lst[sj]);
			for(int i=2;i<11;i++) {
				printf(" %d",divs[sj][i]);
			}
			printf("\n");
			sj++;
		}
	}
	return 0;
}
