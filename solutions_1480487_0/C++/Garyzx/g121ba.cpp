#include <iostream>
#include <fstream>
#include <bitset>

using namespace std;

int main(){
	int numCases;
	ifstream fin("g121ba.in");
	ofstream fout("g121ba.out");
	fin>>numCases;
	for(int caseNum=0; caseNum<numCases; caseNum++){
		int length, sum=0;
		double points[200];
		fin>>length;
		for(int n=0; n<length; n++){
			fin>>points[n];
			sum+=points[n];
		}
		for(int n=0; n<length; n++)
			points[n]/=sum;
		bitset<200> done;
		double answer[200];
		while(true){
			int notDone=0;
			double avg=0;
			for(int n=0; n<length; n++)
				if(!done[n]){
					avg+=points[n];
					notDone++;
				}
			avg/=notDone;
			bool good=true;
			for(int n=0; n<length; n++)
				if(!done[n] && points[n]>1./notDone+avg){
					good=false;
					done[n]=true;
					answer[n]=0;
				}
				else if(!done[n])
					answer[n]=1./notDone+avg-points[n];
			if(good)
				break;
		}
		fout<<"Case #"<<caseNum+1<<":";
		fout.precision(10);
		for(int n=0; n<length; n++)
			fout<<" "<<answer[n]*100;
		fout<<endl;
	}
	return 0;
}
