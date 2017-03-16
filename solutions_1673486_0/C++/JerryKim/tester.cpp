#include<iostream>
#include<fstream>
#include<string>

#include<sstream>
#include<vector>
#include<set>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;

int main(){
	int testcase;
	ifstream infile;
	ofstream outfile;
	infile.open("A-small-attempt0.in"); //filename//
	outfile.open("result.txt");
	
	infile>>testcase;

	for(int i=0;i<testcase;i++){
		int a,b;
		infile>>a>>b; //a:typed, b:total

		vector<double> prob;
		double temp;
		double cp = 1;
		for(int j=0;j<a;j++){
			infile>>temp;
			prob.push_back(temp);
			cp = cp*temp;
		}
		double ksmin = b + 2;

		for(int j=0;j<a;j++){
			double ks;
			double ksmax;
			ks = b - a + 1 + j*2;
			ksmax = ks + b + 1;

			if(j==0){
				double jks;
				jks = ks*cp + ksmax*(1-cp);
				if(ksmin>jks)
					ksmin = jks;
			}
			else{
				double jks;
				cp = cp/prob[a-j];
				jks = ks*cp + ksmax*(1-cp);
				if(ksmin>jks)
					ksmin = jks;
			}
		}
		

		

		//do something end
		outfile.setf(ios::fixed, ios::floatfield);
		outfile.precision(6);
		outfile<<"Case #"<<i+1<<": "<<ksmin<<"\n";
	}
	infile.close();
	outfile.close();
	return 0;
}