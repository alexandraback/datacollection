// leetcode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// Example program
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

string gen(string orig, int time)
{
	if (time == 1)
		return orig;
	string s = gen(orig, time-1);
	string re = "";
	int k = orig.length();
	for (int i=0; i<s.length(); i++)
		if (s[i] == 'G')
		{
			for (int j = 0; j<k; j++)
				re = re + "G";
		}
		else
		{
			re = re + orig;
		}
	return re;
}

int main()
{
    ifstream infile("D-large.in");
	ofstream outfile;//("OUTPUT.txt");
	outfile.open("OUTPUT2.txt");
	long t,n,j,k,c,s;
	
    long count = 0;
	infile>>t;
	long long arr[101];
	
	for (long i=0; i<t; i++)
	{   
		infile>>k>>c>>s;
		arr[0] = 0;
		for (long j = 1; j<=k; j++)
		    arr[j] = j;
		
		for (long j = 2; j<=c; j++)
			for (long f = 1; f<=k; f++)
			{
				if (f==k){
					arr[f] = arr[f]*k;
				}
				else{
					arr[f] = (arr[f]-1)*k + ((f+j-1)<k?(f+j-1):k);
				}
				//cout << j << "   " <<  f << "   " << arr[f] << endl;
			}

		long least = ceil(double(k)/c);
		if (s < least){
			outfile<<"Case #"<<i+1<<": IMPOSSIBLE"<<endl;
		}
		else
		{
			outfile<<"Case #"<<i+1<<": ";
			for (long f = 0; f<least; f++)
				outfile<<arr[f*c+1]<<" ";
			outfile<<endl;
		}
	}
	infile.close();
	outfile.close();
	return 0;
}


