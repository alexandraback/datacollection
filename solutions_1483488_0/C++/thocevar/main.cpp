#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> f[2000001];
int p10[10];

int main() {
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);

	p10[0]=1;
	for (int i=1;i<=9;i++) p10[i]=p10[i-1]*10;
	for (int i=1;i<=2000000;i++) {
		int x=i,len=0;
		while (x>0) { x/=10; len++; }
		x=i;
		for (int j=0;j<len;j++) {
			int d=x%10;
			x=x/10+d*p10[len-1];
			if (d!=0) f[i].push_back(x);
		}
		sort(f[i].begin(),f[i].end());
		f[i].resize(unique(f[i].begin(),f[i].end())-f[i].begin());
	}

	int tests;
	scanf("%d",&tests);
	for (int test=1;test<=tests;test++) {
		int a,b,r=0;
		scanf("%d %d",&a,&b);
		for (int n=a;n<=b;n++) {
			for (int i=0;i<f[n].size();i++) {
				int m=f[n][i];
				if (n<m && m<=b) r++;
			}
		}
		printf("Case #%d: %d\n",test,r);
	}
    return 0;
}
