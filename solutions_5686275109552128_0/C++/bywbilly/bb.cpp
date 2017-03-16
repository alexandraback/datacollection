#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 1000 + 10;
int n;
int a[maxn];
int main()
{
	freopen("1.in","r",stdin); freopen("1.out","w",stdout);
	int T; cin>>T; 
	for (int ii = 1;ii <= T;ii++){
		scanf("%d",&n); 
		for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
		sort(a + 1,a + 1 + n); int MAX = a[n],MIN = a[1];
		int ans = 0x7fffffff;
		for (int i = 1;i <= MAX;i++){
			int now = i,anst = i;
			for (int j = n;j >= 1;j--){
				if (a[j] <= now) break;
				int tt = 0,t = a[j];
				while(1){
					tt++; t -= now;
					if (t <= now) break;
				}
				anst += tt;
			}
			ans = min(ans,anst);
		}
		cout<<"Case #"<<ii<<": "<<ans<<endl;
	}
	return 0;
}