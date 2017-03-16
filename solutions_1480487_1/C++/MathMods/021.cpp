#include <cstdio>
#include <iostream>
#include <fstream>
#include "minmax.h"
using namespace std;

double p[10];
int main(int argc, char* argv[]) {

	char *input="A-small-practice.IN";
	char *output="Output.txt";
	ifstream fin; 
    ofstream fout;
	fin.open(input);
	fout.open(output);

  double pr, avg;
  int T, X, N, count=1, num;
  for (fin >> T; T--;) {
    fin >> N;
	X=0;
    int i;
	for (i = 0; i < N; i++){
		fin >> p[i];
		X+=p[i];
	}
    num=N;
	avg=0;
	for (i = 0; i <N; i++)
		if (p[i]>=(double)X*2.0/N) num--;
			else avg+=p[i];
	avg=(avg+X)/num;

	fout<<"Case #"<<count++<<": "; 
	for (i = 0; i <N; i++) {
    fout.setf(ios::showpoint);
	fout.precision(8);
	fout.width(12);
	
	if (p[i]>=(double)(X*2)/double(N)) pr=0.000000;
		else pr=(avg-p[i])/(double)X*100;
	fout<<pr;
	}
	fout<<"\n";
//	printf("Case #%d: %.10lf\n", prob++, ret);
  }

     fin.close();
	fout.close();
return 0;
}
