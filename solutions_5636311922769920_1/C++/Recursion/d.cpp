#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int task,s,c,k,num;
long long l,r,a[105];
inline long long power(int a,int b) {
	long long ans=1;
	for (int i=1;i<=b;i++) ans*=a;
	return ans;
}
int main() {
	//freopen("D-large.in","r",stdin);
	//freopen("D-large.out","w",stdout);
	scanf("%d",&task);
	for (int id=1;id<=task;id++) {
		scanf("%d%d%d",&k,&c,&s);
		printf("Case #%d:",id);
		num=0;
		int now=0;
		for (int i=1;i<=s;i++) {
			l=1; r=power(k,c);
			for (int j=1;j<=c;j++) {
				now++;
				if (now>k) break;
				long long len=(r-l+1)/k;
				r=l+len*now-1;
				l=r-len+1;
			}
			a[++num]=l;
			if (num>s) break;
			if (now>k) break;
		}
		if (now<k||num>s) puts(" IMPOSSIBLE"); else {
			for (int i=1;i<=num;i++) cout<<' '<<a[i];
			putchar('\n');
		}
	}
	return 0;
}
