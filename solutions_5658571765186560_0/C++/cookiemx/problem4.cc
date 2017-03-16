#include <iostream>
#include <vector>
using namespace std;

int main(){
	int cases;
	cin>>cases;
	for(int i =0;i<cases;i++){
		int X,R,C;
		cin>>X>>R>>C;
		bool win;
		if (X==1) win = 1;
		else if (X==2) {
			if((R*C)%2==0) win = 1;
			else win = 0;
		}
		else if (X == 3){
			if((R*C)<=3) win = 0;
			else if((R*C)%3!=0) win = 0;
			else win = 1;
		}else if( X==4 ){
			if(R == 4 && C ==4) win = 1;
			else if(R == 4 && C==3) win = 1;
			else if (R==3 && C==4) win = 1;
			else win = 0;
		}
		if(win == 1){
			cout<<"Case #"<<i+1<<": GABRIEL"<<endl;			
		}else {
			cout<<"Case #"<<i+1<<": RICHARD"<<endl;				
		}
	}
	return 0;
}
