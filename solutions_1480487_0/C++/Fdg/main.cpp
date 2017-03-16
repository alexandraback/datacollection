#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>

#define ll long long

using namespace std;

const double eps=1e-12;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int TT=1;TT<=T;++TT) {
		printf("Case #%d:",TT);
		int n,arr[202]={0},sum=0;
		scanf("%d",&n);
		for(int i=0;i<n;++i) {
			scanf("%d",&arr[i]);
			sum+=arr[i];
		}
		for(int i=0;i<n;++i) {
			double l=0,r=1;
			for(int t=0;t<300;++t) {
				double m=(l+r)/2;
				double score=arr[i]+sum*m,need=m;
				for(int j=0;j<n;++j)
					if (i!=j&&score>=arr[j]) need+=(score-arr[j])/sum;
				if (need-eps<=1) l=m;
				else r=m;
			}
			printf(" %.7lf",l*100);
		}
		printf("\n");
	}
	return 0;
}
