#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
template<class T> T sqr(T x) {return x*x;}
#define pi acos(-1)
#define INF 100000000
#define debug(x) cerr<<#x"="<<(x)<<"\n";
#define foreach(it,v) for (__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)

int mul[4][4]={
	{0,1,2,3},
	{1,0,3,2},
	{2,3,0,1},
	{3,2,1,0}
};
int sig[4][4]={
	{1,1,1,1},
	{1,-1,1,-1},
	{1,-1,-1,1},
	{1,1,-1,-1}
};
char s[11000];
int a[11000];
int n,m;

PII operator * (PII x,PII y) {
	PII ret;
	ret.first=mul[x.first][y.first];
	ret.second=x.second*y.second*sig[x.first][y.first];
	return ret;
}

int main() {
	int tt,n;
	ll m;
	scanf("%d",&tt);
	for (int te=1;te<=tt;te++) {
		scanf("%d%I64d",&n,&m);
		scanf("%s",s);
		printf("Case #%d: ",te);
		for (int i=0;i<n;i++) {
			if (s[i]=='i') a[i]=1;
			if (s[i]=='j') a[i]=2;
			if (s[i]=='k') a[i]=3;
		}
		PII t,ans;
		int a1,a2,flag;
		t=PII(0,1);
		for (int i=0;i<n;i++) t=t*PII(a[i],1);
		ans=PII(0,1);
		for (int i=0;i<m%4;i++) ans=ans*t;
		if (ans!=PII(0,-1)) {
			puts("NO");
			continue;
		}
		a1=0;
		flag=0;
		for (int k=0;k<4;k++) {
			PII x=PII(0,1);
			for (int i=0;i<k;i++) x=x*t;
			for (int i=0;i<n;i++) {
				x=x*PII(a[i],1);
				if (x==PII(1,1)) {
					a1=i+1+k*n;
					flag=1;
					break;
				}
			}
			if (flag) break;
		}
		a2=0;
		flag=0;
		for (int k=0;k<4;k++) {
			PII x=PII(0,1);
			for (int i=0;i<k;i++) x=t*x;
			for (int i=0;i<n;i++) {
				x=PII(a[n-i-1],1)*x;
				if (x==PII(3,1)) {
					a2=i+1+k*n;
					flag=1;
					break;
				}
			}
			if (flag) break;
		}
		if (a1 && a2 && a1+a2<n*m) puts("YES");
		else puts("NO");
	}
}
