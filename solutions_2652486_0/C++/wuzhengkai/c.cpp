#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>

using namespace std;

int tt;
int r,n,m,k;
map<int,map<int,int> > hash;
map<int,int> now;

int main() {
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);

	scanf("%d",&tt);
	hash.clear();
	for (int ii=1;ii<=tt;++ii) {
		scanf("%d%d%d%d",&r,&n,&m,&k);
		for (int x=2;x<=5;++x)
			for (int y=2;y<=5;++y)
				for (int z=2;z<=5;++z) {
					int st=x*100+y*10+z;
					hash[st][1]++;
					hash[st][x]++;
					hash[st][y]++;
					hash[st][z]++;
					hash[st][x*y]++;
					hash[st][x*z]++;
					hash[st][y*z]++;
					hash[st][x*y*z]++;
				}
		printf("Case #1:\n");
		for (int i=0;i<r;++i) {
			int ans=0,ansl=222;
			now.clear();
			for (int j=0;j<k;++j) {
				int x;
				scanf("%d",&x);
				now[x]++;
			}
			for (map<int,map<int,int> >::iterator it=hash.begin();it!=hash.end();++it) {
				int cnt=0;
				for (map<int,int>::iterator it1=it->second.begin();it1!=it->second.end();++it1) {
					int idx=it1->first;
					cnt+=min(it1->second,now[idx]);
				}
				if (cnt>ans) {
					ans=cnt;
					ansl=it->first;
				}
			}
			cout << ansl << endl;
		}
	}
}
