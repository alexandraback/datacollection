/*************************************************************************
    > File Name: Tic.cpp
    > Author: Hu Pengxiang
    > Mail: hpxiangsky@gmail.com 
    > Created Time: Sat 13 Apr 2013 07:07:03 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
using namespace std;


#define X 0
#define O 1
#define point 2
#define T 3

bool judge(char a, char b, char c, char d)
{
	if(a==b && b== c && c ==d)
		return true;
	if(a==b && b== c && d == 'T')
		return true;
	if(a==b && b== d && c == 'T')
		return true;
	if(a==b && b =='T' && c ==d)
		return true;
	if(a=='T' && b ==c && c ==d)
		return true;
	return false;
}

char getwinner(char a, char b)
{
	if(a == 'T')
		return b;
	else
		return a;
}

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

	char A[4][4];
	bool isFour, isLeft;
	char winner;
	for(int c = 0;c < caseNum;++c)
	{
		//read data
		for(int j = 0;j < 4;++j)
		{
			for(int k = 0;k < 4;++k)
			{
				f1 >> A[j][k];
			}
		}
		//display
		for(int j = 0;j < 4;++j)
		{
			for(int k = 0;k < 4;++k)
			{
				cout <<  A[j][k];
			}
			cout << endl;
		}

		//judge
		isFour = false;
		for(int i = 0;i < 4;++i)
		{
			if(judge(A[i][0], A[i][1], A[i][2], A[i][3]))
			{
				winner = getwinner(A[i][0], A[i][1]);
				if(winner == '.')
					isFour = false;
				else
				{
					isFour =true;
					break;
				}
			}
			if(judge(A[0][i], A[1][i], A[2][i], A[3][i]))
			{
				winner = getwinner(A[0][i], A[1][i]);
				if(winner == '.')
					isFour = false;
				else
				{
					isFour =true;
					break;
				}
			}
		}
		if(judge(A[0][0], A[1][1], A[2][2], A[3][3]))
		{
			winner = getwinner(A[0][0], A[1][0]);
			if(winner == '.')
				isFour = false;
			else
			{
				isFour =true;
			}
		}
		if(judge(A[0][3], A[1][2], A[2][1], A[3][0]))
		{
			winner = getwinner(A[0][3], A[1][2]);
			if(winner == '.')
				isFour = false;
			else
			{
				isFour =true;
			}
		}

		//is left
		isLeft = false;
		for(int i = 0;i < 4;++i)
		{
			for(int j = 0;j < 4;++j)
			{
				if(A[i][j] == '.')
				{
					isLeft = true;
					break;
				}
			}
		}

		if(isFour)
		{
			f2 << "Case #" << c+1 << ": " << winner << " won" << endl;
		}
		else
		{
			if(isLeft)
			{
				f2 << "Case #" << c+1 << ": "  "Game has not completed" << endl;
			}
			else
			{
				f2 << "Case #" << c+1 << ": "  "Draw" << endl;
			}
		}
	}
}

