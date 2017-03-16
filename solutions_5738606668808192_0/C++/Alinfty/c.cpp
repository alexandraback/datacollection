#include <iostream>

using namespace std;

int main(){
	int t;
	cin>>t;
	int n,j;
	cin>>n>>j;
	cout<<"Case #1:"<<endl;
	for(int i=0;i<j;i++){
		cout<<1;
		int num=i;
		for(int k=0;k<(n-2)/2;k++){
			cout<<num%2<<num%2;
			num/=2;
		}
		cout<<1<<" 3 4 5 6 7 8 9 10 11"<<endl;
	}
	return 0;
}
