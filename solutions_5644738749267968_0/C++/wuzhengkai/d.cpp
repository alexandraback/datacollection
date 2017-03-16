#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int tt,n;
double a[1000],b[1000];
bool f[1000];

int main() {
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);

	scanf("%d",&tt);

	for (int ii=1;ii<=tt;++ii) {
		scanf("%d",&n);
		memset(f,false,sizeof(f));
		for (int i=0;i<n;++i) cin >> a[i];
		for (int i=0;i<n;++i) cin >> b[i];
		sort(a,a+n); sort(b,b+n);
		int ans1=0,ans2=0;
		memset(f,false,sizeof(f));
		for (int i=0;i<n;++i) {
			int k=-1;
			for (int j=0;j<n;++j)
				if (!f[j]) {
					if (k==-1) k=j;
					else if (b[k]<a[i] && b[j]>=a[i]) k=j;
				}
			f[k]=true;
			if (b[k]>=a[i]) ans1++;
		}
		ans1=n-ans1;
		memset(f,false,sizeof(f));
		for (int i=0;i<n;++i) {
			int k=-1;
			for (int j=0;j<n;++j)
				if (!f[j]) {
					if (k==-1) k=j;
					else if (a[k]<b[i] && a[j]>=b[i]) k=j;
				}
			f[k]=true;
			if (a[k]>=b[i]) ans2++;
		}
		printf("Case #%d: %d %d\n",ii,ans2,ans1);
	}
}
