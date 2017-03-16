#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>

#define ll long long

using namespace std;

int n,arr[22]={0};
int what[22]={0},ok=0,m1,m2;

set < pair <int,pair <int,int> > > f1;

void go1(int cur = 0,int dif = 0,int mask1 = 0,int mask2 = 0) {
	if (ok) return;
	if (cur==10) {
		f1.insert(make_pair(dif,make_pair(mask1,mask2)));
		if (dif==0&&(mask1||mask2)) {
			m1=mask1,m2=mask2;
			ok=true;
		}
		return;
	}
	go1(cur+1,dif,mask1,mask2);
	go1(cur+1,dif+arr[cur],mask1|(1<<cur),mask2);
	go1(cur+1,dif-arr[cur],mask1,mask2|(1<<cur));
}

void go2(int cur = 10,int dif = 0,int mask1 = 0,int mask2 = 0) {
	if (ok) return;
	if (cur==n) {
		set < pair <int,pair <int,int> > >::iterator it=f1.lower_bound(make_pair(-dif,make_pair(0,0)));
		if (it!=f1.end()&&it->first==-dif) {
			m1=(mask1)|it->second.first;
			m2=(mask2)|it->second.second;
			if (m1&&m2) ok=true;
		}
		return;
	}
	go2(cur+1,dif,mask1,mask2);
	go2(cur+1,dif+arr[cur],mask1|(1<<cur),mask2);
	go2(cur+1,dif-arr[cur],mask1,mask2|(1<<cur));
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int TT=1;TT<=T;++TT) {
		printf("Case #%d:\n",TT);
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%d",&arr[i]);
		f1.clear();
		ok=0; go1(); go2();
		if (ok) {
			int ss1=0,ss2=0;
			bool f=true;
			for(int i=0;i<n;++i)
				if (m1&(1<<i)) {
					if (!f) printf(" "); f=false;
					printf("%d",arr[i]);
					ss1+=arr[i];
				}
			printf("\n");
			f=true;
			for(int i=0;i<n;++i)
				if (m2&(1<<i)) {
					if (!f) printf(" "); f=false;
					printf("%d",arr[i]);
					ss2+=arr[i];
				}
			printf("\n");
			if (ss1!=ss2) cout << "fail\n";
		} else puts("Impossible");
	}
	return 0;
}
