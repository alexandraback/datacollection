#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <fstream>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[]) {
	if(argc < 2) {
		printf("No input file\n");
		return -1;
	}
	ifstream input;
	input.open(argv[1]);
	ofstream output;
	output.open("output");
	
	// number of cases
	int caseNum = 0;
	input>>caseNum;
	int counter = 0;
	while(counter < caseNum) {
		double c,f,x;
		double result = 0.0;
		double rate = 2.0;
		double start = 0;
		input>>c>>f>>x;
		if(start >= x);
		else {
			if(start < c) {
				result = result + (c-start)/rate;
				start = c;
			}
			double r1 = (x - start)/rate;
			double r2 = (x - (start-c))/(rate+f);
			while(r1 > r2) {
				rate = rate + f;
				result = result + (c-(start-c))/rate;
				start = c;
				r1 = (x - start)/rate;
			    r2 = x/(rate+f);
			}
			result = result + r1;
		}
		output<<"Case #"<<counter+1<<": "<<setiosflags(ios::fixed)<<setprecision(7)<<result<<endl;
		counter ++;
	}
	input.close();
	output.close();
	return 0;
}