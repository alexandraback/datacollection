#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>

using namespace std;

double C(int n,int k) {
	double ret=1; int left=n;
	for(int i=1;i<=k;++i) {
		ret*=(n-i+1);
		ret/=i;
		while(left&&ret>5) ret/=2,left--;
	}
	while(left) ret/=2,left--;
	return ret;
}

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
//	cout << C(5,0)+C(5,1) << endl;
/*	int sum=0,a=1;
	for(int i=0;i<10000;++i) {
		sum+=a; a+=4;
		cout << 2*i << "	" << sum << "	" << (a-1)/2 << endl;
		if (sum>1000000) break;
	}*/
	int T;
	scanf("%d",&T);
	for(int test=1;test<=T;++test) {
		printf("Case #%d: ",test);
		int n,x,y;
		scanf("%d%d%d",&n,&x,&y);
		if (x<0) x*=-1;
		int cnt=(x+y)/2,val=1;
		for(int i=0;i<cnt;++i) {
			n-=val;
			val+=4;
		}
		double p=0;
		if (n>0) {
			if (n>=val) p=1.0;
			else {
				if (x==0) p=0;
				else {
					val=(val-1)/2;
					if (n<=val)
						for(int j=y+1;j<=n;++j)
							p+=C(n,j);
					else {
						if (y<n-val) p=1.0;
						else {
							int add=n-val;
							n-=2*add; y-=(add);
							for(int j=y+1;j<=n;++j)
								p+=C(n,j);
						}
					}
				}
			}
		}
		printf("%.7lf",p);
		printf("\n");
	}
	return 0;
}