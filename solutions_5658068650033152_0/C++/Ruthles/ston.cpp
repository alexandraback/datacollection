#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#define For(i,x,y) for (i=x;i<=y;i++)
using namespace std;
int i,j,k,n,m,te,test,K,an;
int f[1010],s[1010];
inline void P(int x) {
	an=min(an,x);
}
inline void work(int _,int n,int m,int K) {
	int A=2*_-1,chang=A-2,hua=f[_],xie=_-2,ke=4;
	n-=A,m-=A;
	if (K<=1+xie) {
		P(f[_]+1);
		return;
	}
	if (n) {
		n--;
		if (K<=chang+2) {
			P(f[_]+2);
			return;
		}
		K-=chang+2;
		hua+=2;
		chang++;
	}
	for (;m;m--) {
		if (K<=1+xie) {
			P(hua+1);
			return;
		}
		if (K<=chang+2) {
			P(hua+2);
			return;
		}
		K-=chang+2;
		hua+=2;
	}
	
	for (;;) {
		if (!ke) xie--,ke=4;
		if (xie<0) break;
		K-=1+xie;
		ke--;
		hua++;
		if (K<=0) {
			P(hua);
			return;
		}
	}
}
int main() {
	freopen("ston.in","r",stdin);
	freopen("ston.out","w",stdout);
	scanf("%d",&test);
	f[1]=1; For(i,2,1000) f[i]=4*i-4,s[i]=s[i-1]+f[i-1];
	For(te,1,test) {
		if (te==28)
		i=1;
		scanf("%d%d%d",&n,&m,&K);
		an=K;
		if (n>m) swap(n,m);
		if (K<=4||n<=2) {
			printf("Case #%d: %d\n",te,K);
			continue;
		}
		int A=(n+1)/2;
		if (f[A]+s[A]<K) work(A,n,m,K-f[A]-s[A]);
		else {
			For(i,1,A) {
				if (f[i]+s[i]==K) {
					printf("Case #%d: %d\n",te,f[i]);
					goto yy1;
				}
				if (f[i]+s[i]>K) break;
			}
			an=f[i]; i--;
			work(i,n,m,K-f[i]-s[i]);
		}
		printf("Case #%d: %d\n",te,an);
		yy1:;
	}
	return 0;
}
