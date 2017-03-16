#include <cstdio>

int noexist(int a,int b) {
	if(a!=2&&b!=2) return 2;
	if(a!=3&&b!=3) return 3;
	return 4;
}
int mul(int a,int b) {
	if(a<0) return -mul(-a,b);
	if(b<0) return -mul(a,-b);
	if(a==1) return b;
	if(b==1) return a;
	if(a==b) return -1;
	int ret=noexist(a,b);
	if((a+1==b)||(b+2==a)) return ret;
	return -ret;
}
int T,L;
long long X;
char str[10008];
int strn[10008];
int main() {
	scanf("%d",&T);
	for(int tn=1;tn<=T;tn++) {
		scanf("%d%lld",&L,&X);
		scanf("%s",str);
		int lset=1;
		for(int i=0;i<L;i++) {
			if(str[i]=='i') strn[i]=2;
			if(str[i]=='j') strn[i]=3;
			if(str[i]=='k') strn[i]=4;
			lset=mul(lset,strn[i]);
		}
		int nws=lset;
		int final=1;
		long long nwx=X;
		while(nwx) {
			if(nwx&1) final=mul(final,nws);
			nws=mul(nws,nws);
			nwx=(nwx>>1);
		}
		int ng=0;
		if(final!=-1) ng=1;
		int now=1;
		long long min_i=-1;
		for(int i=0;i<L*8;i++) {
			now=mul(now,strn[i%L]);
			if(now==2) {
				min_i=i+1;
				break;
			}
		}
		now=1;
		long long min_k=-1;
		for(int i=0;i<L*8;i++) {
			now=mul(strn[L-1-i%L],now);
			if(now==4) {
				min_k=i+1;
				break;
			}
		}
		if(min_i==-1||min_k==-1) ng=1;
		if(min_i+min_k>=X*L) ng=1;
		if(ng) {
			printf("Case #%d: NO\n",tn);
		} else {
			printf("Case #%d: YES\n",tn);
		}
	}
	return 0;
}
