#include <iostream>
#include <fstream>

using namespace std;


int main()
{
	int n,N;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	fin>>N;
	fout.setf(ios::fixed);
	fout.precision(7);

	for(n=0;n<N;n++){
		double C,F,X;
		fin>>C>>F>>X;
		double MIN = X/2.0;
		double cooki = 2.0;
		double t = 0;
		double res;
		while(1){
			t += C/cooki;
			cooki += F;
			res = t + X/cooki;
			if(MIN > res)
				MIN = res;
			else
				break;
		}

				
		fout<<"Case #"<<n+1<<": "<<MIN<<endl;
	}


	return 0;
}


