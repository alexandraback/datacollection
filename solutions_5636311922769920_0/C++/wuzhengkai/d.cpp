#include <iostream>
#include <cstdio>
#include <cstdlib>
#define LL long long

using namespace std;

int tt,k,c,s;
LL f[101];

LL gen(int st,int ed) {
	LL res=0;
	for (int i=0;i<ed-st;++i)
		res+=f[c-i-1]*(st+i);
	return res;
}

int main() {
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);

	scanf("%d",&tt);

	for (int ii=1;ii<=tt;++ii) {
		printf("Case #%d:",ii);
		scanf("%d%d%d",&k,&c,&s);
		if (s*c<k) {
			printf(" IMPOSSIBLE\n");
			continue;
		}
		f[0]=1;
		for (int i=1;i<=c;++i)
			f[i]=f[i-1]*k;

		for (int i=0;i<(k-1)/c+1;++i)
			cout << " " << gen(i*c,min((i+1)*c,k))+1;
		cout << endl;
	}
}