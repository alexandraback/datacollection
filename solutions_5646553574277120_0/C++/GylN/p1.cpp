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
		long int b=0;
		long int c;
		long int o=0;
		int tmp;
		int x;
		int y;
		myfile>>c;
		myfile>>y;
		myfile>>a;
		vector <int> v;
		for (int j=0;j<y;j++)
		{
			myfile>>tmp;
			v.push_back(tmp);
			cout<<v[j]<<endl;
		}
		v.push_back((a+1));
		cout<<v[y]<<endl;
		cout<<"b"<<b<<endl;
		for(int i=0;i<=y;i++)
		{
			while(b<v[i]-1)
			{
				cout<<"add"<<endl;
				o++;
				b=(b+1)*(c+1)-1;

			}
			b=b+c*v[i];
			cout<<" b = "<<b<<"at iteration "<<i<<endl;
		}
		output<<o<<endl;
		cout<<"output "<<o<<endl;
	}
	return 0;
}


