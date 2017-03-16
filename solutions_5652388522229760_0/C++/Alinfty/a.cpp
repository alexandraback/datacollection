#include <iostream>
#include <string>

using namespace std;

//int check[10];
int check=0b0000000000;

int fill(int num){
	while(1){
		if(num==0) break;
		check |= 1<<(num%10);
		num/=10;
	}
	return 0;
}

int main(){
	int t;
	cin>>t;
	cin.get();
	for(int i=1;i<=t;i++){
		int num;
		cin>>num;
		cout<<"Case #"<<i<<": ";
		if(num==0) cout<<"INSOMNIA"<<endl;
		else{
			check=0b0000000000;
			int j=1;
			while(1){
				fill(j*num);
				if(check==0b1111111111) break;
				else j++;
			}
			cout<<j*num<<endl;
		}
	}
	return 0;
}
