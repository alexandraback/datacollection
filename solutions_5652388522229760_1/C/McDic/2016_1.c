#include <stdio.h>

int digit[10]={0,};

int pow(int a, int b){
	int c=1;
	while(b>0){
		b--;
		c*=a;
	} return c;
}

int countdigit(int a){
	
	int i=1, c=0;
	while(a>0){
		//printf("TEST %d\n", a%10);
		digit[a%10]++;
		a/=10;
		c++;
	}
	
	return c;
}

int main(void){
	
	freopen("A-large.in", "r", stdin);
	freopen("output_2016_1_large.txt", "w", stdout);
	
	int i, j, k, testcase, booll, status;
	int temp, tempdigit, tenpow;
	scanf("%d", &testcase);
	
	for(k=1; k<=testcase; k++){
		
		for(i=0; i<10; i++) digit[i]=0;
		scanf("%d", &temp);
		j=1; status=0;
		
		tempdigit = countdigit(temp)+1;
		tenpow = pow(10,tempdigit);
//		printf("TENPOW = %d, TEMPDIGIT = %d\n", tenpow, tempdigit);
		while(tenpow>0){
			tenpow--;
			countdigit(temp*j);
			j++;
			
			booll=1;
			for(i=0; i<10; i++){
				if(digit[i]==0) booll=0;
			}
			if(booll==1){
				status=j;
				break;
			}
		}
		
		if(status==0){
			printf("Case #%d: INSOMNIA\n", k);
		}
		else{
			printf("Case #%d: %d\n", k, (status-1)*temp );
		}
	}
	
	return 0;
}
