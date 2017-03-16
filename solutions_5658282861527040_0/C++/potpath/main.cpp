#include <cstdio>
#include <vector>
#include <functional>
using namespace std;
int main()
{
	int T,a,b,k;
	scanf("%d",&T);
	for (int iT=1; iT<=T; ++iT) {
		int ans=0;
		scanf("%d%d%d",&a,&b,&k);
		for (int i=0; i<a; ++i) {
			for (int j=0; j<b; ++j) {
				if ((i&j)<k) {
					++ans;
				}
			}
		}
		printf("Case #%d: %d\n",iT,ans);
	}
    return 0;
}