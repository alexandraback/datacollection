#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool map[2000000];
int result;

int getPow(int b){
	int pow=1;
	while(b/=10){
		pow*=10;
	}
	return pow;
}

void isRecycled(int i,int a,int b){
	int t=1;
	if(i<10 || map[i]){
		return;
	}else{
		map[i]=true;
		int pow=getPow(i);
		int pow1=10,pow2;
		int tempA;
		int r;
		while(pow){
			r=i%pow1*pow+i/pow1;
			if(r>=a && r<=b && r!=i && (!map[i] || !map[r])){
				map[r]=true;
				t++;
			}
			pow/=10;
			pow1*=10;
		}
		result+=  ( (t-1)*t/2 );
	}
}

int main(){
	ifstream cin("C-large.in");
	ofstream cout("C-large.out");

	int casees;
	cin >> casees;
	int a,b;
	int t=0;
	while(casees--){
		memset(map,false,2000000);
		cin >> a >> b;
		result=0;
		for(int i=b;i>a;i--){
			isRecycled(i,a,b);
			
		}
		cout << "Case #" << ++t << ": "<< result << endl;

	}


	return 0;
}