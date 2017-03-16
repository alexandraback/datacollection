#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
template<class T> T sqr(T x) {return x*x;}
#define pi acos(-1)
#define INF 100000000
#define debug(x) cerr<<#x"="<<(x)<<"\n";
#define foreach(it,v) for (__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)

int gao(int r,int c,int w) {
	int t,ans;
	t=c/w;
	ans=r*t-1;
	if (c%w) ans++; 
	ans+=w;
	return ans;
}

int main() {
	int tt;
	scanf("%d",&tt);
	for (int te=1;te<=tt;te++) {
		int r,c,w;
		scanf("%d%d%d",&r,&c,&w);
		printf("Case #%d: %d\n",te,gao(r,c,w));
	}
}
