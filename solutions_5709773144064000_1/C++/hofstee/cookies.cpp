#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

double C, F, X;

double timer (int farms){
	double rate = 2.0;
	double times = 0.0;
	for(int f = 0; f < farms; f++){
		times += C/rate;
		rate += F;
	}
	return times + X/rate;
}

int main(){
	ifstream fin ("B-large.in");
	FILE * fout;
	fout = fopen ("B-large.out","w");

	int T; fin >> T;
	for(int t = 0; t < T; t++){
		fin >> C >> F >> X;
		int farms = 0;

		double mintime = timer(farms);
		double newtime;

		do{
			farms++;
			newtime = timer(farms);
			if(newtime < mintime) mintime = newtime;
		}while(newtime <= mintime);

		fprintf(fout, "Case #%d: %.7f\n",t+1,mintime);
		cout << "solved testcase " << t+1 << endl;
	}

	fclose(fout);
	return 0;
}