#include<stdio.h>

int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int cas=1;cas<=T;cas++){
		int a,b;
		scanf("%d %d",&a,&b);
		double p[10];
		for(int i=0;i<a;i++){
			scanf("%lf",&p[i]);
		}
		double max=10.0*b;
		double pro[20];
		pro[0]=p[0];
		for(int i=1;i<a;i++){
			pro[0]*=p[i];
		}
		int m=1;
		if(a>1){
			for(int i=0;i<a;i++){
				pro[m]=1.0-p[i];
				for(int j=0;j<a;j++){
					if(i==j)continue;
					pro[m]*=p[j];
				}
				m++;
			}
		}
		if(a==3){
			for(int i=0;i<a;i++){
				pro[m]=1.0;
				for(int j=0;j<a;j++){
					if(i==j){

						pro[m]*=p[j];
					}
					else{
						pro[m]*=(1.0-p[j]);
					}
				}
				m++;
			}
		}
		pro[m]=1.0-p[0];
		for(int i=1;i<a;i++){
			pro[m]*=(1.0-p[i]);
		}
		m++;
		double exp=(b+1-a)*pro[0];
		for(int i=1;i<m;i++){
			exp+=(b+1-a+b+1)*pro[i];
		}
		if(max>exp)max=exp;
		if(a==1){
			exp=(b+2)*(pro[0]+pro[1]);
			if(max>exp)max=exp;
		}
		else if(a==2){
			exp=(1+b+1-1)*(pro[0]+pro[2]);
			exp+=(1+b+1-1+b+1)*(pro[1]+pro[3]);
			if(max>exp)max=exp;
			exp=(2+b+1)*(pro[0]+pro[1]+pro[2]+pro[3]);
			if(max>exp)max=exp;
		}
		else if(a==3){
			exp=(1+b+1-2)*(pro[0]+pro[3]);
			exp+=(1+b+1-2+b+1)*(pro[1]+pro[2]+pro[4]+pro[5]+pro[6]+pro[7]);
			if(max>exp)max=exp;
			exp=(2+b+1-1)*(pro[0]+pro[2]+pro[3]+pro[4]);
			exp+=(2+b+1-1+b+1)*(pro[1]+pro[5]+pro[6]+pro[7]);
			if(max>exp)max=exp;
		}
		exp=0;
		for(int i=0;i<m;i++){
			exp+=(1+b+1)*pro[i];
		}
		if(max>exp)max=exp;
		/*for(int i=0;i<m;i++){
			printf("%.6lf ",pro[i]);
		}
		printf("\n");*/
		printf("Case #%d: %.6lf\n",cas,max);
	}
	return 0;
}

