#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 1000 + 10;
int n;
int a[maxn];
char str[maxn];
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("a.out","w",stdout);
	int T; cin>>T;
	for (int ii = 1;ii <= T;ii++){
		scanf("%d",&n); scanf("%s",str);
		for (int i = 0;i <= n;i++) a[i] = str[i] - '0';
		int ans = 0,now = a[0];
		for (int i = 1;i <= n;i++){
			if (!a[i]) continue;
			if (now >= i) now += a[i];
			else{
				int tt = i - now; ans += tt;
				now += tt + a[i];
			}
		}
		cout<<"Case #"<<ii<<": "<<ans<<endl;
	}
	return 0;
}
