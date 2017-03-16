#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
template<class T> T sqr(T x) {return x*x;}
#define pi acos(-1)
#define INF 100000000
#define debug(x) cerr<<#x"="<<(x)<<"\n";
#define foreach(it,v) for (__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)

int main() {
	int te,tt,A,B,K,i,j,ans;
	scanf("%d",&tt);
	for (te=1;te<=tt;te++) {
		scanf("%d%d%d",&A,&B,&K);
		ans=0;
		for (i=0;i<A;i++)
			for (j=0;j<B;j++)
				if ((i&j)<K) ans++;
		printf("Case #%d: %d\n",te,ans);
	}
}
