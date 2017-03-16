#include <iostream>
#include <vector>
#include <string>
using namespace std;

string Shy;

vector<int> Shyness(1001);




int main() {

	freopen("debug\\A-large.in","r",stdin);
	freopen("debug\\out.txt","w",stdout);
	

	int testcases = 0, Smax = 0;
	int adda = 0, ca = 0;
	cin>>testcases;

	for (int i=0; i<testcases; i++) {
		cin>>Smax;
		
		cin>>Shy;
		adda = 0;
		ca = 0;
//		cout<<Shy<<endl;
		for (int j=0; j<Smax+1; j++) {
			Shyness[j]=Shy[j]-'0';
//			cout<<Shyness[j];
		}//for j Smax
//		cout<<endl;
		
		ca = Shyness[0];
		for (int j=1; j<Smax+1; j++) {
			if (ca<j) {
				adda+=(j-ca);
				ca = j;
			}

			ca+=Shyness[j];
		}//end for j judge


		cout<<"Case #"<<i+1<<": "<<adda<<endl;



	}//for i testcases



	return 0;
}