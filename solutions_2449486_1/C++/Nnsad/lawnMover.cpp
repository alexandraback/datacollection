/*************************************************************************
    > File Name: Tic.cpp
    > Author: Hu Pengxiang
    > Mail: hpxiangsky@gmail.com 
    > Created Time: Sat 13 Apr 2013 07:07:03 AM CST
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


#define X 0
#define O 1
#define point 2
#define T 3

int max(int *A, int size, int cnt)
{
	int m = 0;
	int tmp;
	for(int i = 0;i < cnt;++i)
	{
		tmp = *(A + i * size);
		if(tmp > m)
		{
			m = tmp;
		}
	}
	return m;
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

	int M, N;
	for(int c = 0;c < caseNum;++c)
	{
		//read data
		f1 >> M;
		f1 >> N;
		int A[M][N];
		for(int j = 0;j < M;++j)
		{
			for(int k = 0;k < N;++k)
			{
				f1 >> A[j][k];
			}
		}

		//display
		for(int j = 0;j < M;++j)
		{
			for(int k = 0;k < N;++k)
			{
				cout <<  A[j][k];
			}
			cout << endl;
		}

		//judge if a row or col is the same
		/*
		bool rowSame[M], colSame[N];
		for(int i = 0;i < M;++i)
		{
			rowSame[i] = true;
			for(int j = 1;j < N;++j)
			{
				if(A[i][j] != A[i][j-1])
				{
					rowSame[i] = false;
					break;
				}
			}
		}
		for(int j = 0;j < N;++j)
		{
			colSame[j] = true;
			for(int i = 1;i < M;++i)
			{
				if(A[i][j] != A[i-1][j])
				{
					colSame[j] = false;
					break;
				}
			}
		}
		*/

		//get the maximum of an array
		int rowMax[M], colMax[N], tMax;
		for(int i = 0;i < M;++i)
		{
			rowMax[i] = max(&A[i][0], 1, N);
		}
		for(int i = 0;i < N;++i)
		{
			colMax[i] = max(&A[0][i], N, M);
		}
		tMax = max(rowMax, 1, M);
		int tMax2;
		tMax2 =  max(colMax, 1, N);
		if(tMax < tMax2)
		{
			tMax = tMax2;
		}
		cout << endl << "row max" << endl;
		for(int i = 0;i < M;++i)
		{
			cout << rowMax[i] << " ";
		}
		cout << endl << "col max" << endl;
		for(int i = 0;i < N;++i)
		{
			cout << colMax[i] << " ";
		}
		cout << endl << "tMax " << tMax << endl;

		//judge possibility
		bool isPos;
		for(int i = 0;i < M;++i)
		{
			for(int j = 0;j < N;++j)
			{
				isPos = false;
				if(A[i][j] == tMax)
					isPos = true;
				if(A[i][j] >= rowMax[i])
					isPos = true;
				if(A[i][j] >= colMax[j])
					isPos = true;
				if(isPos == false)
					break;
			}
			if(isPos == false)
				break;
		}

		if(isPos)
		{
			f2 << "Case #" << c+1 << ": YES" << endl;
		}
		else
		{
			f2 << "Case #" << c+1 << ": NO" << endl;
		}
	}
}

