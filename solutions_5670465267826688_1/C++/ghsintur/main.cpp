
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <limits>
#include <iomanip>
#define UINT64 unsigned __int64
using namespace std;
ifstream  fin("b.txt");
ofstream  fout("c.txt");

char pArray[10000];
char pArrayStart[10000];
char pArrayEnd[10000];
char pArrayExp[5];

char mult(char a, char b)
{
	char	sign = (a*b);
	char	res;

	sign	= (sign > 0) ? 1 : -1;
	a		= (a > 0) ? a : -a;
	b		= (b > 0) ? b : -b;

	do 
	{
		if (a == 1)
		{
			res = b;
			break;
		}
		if (b == 1)
		{
			res = a;
			break;
		}
		if (a == b)
		{
			res = -1;
			break;
		}
		switch (a)
		{
		case 2:
			if (b == 3)
			{
				res = 4;
			}
			else
			{
				res = -3;
			}
			break;
		case 3:
			if (b == 2)
			{
				res = -4;
			}
			else
			{
				res = 2;
			}
			break;
		case 4:
			if (b == 2)
			{
				res = 3;
			}
			else
			{
				res = -2;
			}
			break;
		default:
			while (1)
			{

			}
			break;
		}
	} while (0);
	
	return res*sign;
}
// 
// void solvel(unsigned int l, unsigned int x)
// {
// 	unsigned int	i;
// 	unsigned int	j;
// 	unsigned int	split;
// 	unsigned int	temp;
// 	unsigned int	res =1001;
// 	unsigned int	s1;
// 	unsigned int	s2;
// 	unsigned int	s3;
// 
// 	unsigned int	s1Index;
// 	unsigned int	s2Index;
// 	unsigned int	s3Index;
// 
// 	res				temp1;
// 	res				temp2;
// 	res				temp3;
// 
// 	pArrayStart[0]		= pArray[0];
// 	pArrayEnd[l-1]		= pArray[l-1];
// 
// 	for (i=1; i<l; i++)
// 	{
// 		pArrayStart[i]		= mult(pArrayStart[i-1], pArray[i]);
// 		pArrayEnd[l-i-1]	= mult(pArray[l-i-1], pArrayEnd[l-i]);
// 	}
// 
// 	pArrayExp[0] = 1;
// 	for (i = 1; i < 5; i++)
// 	{
// 		pArrayExp[i] = mult(pArrayExp[i-1], pArrayEnd[0]);
// 	}
// 
// 	//[c0,...cl-1]^s1*[c0,..ci] |				[ci+1,...cl-1]*[c0,...cl-1]^s2*[c0,..cj]					|[cj+1,...cl-1]*[c0,...cl-1]^s3
// 
// 	for (s1Index = 0; s1Index < 5; s1Index++)
// 	{
// 		for (s2Index = 0; s2Index < 5; s2Index++)
// 		{
// 			for (s3Index = 0; s3Index < 5; s3Index++)
// 			{
// 				//is valid solution ?
// 				for ( i = 0; i < l; i++)
// 				{
// 					//is valid solution ?
// 					for ( j = 0; j < l; j++)
// 					{
// 						//is valid solution 
// 
// 						//
// 					}
// 				}
// 			}
// 		}
// 	}
// 
// 	fout << res << endl;
// 
// }

void solve(unsigned long long l, unsigned long long x)
{
	int	i;
	int	j;
	char			temp0 =1;
	char			temp1 =1;
	char			res;
	unsigned long long orgX;
	long long indexI = -1;
	long long indexK = -1;
	unsigned int rounds = ((x >= 4) ? 4 : x);

	for (i=0; i<l; i++)
	{
		temp0 = mult(temp0, pArray[i]);
	}



	//in this point temp is only l not l^x
	orgX =x;
	x = x%4;
	switch (x)
	{
	case 0:
		temp0 = 1;
		break;
	case 1:
		break;
	case 2:
		temp0 =  mult(temp0, temp0);
		break;
	case 3:
		temp0 =  mult(temp0,  mult(temp0, temp0));
	break;
	default:
		while (true)
		{

		}
	}

	res = mult(2, temp0);
	res = mult(res, 4);

	if (res == 3)
	{
		temp1 =1;
		for (j=0; j<rounds; j++)
		{
			for (i=0; i<l; i++)
			{
				temp1 = mult(temp1, pArray[i]);
				if ((temp1 == 2 )&& (indexI == -1))
				{
					indexI = i+j*l;
					break;
				}
				if (indexI != -1)
				{
					break;
				}
			}
		}

		temp1 =1;
		for (j=0; j<rounds; j++)
		{
			for (i=l-1; i>=0; i--)
			{
				temp1 = mult(pArray[i], temp1);
				if ((temp1 == 4 )&& (indexK == -1))
				{
					indexK = (l*orgX)-(((l-1)-i)+(j*l));
					break;
				}
			}
			if (indexK != -1)
			{
				break;
			}
			

		}
	}


	if ((l*orgX)<3)
	{
		fout << "NO" << endl;
	}
	else if (((indexI <0)||(indexK <0)||(indexI >=indexK))&&(res == 3))
	{
		/*fout <<indexI<<" "<<indexK<<" ";*/
		fout << "NO" << endl;
	}
	else if (res == 3)
	{
		//fout <<"x:"<<orgX<<" l:"<<l<<" "<<indexI<<" "<<indexK<<" ";
		fout << "YES" << endl;
	}
	else
	{
		fout << "NO" << endl;
	}

	
}

int main(void)
{
	unsigned int numOfTests;
	unsigned int i;
	unsigned int j;
	unsigned long long x;
	unsigned long long l;

	fin >> numOfTests;

	for (i = 0; i<numOfTests; i++)
	{
		fin >> l>>x;
		for (j = 0; j < l; j++)
		{
			fin >> pArray[j];
			switch (pArray[j])
			{
			case 'i':
				pArray[j] = 2;
				break;
			case 'j':
				pArray[j] = 3;
				break;
			case 'k':
				pArray[j] = 4;
				break;
			}		
		}

		fout << "Case #"<<i+1<<": ";
		solve(l, x);
	}
}
