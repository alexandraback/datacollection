#include <iostream>
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t,rep;
	scanf("%d",&t);
	for(rep=1;rep<=t;rep++) {
		int n,i,j,count=0;
		int a[2000],b[2000],c[2000]={0};
		scanf("%d",&n);
		for(i=0;i<n;i++) {
			scanf("%d %d",&a[i],&b[i]);
		}
		int star=0;
		while(star!=(2*n)) {
			count++;
			int min=3000, tar, atar;
			for(i=0;i<n;i++) {
				if(min>b[i] && c[i]!=2) {
					tar=i;
					min=b[i];
				}
			}
			if(min<=star) {
				if(c[tar]==1) star+=1;
				else if(c[tar]==0) star+=2;
				else break;
				c[tar]=2;
				continue;
			}
			for(i=0;i<n;i++) {
				if(min>a[i] && c[i]==0) {
					tar=i;
					min=a[i];
				}
				if(min==a[i] && c[i]==0) {
					atar=i;
					if(b[atar]<b[tar]) atar=tar;
				}
			}
			if(min<=star) {
				if(c[tar]!=0) break;
				else star+=1;
				c[tar]=1;
				continue;
			}
			break;
		}
		if(star==(2*n)) printf("Case #%d: %d\n",rep,count);
		else printf("Case #%d: Too Bad\n",rep);
	}
    return 0;
}
