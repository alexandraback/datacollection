#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <stdio.h>


using namespace std;




int main() {

	ifstream myfile ("example.txt");
	ofstream output;
	output.open("output.txt");
	int Nb;
	myfile>>Nb;

	for (int i=0;i<Nb;i++)
	{
		output<<"Case #"<<(i+1)<<": ";
		cout<<"Case #"<<(i+1)<<": "<<endl;
		double cpt;
		long int number;
		long int a;
		long int b;
		long int c;
		long int o;
		long int tmp;
		int x;
		int y;
		int size;
		myfile>>x;
		myfile>>y;
		myfile>>size;
		a=floor(y/size);
		cout<<"x y z "<<x<<" "<<y<<" "<<" "<<size<<endl;
		//cout<<"a"<<x<<endl;
		o=a*x+(size-1);
		if(y%size!=0)
		{
			o++;
		}

		output<<o<<endl;
		cout<<"ouput "<<o<<endl;
	}
	return 0;
}


