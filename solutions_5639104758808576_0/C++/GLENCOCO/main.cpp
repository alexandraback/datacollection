#include <iostream>
#include <string>

using namespace std;
void main(){
	//Read and Iterate over number of testcases
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++){
		int Smax;
		//Number of friends required for this testcase
		int F=0;
		//audience string
		string aud;
		//Total size of audience
		long long int A = 0;
		//Read testcase input
		cin >> Smax;
		cin >> aud;

		//Iterate over the shyness levels of the audience, determine the maximum number of friends required
		for (int s = 0; s <= Smax; s++){
			if ((A+F) < s){
				F = (s - A);
			}
			A += (int)(aud[s] - '0');
		}
		cout << "Case #" << t << ": " << F<<endl;
	}


}