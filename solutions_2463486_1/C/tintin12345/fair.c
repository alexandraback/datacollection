#include<stdio.h>
#include<stdlib.h>
#include<string.h>

long long int reverse(long long int no);
int pallindrome(long long int no);

int main(){
	long long int *square;
	int *count;
	long long int i,min,max;
	int cases,j,minindex,maxindex;
	square = (long long int *)malloc(10000012*sizeof(long long int));
	count = (int *)malloc(10000012*sizeof(int));
	count[0]=0;
	for(i=1;i<=10000011;i++){
		square[i]=i*i;
		if(pallindrome(square[i]) && pallindrome(i)){
			count[i]=count[i-1]+1;
		}
		else{
			count[i]=count[i-1];
		}
	}

	scanf("%d",&cases);
	for(i=1;i<=cases;i++){
		scanf("%lld",&min);scanf("%lld",&max);
		for(j=1;j<=10000002;j++){
			if(square[j]>=min){minindex=j-1;break;}
		}
		for(j=minindex;j<=10000002;j++){
			if(square[j]>max){maxindex=j-1;break;}
		}//printf("%d %d\n",minindex,maxindex);
		printf("Case #%d: %d\n",i,count[maxindex]-count[minindex]);
	}
}

int pallindrome(long long int no){
	if(no%10==0)return 0;
	long long int a;
	a=reverse(no);
	while(a>0){
		if(a%10==no%10){
			a=a/10;no=no/10;
		}
		else{
			return 0;
		}
	}
	return 1;
}

long long int reverse(long long int no){
	long long int a=0;
	while(no>0){
		a=a*10+no%10;
		no=no/10;
	}
	return a;
}
