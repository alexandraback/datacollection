//============================================================================
// Name        : Problem.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

void addTo(int N, vector<int> & v)
{
    for(;N;N/=10)
    	v[N%10] = 1;
}

bool check(vector<int> & v)
{
    if(v[0] == 0)
    	return false;
    if(v[1] == 0)
        	return false;
    if(v[2] == 0)
        	return false;
    if(v[3] == 0)
        	return false;
    if(v[4] == 0)
        	return false;
    if(v[5] == 0)
        	return false;
    if(v[6] == 0)
        	return false;
    if(v[7] == 0)
        	return false;
    if(v[8] == 0)
        	return false;
    if(v[9] == 0)
        	return false;
    return true;
}

int main()
{
	// open a file in read mode.
	ifstream infile;
//	infile.open("src/in");
	infile.open("src/A-large.in");

	// open a file in write mode.
	ofstream outfile;
	outfile.open("src/out");

	int T;
	infile>>T;
	for (int i = 1; i <= T; ++i)
	{
		int N,a;
		infile>>N;
		a = N;
		vector<int> seenDigits(10, 0);
		for(int j = 1; j <= 1250; ++j)
		{
			addTo(a, seenDigits);
			if(check(seenDigits))
			{
				outfile<<"Case #"<<i<<": "<<a<<endl;
				break;
			}
			a+=N;
		}
		if(!check(seenDigits))
			outfile<<"Case #"<<i<<": INSOMNIA"<<endl;
	}
	return 0;
}
