//============================================================================
// Name        : cj13r1Aq1.cpp
// Author      : NioBium
// Version     :
// Copyright   : DaДџД±daram
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include "math.h"
using namespace std;

struct Comparison{
  bool operator() (int i,int j) { return (i > j);}
} comparison;

int main()
{
    ifstream inFile("data.in",std::ifstream::in);
    ofstream outFile("data.out");
    long T = 0;

    if (!inFile)
    	cout << "no file, aborting." << endl;
    else
    	inFile >> T;

    long long E, R, N, e, mk, val = 0;
    for (int i = 0; i<T; i++)
    {
    	val = 0;
    	cout << i << endl;
    	inFile >> E >> R >> N;
    	long long int* v = new long long [N];
    	if (!v)
    	{
    		cout << "new failed :(\n\r";
    		break;
    	}
    	else
    	{
    		e = E;
    		for (long n = 0; n<N; n++)
    			inFile >> v[n];
    		for (long n = 0; n<N; n++)
    		{
    			mk = 0;
    			for (long m=n+1;m<N;m++)
    			{
    			    if (v[m] > v[n])
    			    {
    			    	mk = max(mk, E - (m-n)*R);
    			    	if (mk > e)
    			    		break;
    			    }
    			}
    			if (e>=mk)
    			{
					val += v[n]*(e-mk);
//
					e = mk;

    			}
    			e+=R;
    			if (e>E) e = E;
    		}
    	}


    	outFile << "Case #" << i+1 << ": " <<    val   << "\n";
    }
    outFile.flush();
    outFile.close();

	return 0;
}
