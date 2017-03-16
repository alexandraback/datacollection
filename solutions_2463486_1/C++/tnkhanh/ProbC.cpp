#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>

#define FI first
#define SE second
#define MP make_pair

using namespace std;

const int MAXN=int(1e7);

int tnum, nfs;
long long fs[MAXN/100], a, b;

bool fairsq(long long x){
	int dig[18], nd=0;
	while (x){
		dig[++nd]=x%10;
		x/=10;
	}
	
	for (int i=1; i<=nd/2; i++) if (dig[i]!=dig[nd-i+1]) return false;
	return true;
}

int main(){
	for (long long i=1; i<=MAXN; i++) if (fairsq(i) && fairsq(i*i)) fs[++nfs]=i*i;

	scanf("%d", &tnum);
	for (int t=1; t<=tnum; t++){
		scanf("%lld %lld", &a, &b);	
		
		int r=0, l=nfs+1;
		for (int i=1; i<=nfs; i++) 
			if (fs[i]>=a){
				l=i;
				break;
			}
			
		for (int i=nfs; i>=1; i--)
			if (fs[i]<=b){
				r=i;
				break;
			}
		
		if (r<l) printf("Case #%d: 0\n",t);
		else
			printf("Case #%d: %d\n", t, r-l+1);
	}
	return 0;
}
