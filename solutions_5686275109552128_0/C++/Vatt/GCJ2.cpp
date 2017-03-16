#include <stdio.h>
#include <algorithm>
using namespace std;
int n,a[1005];
int main(int argc, char *argv[])
{
	int t;
	scanf("%d",&t);
	for(int r=1;r<=t;r++) {
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		printf("Case #%d: ",r);
		int minn = 1000;
		for(int max_each = 1;max_each<=1000;max_each++) {
			int sum = 0;
			for(int j=0;j<n;j++) {
				int div = a[j]/max_each;
				if(max_each*div<a[j]) div++;
				sum+=div-1;
			}
			minn=min(minn,sum+max_each);
		}
		printf("%d\n",minn);
	}
	
	return 0;
}
