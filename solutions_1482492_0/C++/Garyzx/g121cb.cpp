#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main(){
	int numCases;
	ifstream fin("g121cb.in");
	ofstream fout("g121cb.out");
	fin>>numCases;
	fout.precision(10);
	for(int caseNum=0; caseNum<numCases; caseNum++){
		fout<<"Case #"<<caseNum+1<<":"<<endl;
		double distance;
		int N, numAccels;
		fin>>distance>>N>>numAccels;
		if(N==1){
			double t;
			fin>>t>>t;
			for(int n=0; n<numAccels; n++){
				double accel;
				fin>>accel;
				fout<<sqrt(2.*distance/accel)<<endl;
			}
		}
		else{
			double t1, t2, x1, x2;
			fin>>t1>>x1>>t2>>x2;
			double slope=(x2-x1)/t2;
			double otherTime=(distance-x1)/slope;
			for(int n=0; n<numAccels; n++){
				double accel;
				fin>>accel;
				double ourTime=sqrt(2.*distance/accel);
				fout<<max(ourTime, otherTime)<<endl;
			}
		}
	}
	return 0;
}
