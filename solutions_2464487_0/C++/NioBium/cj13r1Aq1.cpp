//============================================================================
// Name        : cj13r1Aq1.cpp
// Author      : NioBium
// Version     :
// Copyright   : Dağıdaram
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

    /*int arr[] = {0,1,2,3,4,5,6};
    vector<int>  vect(arr, arr+7);
    sort(vect.begin(),vect.end(),comparison);
    //for (int i=0;i<7;i++) cout << vect[i] << " ";*/
    for (int i = 0; i<T; i++)
    {
    	cout << i << endl;
    	long long int r,t;
    	inFile >> r >> t;

    	long long low = 0, high = ceil(sqrt(t>>1))+1;

    	unsigned long long amount;
    	long long mid;
    	while (high-low>1)
    	{
    		mid = (low + high)/2;
    		amount = (2*r-1)*mid+2*mid*mid;

    		if (amount>t)
    		{
    			high = mid;
    		}
    		else if (amount<t)
    		{
    			low = mid;
    		}
    		else
    			break;
    	}

    	mid = mid -4 < 0 ? 0 : mid -4;
    	do
    	{
    		mid++;
    		amount  = (2*r-1)*mid+2*mid*mid;
    	}	while (amount <= t);

    	outFile << "Case #" << i+1 << ": " << mid-1 << "\n";
    }
    outFile.flush();
    outFile.close();

	return 0;
}
