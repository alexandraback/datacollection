#include "bits/stdc++.h"
using namespace std;

string isPossible(int a, long long b)
{
	int sum = 1;
	if(a > 2)
		sum = 2<<(a-3);

	if( b > sum )
		return "IMPOSSIBLE";
	else
		return "POSSIBLE";
}
void find(int mat[][50], int B, int M)
{
	/*
	for(int i=0; i<B; i++)
	{
		if(M <= 0)
			break;
		mat[i][B-1] = 1;
		if(i!=0)
			mat[0][i] = 1;
		M--;
	}
	for(int i=0; i<B; i++)
	{
		if(M <= 0)
			break;
		mat[i][B-2] = 1;
		M--;
	}

	for(int i=0; i<B; i++)
	{
		if(M <= 0)
			break;
	}
	for(int i=0; i<B; i++)
	{
		for(int j=0; j<i; j++)
			mat[j][i] = 1;
	}
	int sum = 1;
	sum = 2<<(a-2);

	for(int i=0; i<B; i++)
	{
		mat[0][i] = 0;
		sum--;
		if(sum == M)
			break;
	}
	*/
	long long M_p = M;
	if(M  > 0)
	{
		for(int i=0; i<B-1; i++)
		{
			if(i!=0)
				mat[0][i] = 1;
			mat[i][B-1] = 1;
			M--;
			if(M <= 0)
				break;
		}
	}
	if( M > 0)
	{
		if( B == 4)
			mat[1][2] = 1;
		else if (B == 5)
		{
			switch(M)
			{
				case 1:
					mat[2][3] = 1;
					break;
				case 2:
					mat[2][3] = 1;
					mat[1][3] = 1;
					break;
				case 4:
					mat[2][3] = 1;
					mat[1][3] = 1;
					mat[1][2] = 1;
					break;
				case 3:
					mat[0][4] = 0;
					mat[2][3] = 1;
					mat[1][3] = 1;
					mat[1][2] = 1;
					break;
			}
		}
		else
		{
			int i = 1;
			while( i < 4 && M > 0)
			{
				mat[i][4] = 1;
				i++;
				M--;
			}
			if( M > 0)
			{
				switch (M)
				{
					case 1:
						mat[2][3] = 1;
						mat[0][5] = 0;
						break;
					case 2:
						mat[2][3] = 1;
						break;
					case 3:
						mat[2][3] = 1;
						mat[1][3] = 1;
						mat[0][5] = 0;
						break;
					case 4:
						mat[2][3] = 1;
						mat[1][3] = 1;
						break;
					case 5:
						mat[2][3] = 1;
						mat[1][2] = 1;
						mat[0][5] = 0;
						break;
					case 6:
						mat[2][3] = 1;
						mat[1][2] = 1;
						break;
					case 7:
						mat[2][3] = 1;
						mat[1][2] = 1;
						mat[1][3] = 1;
						mat[0][5] = 0;
						break;
					case 8:
						mat[2][3] = 1;
						mat[1][2] = 1;
						mat[1][3] = 1;
						break;
				}
			}
		}
	}
}
int main()
{
	int t;
	int B;
	long long M;
	int mat[50][50];
	cin>>t;
	for (int i = 1; i <=t; ++i)
	{
		cin>>B>>M;
		string str = isPossible(B, M);
		cout<<"Case #"<<i<<": "<<str<<endl;
		if(str[0] == 'P')
		{
			for(int j=0; j<B; j++)
				for(int k=0; k<B; k++)
					mat[j][k] = 0;

			find(mat, B, M);
			for(int j=0; j<B; j++)
			{
				for(int k=0; k<B; k++)
					cout<<mat[j][k];	
				cout<<endl;
			}
		}
	}
}