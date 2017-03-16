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

int main()
{
    ifstream infile("C-large.in");
	ofstream outfile;//("OUTPUT.txt");
	outfile.open("OUTPUT.txt");
	unsigned long t,n,j;
	int arr[32];
    int count = 0;
	infile>>t;
	string s;
	
	for (int i=0; i<t; i++)
	{   
		outfile<<"Case #"<<t<<":"<<endl;
		infile >> n >> j;
		unsigned long num = (1<<(n/2-1))+1;
		while (count<j)
		{
			
			unsigned long numnum = num;
			//for (int i =0; i<n/2; i++)
			//	numnum = numnum | (((num>>i)&1)<<(n-i-1);
			//for (int i = 0; i<n/2; i++)
			//	outfile<<((num>>i)&1);			
			for (int i = n/2; i>0; i--)
				outfile<<((num>>(i-1))&1);
			for (int i = n/2; i>0; i--)
				outfile<<((num>>(i-1))&1);
			outfile<<" ";
			
			for (int base = 2; base <= 10; base++)
			{
				long long part = 0;
				for (int i=0; i<n/2; i++)
				{
					part += (((num>>i)&1)*pow((long double)base,i));
					//cout<<pow((long double)base,i)<<" ";
					//cout<<"*"<<part<<"*"<<((num>>i)&1)<<"*"<<(((num>>i)&1)*pow((long double)base,i))<<"*"<<" ";
				}
				//cout<<"["<<part<<"]"<<endl;
				outfile<<part<<" ";
			}
			outfile<<endl;			
			num+=2;
			count++;
		}
	}
	infile.close();
	outfile.close();
	return 0;
}

