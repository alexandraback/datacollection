#include <math.h>
#include <stdio.h>
int buf[10],bn;
int main()
{
	int T,a,b,ans;
	scanf("%d",&T);
	for(int tt=1;tt<=T;tt++) {
		scanf("%d%d",&a,&b);
		ans=0;
		for (int k=a;k<=b;k++) {
			int n=(int)(log((double)k)/log(10.0)),m=1,p=10*pow(10,n);
			bn=0;
			for(int i=0;i<=n;i++) {
				int tmp=k/m+(k%m)*(p/m);
				if (tmp<=b&&tmp>k) {
					bool flag=true;
					for(int j=0;j<bn;j++) {
						if(buf[j]==tmp) {
							flag=false;
							break;
						}
						}
					if (flag) {
						//printf("%d %d\n",k,tmp);
						ans++;
						buf[bn++]=tmp;
					}
				}
				m*=10;
			}
		}
		printf("Case #%d: %d\n",tt,ans);
	}
}
