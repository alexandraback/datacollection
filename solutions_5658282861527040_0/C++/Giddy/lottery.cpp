#include<cstdlib>
#include<iostream>
using namespace std;

int main(){
	int time;
	cin>>time;
	for(int t=0;t<time;t++){
		unsigned int A,B,K;
		cin>>A>>B>>K;
		int sum=0;
		for(unsigned int i=0;i<A;i++){
			for(unsigned int j=0;j<B;j++){
				if((i&j)<K)sum++;
			}
		}
		cout<<"Case #"<<t+1<<": "<<sum<<endl;
	}
}
