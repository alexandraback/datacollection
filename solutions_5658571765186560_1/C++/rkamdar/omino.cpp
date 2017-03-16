#include<iostream>

using namespace std;

int X;
int R;
int C;

int main(){
	int T;
	cin >> T;
	for(int test_case=0; test_case<T; test_case++){
		cin >> X;
		cin >> R;
		cin >> C;
		
		int flag=0;
		
		if((R*C)%X != 0){
			flag = 1;
		}
		
		switch(X){
			case 1:	flag = 0;
					break;
			case 2: break;
			case 3: if((R*C)<6)	flag=1;
					break;
			case 4: if((R*C)<12)	flag=1;
					break;
			case 5: if((R*C)<20)	flag=1;
					break;
			case 6:	if((R*C)<24)	flag=1;
					break;
			default:flag=1;
					break;
		}
		
		cout << "Case #" << test_case+1 << ": ";
		if(flag == 1){
			cout << "RICHARD" << endl;
		} else {
			cout << "GABRIEL" << endl;
		}
		
	}
	return 0;
}
