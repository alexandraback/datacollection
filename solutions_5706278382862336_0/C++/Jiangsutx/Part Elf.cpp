#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

long long gcd(long long a, long long b)
{
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
	ofstream ofile;
	ifstream ifile;

	ofile.open("A-small-attempt1-out.txt");		
	ifile.open("A-small-attempt1.in");			
	//ofile.open("A-small-out.txt");		
	//ifile.open("A-small.txt");		

	long T;
	long long N, P, Q;
	
	

	ifile>>T;
	for (int iT=1; iT<=T;iT++)
	{
		char ch;
		ifile>>P;
		ifile>>ch;
		ifile>>Q;

		long long gc = gcd(Q,P);
		P = P/gc;
		Q = Q/gc;

		long long t = Q;
		while (t>0)
		{
			if (t%2 == 0)
			{
				t = t>>1;
			}
			else
				break;
		}
		if (t>1)
		{
			ofile<<"Case #"<<iT<<": impossible"<<endl;
			continue;
		}

		t = Q;
		int count = 0;
		while (t>P)
		{
			t = t>>1;
			count++;
		}
		if (count<=40)
		{
			ofile<<"Case #"<<iT<<": "<<count<<endl;
		}
		else
		{
			ofile<<"Case #"<<iT<<": impossible"<<endl;
		}
	}
	ifile.close();
	ofile.close();
	system("pause");
}