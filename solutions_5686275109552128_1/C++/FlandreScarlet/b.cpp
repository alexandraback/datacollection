#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
template<class T> T sqr(T x) {return x*x;}
#define pi acos(-1)
#define INF 100000000
#define debug(x) cerr<<#x"="<<(x)<<"\n";
#define foreach(it,v) for (__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)

int a[1100];

int main() {
	int tt,n;
	scanf("%d",&tt);
	for (int te=1;te<=tt;te++) {
		scanf("%d",&n);
		int ans=INF;
		for (int i=1;i<=n;i++) scanf("%d",a+i);
		for (int k=1;k<=1000;k++) {
			int sum=0;
			for (int i=1;i<=n;i++) {
				sum+=a[i]/k;
				if (a[i]%k==0) sum--;
			}
			ans=min(ans,sum+k);
		}
		printf("Case #%d: %d\n",te,ans);
	}
}
