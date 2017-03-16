#include <stdio.h>

int shift(int number, int number_base)
{
int right,number2,ten_times;

right = number % 10;
number2 = number_base ;
ten_times = 1;
while((number2 = number2/10) != 0) ten_times *=10;
return  (right * ten_times) + (number/10);
}

int compute(int A,int B)
{
int n;
int count;

count = 0;
for(n = A; n < B; n++) {
	 int temp;
         temp = shift(n, n);
	 while(temp != n) {
		 if((temp > n ) && (temp <= B)) count++;
		 temp = shift(temp,n);	
		}
	}
return count;
}

int main()
{
int T,A,B,n,m;
int i;

scanf("%d",&T);
for(i =0; i< T; i++) {
	scanf("%d %d",&A,&B);
        printf("Case #%d: %d\n", i+1, compute(A,B));	
	}
}
