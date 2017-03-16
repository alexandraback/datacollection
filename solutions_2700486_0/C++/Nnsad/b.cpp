#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <math.h>
#define abs(x) x < 0? -x:x
using namespace std;

int factorial(int n)
{
	if(n != 0)
		return n * factorial(n-1);
	else
		return 1;
}

double C(int l, int h)
{
		double P = (double)(factorial(l)) / (double)(factorial(h)) / (double)(factorial(l-h)) ;
		return P;
}

double getPro(int l, int h, int maxH)
{
	double P;
	if(l - h > maxH || l - h < 0)
		return 0;
	if(l - h < maxH && h < maxH)
		P = C(l, h) / (double)(pow(2, l));
	else
	{
		P = 0;
		for(int i = maxH;i <=l; ++i)
			P += C(i, maxH) / pow(2, maxH);
		P /= 2;
	}

	return P;
}

int main()
{
	//open file
	char inFileName[10] = "small.in";
	char outFileName[10] = "small.out";
	ifstream f1;
	f1.open(inFileName, ios::in);	
	ofstream f2;
	f2.open(outFileName, ios::out);

	//process
	int T;
	int k, S1, S2;
	f1 >> T;
	for(int c = 0;c < T;++c)
	{
		//read data
		int N;
		f1 >> N;
		int X, Y;
		f1 >> X;
		f1 >> Y;
		double P;

		//process
		X = X > 0 ? X : -X;
		Y = Y > 0 ? Y : -Y;
		k = (X+Y)/2;
		S2 = 2 * k * k + 3 * k + 1;
		S1 = 2 * (k - 1) * (k - 1) + 3 * (k - 1) + 1;
		if(N >= S2)
			P = 1.0;
		else
			if(N <= S1)
				P = 0.0;
			else
			{
				int maxH = (S2 - S1 - 1) / 2; 
				int h = abs(Y) + 1;
				int l = N - S1;
				if(h == maxH + 1 || h > l)
					P = 0.0;
				else
				{
					P = 0.0;
					for(int jj = h;jj <= maxH;++jj)
					{
						P += getPro(l, jj, maxH);
					}
				}
			}


		f2 << "Case #" << c+1 << ": " << setprecision(6) << P << endl;
    }
	f1.close();
	f2.close();
    return 0;

}
