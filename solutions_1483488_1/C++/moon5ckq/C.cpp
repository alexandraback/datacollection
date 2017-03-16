#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<vector<int> > a;
bool mk[2000005];
int Case;

void Prepare() {
	for (int i=1;i<=2000000;++i)
		if (!mk[i]) {
			mk[i] = true;
			vector<int> b,d;
			b.push_back(i);
			int c[8], n=0;
			for (int j=i;j;j/=10)
				++n;
			for (int j=1, k=10;j<n;++j, k*=10) {
				int x = i/k, y= i%k;
				if (y >= k/10) {
					for (int l=j;l<n;++l)
						y*=10;
					b.push_back(y+x);
				}
			}
			
			sort(b.begin(), b.end());
			d.push_back(b[0]);
			for (int j=1;j<b.size();++j)
				if (d[d.size()-1] != b[j] && b[j]>=1 && b[j]<=2000000) {
					d.push_back(b[j]);
					mk[b[j]] = true;
				}
			if (d.size() > 1)
				a.push_back(d);
		}
}

int main() {
	scanf("%d", &Case);
	Prepare();
	/*for (int i=0;i<a.size();++i) {
		for (int j=0;j<a[i].size();++j)
			printf("%d ",a[i][j]);
		puts("");
	}*/
	for (int i=1;i<=Case;++i) {
		printf("Case #%d: ", i);
		int A,B, Ans=0;
		scanf("%d%d",&A, &B);
		for (int j=0;j<a.size();++j) {
			int count = 0;
			for (int k=0;k<a[j].size();++k)
				if (a[j][k]>=A && a[j][k]<=B) ++count;
			Ans += count * (count - 1)/2;
		}
		printf("%d\n", Ans);
	}
	return 0;
}