#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define ll long long
#define ii pair<int,int>
#define mp make_pair
#define pb push_back
#define INF 1000000000
int tc,n;
int f[1005],t1[1005],t2[1005],meet[1005];
int main() {
	scanf("%d",&tc);
	for (int kk=1;kk<=tc;kk++) {
		scanf("%d",&n);
		for (int i=0;i<n;i++) {
			scanf("%d",&f[i]);
			f[i]--;
		}
		int ans=0;
		for (int i=0;i<n;i++) {
			int x=f[i],y=f[f[i]];
			while(x!=y) x=f[x],y=f[f[y]];
			meet[i]=x;
			int len=1,c=f[x];
			while(c!=x) c=f[c],len++;
			ans=max(ans,len);
		}
		//printf("%d\n", ans);
		int sum=0;
		for (int i=0;i<n;i++) {
			if (f[i]>i && f[f[i]]==i) {
				//printf("%d and %d\n", i,f[i]);
				memset(t1,0,sizeof(t1));
				memset(t2,0,sizeof(t2));
				for (int j=0;j<n;j++) {
					if (meet[j]!=i && meet[j]!=f[i]) continue;
					int c=j,len=0;
					while(c!=i) c=f[c],len++;
					t1[j]=len;
					//printf("%d = %d\n", j,len);
				}
				for (int j=0;j<n;j++) {
					if (meet[j]!=i && meet[j]!=f[i]) continue;
					int c=j,len=0;
					while(c!=f[i]) c=f[c],len++;
					t2[j]=len;
				}
				int l1=0,l2=0;
				for (int j=0;j<n;j++) {
					if (t1[j]<t2[j]) l1=max(l1,t1[j]);
					else l2=max(l2,t2[j]);
				}
				sum+=(l1+l2+2);
			}
		}
		ans=max(ans,sum);
		printf("Case #%d: %d\n", kk,ans);
	}
}