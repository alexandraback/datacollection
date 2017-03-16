#include <stdio.h>
#include <math.h>

int shift(int num,int d);
int digit(int num);

int main()
{
	int test_case, pairs, temp;
	int a,b,d,i,j;
	FILE* fp;
	
	fp = fopen("output.txt","w");

	scanf("%d",&test_case);

	for(i=1; i<=test_case; i++) {
		pairs=0;
		scanf("%d %d",&a,&b);
		d = digit(a);
		for(j=a; j<=b; j++) {
			temp = shift(j,d);
			while(temp!=j) {
				if(temp < j) {
					temp = shift(temp,d);
					continue;
				}
				else if(temp > b) {
					temp = shift(temp,d);
					continue;
				}
				pairs++;
				temp = shift(temp,d);
			}
		}
		fprintf(fp,"Case #%d: %d\n",i,pairs);
	}
	return 0;
}
int shift(int num,int d)
{
	int k;

	k = num/(int)pow((double)10,d-1);
	
	return ((num*10)+k)-(k*(int)pow((double)10,d));
}
int digit(int num)
{
	int temp = num;
	int d=0;

	while(temp) {
		d++;
		temp/=10;
	}

	return d;
}