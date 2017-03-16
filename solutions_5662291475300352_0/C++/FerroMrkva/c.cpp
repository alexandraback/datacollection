#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int t;
int n;
int d[20],h[20],m[20];
vector<pair<long long,long long>> v;

int main(){
	scanf("%d",&t);
	for(int tt=1;tt<=t;++tt){
		scanf("%d",&n);
		printf("Case #%d: ",tt);
		v.clear();
		for(int i=0;i<n;++i){
			scanf("%d%d%d",d+i,h+i,m+i);
			for(int j=0;j<h[i];++j) v.emplace_back(make_pair(d[i],m[i]+j));
		}
		if ((360LL-v[0].first)*v[1].second<(360LL-v[1].first)*v[0].second){
			swap(v[0],v[1]);
		}
		if (v[1].second*(360LL-v[0].first)>=(360LL+360-v[1].first)*v[0].second){
			puts("1");
		} else puts("0");
	}
	return 0;
}
