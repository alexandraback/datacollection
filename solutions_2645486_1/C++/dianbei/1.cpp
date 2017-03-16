#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <string>
#include <map>
#include <set>
#include <iostream>
using namespace std;

typedef long long ll;
const ll inf=1LL<<50;

int a[10010],R[10010];
vector<pair<int,int> > st;
int main() {
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int T,ri=1,E,r,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&E,&r,&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		st.clear();
		for (int i = n; i >= 1; i--) {
			while (!st.empty() && st.back().second < a[i]) {
				st.pop_back();
			}
			if (st.empty())
				R[i] = n+1;
			else
				R[i] = st.back().first;
			st.push_back(make_pair(i, a[i]));
		}
		int t=E;
		ll ans=0;
		for(int i=1;i<=n;i++){
			if(R[i]==n+1){
				ans+=(ll)t*a[i];
				t=r;
			}else{
				int need=E-t;
				if(need>(ll)r*(R[i]-i)){
					t+=r;
				}else{
					ll tt=(ll)r*(R[i]-i)-need;
					if(tt>t)  tt=t;
					ans+=tt*a[i];
					t=t-tt+r;
					t=min(t,E);
				}
			}
		}
		printf("Case #%d: %I64d\n",ri++,ans);
	}
}
