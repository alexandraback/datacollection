#include<stdio.h>
int a,b;
double p[100010],pro[100010];

int main(){
	freopen("b1.in","r",stdin);
	freopen("b1.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int cas=1;cas<=T;cas++){
		
		scanf("%d %d",&a,&b);
		for(int i=0;i<a;i++){
			scanf("%lf",&p[i]);
		}
		pro[0]=1.0;
		for(int i=1;i<=a;i++){
			pro[i]=pro[i-1]*p[i-1];
		}
		double max=(double)(1.0+(double)b+1.0);
		double exp=(b-a+1)*pro[a]+(b-a+1+b+1)*(1.0-pro[a]);
		if(max>exp)max=exp;
		for(int i=1;i<=a;i++){
			int id=a-i;
			exp=(i+b+1-id)*pro[id]+(i+b+1-id+b+1)*(1.0-pro[id]);
			if(max>exp)max=exp;
		}
		
		printf("Case #%d: %.6lf\n",cas,max);
	}
	return 0;
}

//
//double max=10.0*b;
		//double pro[20];
		//pro[0]=p[0];
		//for(int i=1;i<a;i++){
		//	pro[0]*=p[i];
		//}
		//int m=1;
		//if(a>1){
		//	for(int i=0;i<a;i++){
		//		pro[m]=1.0-p[i];
		//		for(int j=0;j<a;j++){
		//			if(i==j)continue;
		//			pro[m]*=p[j];
		//		}
		//		m++;
		//	}
		//}
		//if(a==3){
		//	for(int i=0;i<a;i++){
		//		pro[m]=1.0;
		//		for(int j=0;j<a;j++){
		//			if(i==j){

		//				pro[m]*=p[j];
		//			}
		//			else{
		//				pro[m]*=(1.0-p[j]);
		//			}
		//		}
		//		m++;
		//	}
		//}
		//pro[m]=1.0-p[0];
		//for(int i=1;i<a;i++){
		//	pro[m]*=(1.0-p[i]);
		//}
		//m++;
		//double exp=(b+1-a)*pro[0];
		//for(int i=1;i<m;i++){
		//	exp+=(b+1-a+b+1)*pro[i];
		//}
		//if(max>exp)max=exp;
		//if(a==1){
		//	exp=(b+2)*(pro[0]+pro[1]);
		//	if(max>exp)max=exp;
		//}
		//else if(a==2){
		//	exp=(1+b+1-1)*(pro[0]+pro[2]);
		//	exp+=(1+b+1-1+b+1)*(pro[1]+pro[3]);
		//	if(max>exp)max=exp;
		//	exp=(2+b+1)*(pro[0]+pro[1]+pro[2]+pro[3]);
		//	if(max>exp)max=exp;
		//}
		//else if(a==3){
		//	exp=(1+b+1-2)*(pro[0]+pro[3]);
		//	exp+=(1+b+1-2+b+1)*(pro[1]+pro[2]+pro[4]+pro[5]+pro[6]+pro[7]);
		//	if(max>exp)max=exp;
		//	exp=(2+b+1-1)*(pro[0]+pro[2]+pro[3]+pro[4]);
		//	exp+=(2+b+1-1+b+1)*(pro[1]+pro[5]+pro[6]+pro[7]);
		//	if(max>exp)max=exp;
		//}
		//exp=0;
		//for(int i=0;i<m;i++){
		//	exp+=(1+b+1)*pro[i];
		//}
		//if(max>exp)max=exp;
		///*for(int i=0;i<m;i++){
		//	printf("%.6lf ",pro[i]);
		//}
		//printf("\n");*/

