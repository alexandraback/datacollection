/*************************************************************************
    > File Name: fairSquare_small.cpp
    > Author: Hu Pengxiang
    > Mail: hpxiangsky@gmail.com 
    > Created Time: Sat 13 Apr 2013 09:21:52 AM CST
 ************************************************************************/

#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	//open file
	int caseNum;
	char inFileName[10] = "small.in";
	//cout << "input file name" << endl;
	//cin >> inFileName;
	ifstream f1;
	f1.open(inFileName, ios::in);	
	char outFileName[10] = "small.out";
	//cout << "output file name" << endl;
	//cin >> outFileName;
	ofstream f2;
	f2.open(outFileName, ios::out);
	f1 >> caseNum;

	int number[5] = {1, 4, 9, 121, 484};

	int A, B;
	for(int c = 0;c < caseNum;++c)
	{
		f1 >> A;
		f1 >> B;
		int b = 5, e = -1;
		for(int i = 0;i < 5;++i)
		{
			if(A <= number[i])
			{
				b = i;
				break;
			}
		}

		for(int i = 4;i >= 0 ;--i)
		{
			if(B >= number[i])
			{
				e = i;
				break;
			}
		}
		if(e < b)
			f2 << "Case #" << c+1 << ": " << 0 << endl;
		else
			f2 << "Case #" << c+1 << ": " << e - b + 1 << endl;
	}

	return 0;
}
