
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>
using namespace std;


vector<int> v;

bool test(int max, int K)
{
	for(int x : v){
		K -= (x-1) / max;
		if(K<0) return false;
	}
	return true;
}

bool test(int n)
{
	for(int i=0;i<n;++i) if(test(n-i, i)) return true;
	return false;
}

int main()
{
	int cs = 0, T=0;
	scanf("%d",&T);
	while(++cs <= T){
		v.clear();
		int n;
		scanf("%d",&n);
		for(int i=0; i < n; ++i){
			int t;
			scanf("%d",&t);
			v.push_back(t);
		}
		sort(v.begin(), v.end(), greater<int>());

		int l = 1, r = v.front();
		while(l<r){
			int mid = (l+r)/2;
			//printf("l=%d r=%d mid=%d\n",l,r,mid);
			if(test(mid)){
				r = mid;
			}
			else{
				l = mid+1;
			}
		}

		int res = l;

		printf("Case #%d: %d\n", cs, res);
	}

	return 0;
}
