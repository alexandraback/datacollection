#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	freopen("B-large.in","r",stdin);
	freopen("out.txt","w",stdout);

	int tc;
	scanf("%d", &tc);
	for(int ti=1; ti<=tc; ti++){
		int n;
		int a[1010];
		scanf("%d",&n);
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]);
		}
		int mx=1000;
		for(int j = 1; j <= 1000; j++){
			double d=j;
			int s=0;
			for(int i = 0; i < n; i++){
				s+=((int)ceil(a[i]/d))-1;
			}
			if(j+s<mx)
				mx=j+s;
		}
		printf("Case #%d: %d\n",ti,mx);
	}
	return 0;
}