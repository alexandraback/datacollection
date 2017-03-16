#include <stdio.h>

int main(){
	int testn,test=1,i,j;
	double arr[100000];
	scanf("%d" , &testn);

	while(testn--){
		int A,B;
		double min=0,tem=1,sum;
		scanf("%d%d" , &A , &B);

		for(i=0;i<A;i++){
			scanf("%lf" , &arr[i]);
			tem *= arr[i];
		}
		arr[i] = 1;

		for(i=0;i<=A;i++){
			tem /= arr[A-i];
			sum = tem*(B-A+1+(i*2));
			sum += (1-tem)*(B-A+1+B+1+(i*2));
			if(i==0)
				min = sum;
			else if(min > sum)
				min = sum;
		}
		if(min>B+2)
			min = B+2;

		printf("Case #%d: %lf\n" , test++ , min);
	}
}
