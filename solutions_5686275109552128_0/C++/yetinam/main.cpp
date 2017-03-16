#include <cstdlib>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	for (int r=1;r<=t;r++) {
		int d;
		scanf("%d",&d);
		vector <int> plates;
		for (int i=0;i<d;i++) {
			int tmp;
			scanf("%d",&tmp);
			plates.push_back(tmp);
		}
		sort(plates.begin(),plates.end());
		int min=0;
		int max=plates[d-1];
		while (max-min>1) {
			int m=(max+min)/2;
			//printf("%d %d %d\n",min,max,m);
			bool pos=false;
			for (int s=0;s<m;s++) {
				int count=0;
				for (int p=d-1;p>=0;p--) {
					//printf("S %d %d %d %d %d %d\n",min,max,m,s,p,plates[p]);
					if (plates[p]<=m-s) {
						break;
					}
					if (plates[p]>m-s) {
						count+=(plates[p]-1)/(m-s);
					}
				}
				if (count<=s) {
					//printf("O %d %d\n",s,count);
					pos=true;
					break;
				}
			}
			if (pos) {
				max=m;
			} else {
				min=m;
			}
		}
		printf("Case #%d: %d\n",r,max);
	}
	return 0;
}
