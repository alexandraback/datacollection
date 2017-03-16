#include<iostream>

using namespace std;

int main() {

	int nCases;
	cin>>nCases;
	
	for(int n=1; n<=nCases; n++) {
		int Smax;
		char S;
		cin>>Smax;
		int sum=0,friends=0;
		for(int i=0;i<Smax;i++) {
			cin>>S;
			sum+=S-48;
			if(sum<i+1) {
				friends++;
				sum++;
			}
		}
		cin>>S;
		cout<<"Case #"<<n<<": "<<friends<<endl;
	}

	return 0;
}
