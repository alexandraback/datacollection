#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

enum quaternion {ONE = 1, I = 2, J = 3, K = 4, MINUS_ONE = -1, MINUS_I = -2, MINUS_J = -3, MINUS_K = -4};

int multiplicationTable[] = {1, 2, 3, 4, 2, -1, 4, -3, 3, -4, -1, 2, 4, 3, -2, -1};

quaternion multiply(quaternion a, quaternion b)
{
	int x = static_cast<int>(a);
	int y = static_cast<int>(b);	
	int xy = multiplicationTable[abs(x) * 4 + abs(y) - 5] * ((x>0 ^ y>0)?-1:1);
	return static_cast<quaternion>(xy);
}

quaternion power(quaternion a, long exponent)
{
	switch(a)
	{
		case ONE: return ONE;
		case MINUS_ONE: return (a%2==0?ONE:MINUS_ONE);
		
		default:
		switch(exponent % 4)
		{
			case 0: return ONE;
			case 1: return a;
			case 2: return MINUS_ONE;
			case 3: return static_cast<quaternion>(-static_cast<int>(a));
		}
	}
}

int main()
{ 
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int numCases;
	fin >> numCases;
	
	for (int caseNumber=1; caseNumber<=numCases; caseNumber++)
	{
		fout << "Case #" << caseNumber << ": ";
		cout << "Case #" << caseNumber << ": " << endl;
		
		long L, X;
		fin >> L >> X;
		
		// read input
		quaternion input[10000];
		char c;
		for (long i=0; i<L; i++)
		{
			fin >> c;
			switch(c)
			{
				case 'i': input[i] = I; break;
				case 'j': input[i] = J; break;
				case 'k': input[i] = K; break;
			}
		}
		
		// step 1: multiply all and check
		quaternion product = ONE;
		for (long i=0; i<L; i++)
			product = multiply(product, input[i]);
		product = power(product, X);
		
		if (product != MINUS_ONE)
		{
			fout << "NO" << endl;
			continue;
		}
		
		// step 2: scan right and left		
		int loop;
		long leftOptimal = X*L;
		long rightOptimal = X*L;
		
		product = ONE;
		loop = 0;
		while(loop < 4 && loop < X)
		{
			for (long i=0; i<L; i++)
			{
				product = multiply(product, input[i]);
				if (product == I)
				{
					leftOptimal = i + 1 + loop * L;
					goto leftDone;
				}
			}
			loop++;
		}
		leftDone:
		
		product = ONE;
		loop = 0;
		while(loop < 4 && loop < X)
		{
			for (long i=L-1; i>=0; i--)
			{
				product = multiply(input[i], product);
				if (product == K)
				{
					rightOptimal = loop * L + L - i;
					goto rightDone;
				}
			}
			loop++;
		}
		rightDone:
		
		fout << ((leftOptimal + rightOptimal < X*L)?"YES":"NO") << endl;
	}
 
    return 0;
}