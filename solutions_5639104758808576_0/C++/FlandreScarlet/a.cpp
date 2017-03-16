#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
template<class T> T sqr(T x) {return x*x;}
#define pi acos(-1)
#define INF 100000000
#define debug(x) cerr<<#x"="<<(x)<<"\n";
#define foreach(it,v) for (__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)

char s[1100];

int main() {
	int tt,n;
	scanf("%d",&tt);
	for (int te=1;te<=tt;te++) {
		scanf("%d",&n);
		scanf("%s",s);
		int ans=0,all=0;
		for (int i=0;i<=n;i++) {
			int x=s[i]-'0';
			if (x>0 && all<i) {
				ans+=i-all;
				all=i;
			}
			all+=x;
		}
		printf("Case #%d: %d\n",te,ans);
	}
}
