#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<cstring>
#include<map>
#include<algorithm>
#include<vector>
#include<stdlib.h>

using namespace std;

#define MEM(v,i) memset(v,i,sizeof(v))

typedef long long int LL;

int main(){
	int test = 0, N = 0;
	int i = 0;
	double C = 0, F = 0, X = 0, rate = 0, cookies = 0, T = 0;
	double temp1, temp2, temp_time;
	scanf("%d",&test);
	for(int x_test = 1;x_test<=test; x_test++){
		scanf("%lf %lf %lf",&C,&F,&X);
		rate = 2.0;
		cookies = 0;
		T = 0;
		while(cookies<X){
//			cout<<"------------------------"<<endl<<flush;
			temp1 = (X-cookies)/rate;
			temp2 = (C-cookies)/rate;
			temp_time = temp2 + (X-0)/(rate+F);
//			cout<<"Time "<<T<<endl<<flush;
//			cout<<"Temp1 "<<temp1<<endl<<flush;
//			cout<<"Temp2 "<<temp2<<endl<<flush;
//			cout<<"Temp_Time "<<temp_time<<endl<<flush;
			if(temp1<= temp_time){
				T += temp1;
				cookies += temp1*rate;
			}
			else{
				T += temp2;
				cookies += temp2*rate;
				cookies = cookies-C;
				rate += F;
			}
//			cout<<"Rate "<<rate<<endl<<flush;
//			cout<<"Cookies "<<cookies<<endl<<flush;
//			cout<<"Time "<<T<<endl<<flush;
		}
		printf("Case #%d: %.7f\n",x_test,T);
	}
	return(0);
}
