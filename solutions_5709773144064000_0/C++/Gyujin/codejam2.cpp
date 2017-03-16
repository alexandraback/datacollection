#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int cases;
	double c,f,x;
	int n;
	double sum;
	int i;
	int j;
	ifstream fin;
	ofstream fout;
	fin.open("B-small-attempt0.in");
	fout.open("B-small-attempt0.out");
    fout.precision(7);
    fout.setf(ios::fixed, ios::floatfield);
	
	fin >> cases;
	for(i=1; i<=cases; i++){
		fin >> c;
		fin >> f;
		fin >> x;
		n = (int)floor(x/c - 2.0/f);
		if(n<0) n=0;
		sum = 0;
		for(j=1; j<=n; j++){
			sum += c/(2.0+(j-1)*f);
		}
		sum+=x/(2+n*f);
		fout << "Case #" << i << ": " << sum << endl;
	}
	fin.close();
	fout.close();
	return 0;
}