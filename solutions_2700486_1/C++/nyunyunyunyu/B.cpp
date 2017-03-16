#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int T,n,x,y,o;
double p[3011][3011];
int main(){
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	cin>>T;
	while (T--){
		o++;
		cin>>n>>x>>y;
		int l=1,r=n,mid,k;
		while (l!=r){
			mid=l+r-(l+r)/2;
			if ((long long)(mid*2-1)*mid<=n)l=mid;
			else					 r=mid-1;
		}
		k=l;
		n-=(k*2-1)*k;
		if (x<0)x=-x;
		int w=(x+y)/2+1;
		if (w<=k){
			cout<<"Case #"<<o<<": 1.0\n";
			continue;
		}
		if (w>k+1){
			cout<<"Case #"<<o<<": 0.0\n";
			continue;
		}
		k++;
		w=y+1;
		if (w>n){
			cout<<"Case #"<<o<<": 0.0\n";
			continue;
		}
		int lim=min(k*2-2,n);
		double sum = 0;
		memset(p, 0, sizeof(p));
		p[0][0]=1;
		for (int i = 1;i <= lim;i++){
			p[0][i] = p[0][i-1] * 0.5;
			if (i==n&&i>=w)sum+=p[0][i];
		}
		for (int i = 1;i <= lim;i++){
			p[i][0] = p[i-1][0] * 0.5;
			for (int j = 1;j <= lim && i + j <= n;j++){
				if (j==lim) p[i][j]+=p[i-1][j];
				else		p[i][j]+=p[i-1][j]*0.5;
				if (i==lim) p[i][j]+=p[i][j-1];
				else		p[i][j]+=p[i][j-1]*0.5;
				if (i + j == n && j >= w) sum+=p[i][j];
			}
		}
		printf("Case #%d: %.7f\n",o,sum);
	}
	return 0;
}

