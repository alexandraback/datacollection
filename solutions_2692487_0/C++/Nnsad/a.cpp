#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
using namespace std;

int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;	
}
int getStep(int *b, int n, int a)
{
	    
	if(n == 0)
		return 0;
    else
    {
		if(a == 1)
			return n;
		else
        {
			int step;
			int a2;
			if(*b < a)
			{
				a2 = a + *b;
				return getStep(b+1,n-1,a2);
			}
			else
			{
				double tmp = log10((*b - 1) / (a - 1)) / log10(2);
				step = (int)tmp;
				if((double)step <= tmp)
					step++;
		        int tStep1 = n;
		        a2 = pow(2, step)*(a - 1) + 1;
				a2 += *b;
		        int tStep2 = step + getStep(b+1, n-1, a2); 
                if(tStep1 > tStep2)
			        return tStep2;
		        else
			        return tStep1;
			}
        }
    }
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
	f1 >> T;
	for(int c = 0;c < T;++c)
	{
		//read data
		int A;
		int N;
		f1 >> A;
		f1 >> N;
		int B[N];
		for(int j = 0;j < N;++j)
		{
			f1 >> B[j];
		}
		qsort(B, N, sizeof(int), cmp);
		for(int j = 0;j < N;++j)
		{
			cout << B[j] << " ";
		}
		cout << endl;

		int n = getStep(B, N, A);
		f2 << "Case #" << c+1 << ": " << n << endl;
    }
	f1.close();
	f2.close();
    return 0;

}
