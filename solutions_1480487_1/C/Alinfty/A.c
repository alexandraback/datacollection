#include <stdio.h>

void sort(int *point, int* ji, int n){
	int i,j;
	int temp;
	for(i=0;i<n;i++){
		for(j=0;j<n-1-i;j++){
			if(point[j]>point[j+1]){
				temp=point[j];
				point[j]=point[j+1];
				point[j+1]=temp;
				temp=ji[j];
				ji[j]=ji[j+1];
				ji[j+1]=temp;
			}
		}
	}
	return;
}
				
				

int main(){
	int t;
	int i,j,k;
	int sum;
	double use;
	int n;
	int point[200];
	double doupoint[200];
	double ing[200];
	int ji[200];
	scanf("%d", &t);
	for(i=1;i<=t;i++){
		sum=0;
		scanf("%d", &n);
		for(j=0;j<n;j++){
			scanf("%d", &point[j]);
			sum=sum+point[j];
		}
		printf("Case #%d:", i);
		for(j=0;j<n;j++){
			ji[j]=j;
			ing[j]=0;
		}
		sort(point,ji,n);
		for(j=0;j<n;j++){
			doupoint[j]=100*point[j]/(double)sum;
		}
		for(j=0;j<n;j++){
			use=0;
			for(k=0;k<j;k++){
				use=use+ing[k];
			}
			if(j==n-1){
				for(k=0;k<=j;k++){
					ing[k]=ing[k]+(100-use)/(double)n;
				}
				break;
			}
				

			if(((j+1)*(doupoint[j+1]-doupoint[j]))>(100-use)){
				for(k=0;k<=j;k++){
					ing[k]=ing[k]+(100-use)/(double)(j+1);
					doupoint[k]=doupoint[k]+(100-use)/(double)(j+1);
				}
				break;
			}
			else{
				for(k=0;k<=j;k++){
					ing[k]=ing[k]+doupoint[j+1]-doupoint[j];
					doupoint[k]=doupoint[j+1];
				}
			}
		}
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				if(ji[k]==j) break;
			}
			printf(" %lf", ing[k]);
		}
		printf("\n");
	}
	return 0;
}

