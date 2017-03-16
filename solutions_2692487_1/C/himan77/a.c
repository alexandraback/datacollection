#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void mergesort(int i,int k,int j,int *p){
	int k1=i,k2=k+1,n,b,m;
	int q[j-i+1];
	
	for(m=0;m<=j-i;m++){
		if(p[k1]<p[k2] && k1<k+1){
				q[m]=p[k1];
				k1++;} 
		else if(p[k2]<=p[k1] && k2<j+1){
				q[m]=p[k2];
				k2++;}
		else if(k1>k){
				for(n=k2;n<=j;n++){
					q[m]=p[n];
					m++;}
					}
		else if(k2>j){
				for(n=k1;n<=k;n++){
					q[m]=p[n];
					m++;}
					}
		}
			
	for(b=i;b<=j;b++){
		p[b]=q[b-i];}	
				
}	
	

void merge(int i, int j,int *p){
	if(i==j)return;
	merge(i,(int)(floor((i+j)/2)),p);
	merge((int)(floor((i+j)/2+1)),j,p);
	
	mergesort(i,(int)(floor((i+j)/2)),j,p);
	}

int main(){

	int i,j,k,T,n,a,count;

	scanf("%d",&T);

	for(k=0;k<T;k++){

		scanf(" %d %d",&a,&n);
		count = 0;
		int mote[n];int subsum[n],check[n];subsum[0] = a;
		for(i=0;i<n;i++){
			scanf(" %d",&mote[i]);
			check[i] = 0;
			//subsum[i]=subsum[i-1]+mote[i];			
		}

	merge(0,n-1,mote);
	
	for(i=0;i<n;i++){
		if(subsum[i]>mote[i]){
			subsum[i+1]=subsum[i]+mote[i];}
		else {
			
			count++;if(check[i] == 0)check[i]=count;
			if((2*subsum[i]-1)>subsum[i]){
			subsum[i]=2*subsum[i]-1;
			i--;}
			else subsum[i+1]=subsum[i];
		}		
	}
	for(i=0;i<n;i++){
		if(check[i]!=0){if((check[i]+n-i-1)<count)count = check[i]+n-i-1;}
		}
	printf("Case #%d: %d\n",k+1,count);

	}




	return 0;

}
