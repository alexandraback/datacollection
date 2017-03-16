// leetcode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// Example program
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


int main()
{
    ifstream infile("A-large.in");
	ofstream outfile;//("OUTPUT.txt");
	outfile.open("OUTPUT.txt");
	long long t,n;
	int arr[10];
    int count = 0;
	infile>>t;
	for (int i=0; i<t; i++)
	{   memset(arr,0,sizeof(arr));
		infile >> n;
		count = 0;
        if (n == 0)
			outfile << "Case #"<<i+1<<": INSOMNIA"<<endl;
		else
		{   long long loop = 1;
		    do
			{
				long long tmp = loop*n;			
				while (tmp!=0)
				{
					int odd = tmp%10;
					tmp = tmp/10;
					
					if (arr[odd] == 0)
					{
						arr[odd] = 1;
						count++;
					}
				}
				if (count == 10)
				{
					outfile << "Case #"<<i+1<<": "<<loop*n<<endl;
				}
				else
					loop++;
			}
			while (count<10);
		}
	}
	infile.close();
	outfile.close();
	return 0;
}

