#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//istream& fin = cin;
//ifstream fin ("A-sample.txt");
ifstream fin ("A-small-attempt0.in");
ofstream fout ("A-small-attempt0.out");
//ifstream fin ("A-large.in");
//ofstream fout ("A-large.out");
//ostream& fout = cout;

double d[99999];

int main(){
  fout.precision(6);
	int t,a,b;
	fin >> t;
	for(int i=1; i<=t; i++){
		fin >> a >> b;
		double rs=b+2;
		
		for(int j=0; j<a; j++){
			fin >> d[j];
		}
		
    for(int j=0; j<a; j++){
			int yes = b-a+j*2+1;
			int no = yes+b+1;
			//cout << yes << ' ' << no << endl;
			double corr=1.0;
			for(int k=0; k<(a-j); k++){
				corr *= d[k];
			}
			double ex = yes*corr + no*(1-corr);
			//cout << corr << ' ' << ex << endl;
			if(ex < rs){
				rs = ex;
			}
		}
		
		fout << "Case #" << i << ": " << fixed << rs << endl;
	}
	system("pause");
}
