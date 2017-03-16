/*************************************************************************
    > File Name: fairSquare_large.cpp
    > Author: Hu Pengxiang
    > Mail: hpxiangsky@gmail.com 
    > Created Time: Sat 13 Apr 2013 05:17:43 PM CST
 ************************************************************************/
#define TEST 0 
#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>
#include "number.cpp"
using namespace std;

const vector<number> buildDatabase(int MaxLen)
{
	//an fair square number's length is odd
	//range of root of a fair square: 1~3.4 * 10^x
	
	//get the fair square number from 1 to 10^14
	//and save
	MaxLen = (MaxLen-1) / 2;
	vector<number> data;
	for(int len = 0;len <= MaxLen;++len)
	{
		number begin((int)(1 * pow(10, len)));
		number end((int)(3.4 * pow(10, len)));
		if(TEST)
		{
			cout << "loop " << len << endl;
			cout << "begin " << begin << endl;
			cout << "end " << end << endl;
		}
		for(number i = begin;i <= end;++i)
		{
			if(i.isPalindrome())
			{
				number tmp = i * i;
				if(tmp.isPalindrome())
				{
					data.push_back(tmp);
					cout << tmp << endl;
				}
			}
		}
	}
	return data;
}

int main()
{
	vector<number> data = buildDatabase(14);

	int caseNum;
	char inFileName[10] = "small.in";
	ifstream f1;
	f1.open(inFileName, ios::in);	
	char outFileName[10] = "small.out";
	ofstream f2;
	f2.open(outFileName, ios::out);
	f1 >> caseNum;

	number A, B;
	for(int c = 0;c < caseNum;++c)
	{
		f1 >> A;
		f1 >> B;
		if(TEST)
		{
			cout << A << endl;;
			cout << B << endl;;
		}
		int b, e;
		for(unsigned int i = 0;i < data.size();++i)
		{
			if(A <= data[i])
			{
				b = i;
				break;
			}
		}

		for(unsigned int i = data.size()-1;i >= 0 ;--i)
		{
			if(B >= data[i])
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
