#include<iostream>
#include<cstdio>
#include<cmath>
#include<list>
using namespace std;

int tens[10] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
//int map[2000001] = {0};
int main() {
	int tc; scanf("%d",&tc);
	for(int t=1; t<=tc; t++) {
		int ans=0;
		int a,b; scanf("%d%d",&a,&b);
		int map[2000001]={0};
		int l = 1+(int)log10(1.0*a);
		for(int n=a;n<=b;n++) {
			list<int> L;
			int m = n, minn = n;
			for(int i=1;i<=l;i++) {
				//cout<<m<<"\n";
				if(m>=a && m<=b) {
					L.push_back(m);
					if(minn>m) minn = m;
				}
				m = tens[l-1]*(m%10) + m/10;
			}
			if (!map[minn]) {
				L.sort();
				L.unique();
				int l2 = L.size();
				int k = (l2 * (l2-1))/2;
				//if (k) cout<<"n = "<<n<<", point = "<<k<<"\n";
				ans += k;
				map[minn]=1;
			}
		}
		printf("Case #%d: %d\n", t, ans);
	}
}
