#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1005;
int T;
int n;
double a[N],b[N];
int round=0;

int main()
{
	freopen("D-small-attempt0.in","r",stdin);
	freopen("war.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		int res1=0,res2=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%lf",&a[i]);
		for(int i=0;i<n;i++)
			scanf("%lf",&b[i]);
		sort(a,a+n);
		sort(b,b+n);
		int p=0,q=0;
		while(p<n && q<n){
			if(a[p]>b[q]){
				p++;
				q++;
				res1++;
			}
			else p++;
		}
		p=0,q=0;
		while(p<n && q<n){
			if(b[p]>a[q]){
				p++;
				q++;
				res2++;
			}
			else p++;
		}

		/*
		for(int i=0;i<n;i++)
			printf("%.5lf ",a[i]);
		printf("\n");
		for(int i=0;i<n;i++)
			printf("%.5lf ",b[i]);
		printf("\n");
		*/

		printf("Case #%d: %d %d\n",++round,res1,n-res2);
	}
	return 0;
}