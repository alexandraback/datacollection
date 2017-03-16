#include<stdio.h>
#include<stdlib.h>

int main ()
{
	int b[1000][2],yeno;
	int t,n,l[1000][2],s,total,max,tmp,i,j;
	
	scanf("%d",&t);
	for (i=1;i<=t;i++){
		scanf("%d",&n);
		for (j=0;j<n;j++){
			scanf("%d %d",&l[j][0],&l[j][1]);
			b[j][0]=0;
			b[j][1]=0;
		}
		s=0;
		total=0;
		while (s!=2*n){
			yeno=0;
			for (j=0;j<n;j++){
				if (b[j][1]==0 && s>=l[j][1]) {
					if (b[j][0]==1) {
						s++;
					} else {
						s+=2;
					}
					b[j][0]=1;
					b[j][1]=1;
					yeno=1;
					total++;
				}
			}
	if (yeno==0){
		max=-1;
		for (j=0;j<n;j++) {
			if (b[j][0]==0 && s>=l[j][0]) {
				if (l[j][1]>max) {
					max=l[j][1];
					tmp=j;
				}
				yeno=1;
			}
		}
		if (yeno==1){
			s++;
			total++;
			b[tmp][0]=1;
		}
	}
	if (yeno==0){
		total=-1;
		s=2*n;
	}
}
if (total==-1){
printf("Case #%d: Too Bad\n",i);
} else {
printf("Case #%d: %d\n",i,total);
}
}
return 0;
}
