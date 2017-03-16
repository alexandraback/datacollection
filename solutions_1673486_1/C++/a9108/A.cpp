#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>

using namespace std;

#define MP make_pair
#define PB push_back

double p[110000];
int n,m;
int T;

int main(){
	scanf("%d",&T);
	for (int ti=1;ti<=T;ti++){
		scanf("%d%d",&m,&n);
		p[0]=1;
		for (int i=1;i<=m;i++){
			scanf("%lf",&p[i]);
			p[i]*=p[i-1];
		}
		double ans=n+2;
		for (int z=0;z<=m;z++){
			ans=min(ans,p[m-z]*(n-m+z+1+z)+(1-p[m-z])*(n+2+n-m+z+z));
		}
		printf("Case #%d: %.10f\n",ti,ans);
	}
    return 0;
}
