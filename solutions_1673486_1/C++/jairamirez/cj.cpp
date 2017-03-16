#include <fstream>
#include <stdio.h>
using namespace std;
int main(){
	int T;
	int M;
	int A;
	double m[100002];
	double p;
	ifstream fin;
	ofstream fout;
	fin.open("A-large.in");
	fout.open("output.txt");
	
	fin>>T;
	double av;
	for(int t = 1;t<=T; t++){
		fin >> A >> M;
		m[0]=1;
		for(int i = 1; i<=A; i++){
			fin >> p;
			m[i]=m[i-1]*p;
		}
		
		av=10000000;
		double temp;
		for(int rt=0;rt<=A;rt++){
			temp = m[A-rt]*(M-A+2*rt+1)+(1-m[A-rt])*(2*M+2*rt+2-A);
			if(temp<av){
				av=temp;
			}
			//cout << temp << " ";
		}
		temp = M+2;
		//cout << temp << endl;
		if(temp<av)
			av=temp;
		fout.setf(ios::fixed,ios::floatfield);
		fout.precision(6);
		fout << "Case #" << t << ": " << av << endl;
		//printf("Case #%d: %.6lf\n", t, av);
		
		//cout << endl << endl << endl;
	}
	return 0;
}