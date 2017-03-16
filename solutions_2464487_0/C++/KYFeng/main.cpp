#include<iostream>
using std::cin;
using std::cout;
using std::endl;
void prob1(){
	int t, r, testCase;
	cin>>testCase;
	for(int i=0; i<testCase; i++){
		cin>>r>>t;
		int currentR = r;
		int count = 0;
		while(t>0){
			int area = (r+1)*(r+1)-r*r;
			if(t>=area){
				count++;
				t=t-area;
				r = r+2;
			}
			else
				break;
		}
		cout<<"Case #"<<1+i<<": "<<count<<endl;
	}
}
int main(){
	prob1();
}