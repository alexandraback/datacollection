#include<cstdio>
#include<iostream>

using namespace std;

int main(){
	int t;
	scanf("%d\n", &t);
	for(int iiii = 1; iiii<=t; iiii++){
		int smax;
		scanf("%d ", &smax);
		int req = 0, tnow = 0;
		char c = '0';
		int i;
		for(i=0; i<=smax; i++){
			c = getchar();
			if(c == ' ' || c == '0') continue;
			if(c == '\n') break;
			if(tnow < i){
				req += (i-tnow);
				tnow += (i-tnow);
			}
			if(c == '1') tnow += 1;
			if(c == '2') tnow += 2;
			if(c == '3') tnow += 3;
			if(c == '4') tnow += 4;
			if(c == '5') tnow += 5;
			if(c == '6') tnow += 6;
			if(c == '7') tnow += 7;
			if(c == '8') tnow += 8;
			if(c == '9') tnow += 9;
		}
		if(c != '0' && tnow < i) req += (i-tnow);
		cout<<"Case #"<<iiii<<": "<<req<<endl;
	}
}
