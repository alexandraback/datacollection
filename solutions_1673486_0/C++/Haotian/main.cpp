#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
int A, B;
double streetFinish(double p, double a)
{

    return (double)  ( (double)(p * (1+B-a)) + (1-p) * (double) (2+2 *B -a ));
	//return  (double)(2*B+2-A-  (p * (1+B)));
}

double min(double a, double b, double c)
{
	double tmp = a<b? a:b;
	return tmp<c? tmp:c;
}
double min(double a, double b)
{
	return a<b?a:b;	
}

int main()
{
	ifstream fin("A-small-attempt1.in");
	//ifstream fin("A-small.in");
    //ifstream fin("A-large.in");
    ofstream fout("A-small-attempt1.out");
	//ofstream fout("A-small.out");
    //ofstream fout("A-large.out");
	int T;
	double p[100000];
	fin>>T;
	for(int t = 1; t<=T; t++)
	{
		fin >> A;
		fin >> B;
		double totalRight = 1;
	    double oldBest = -1, currentBest = 0;
        for(int a = 1; a <= A; a++)
		{
			fin >> p[a];
			totalRight *= p[a];
			if(oldBest  == -1)
			{
				currentBest= min(streetFinish(totalRight, a), 2+B);
				oldBest = currentBest;
			}
			else
			{
				currentBest = min(streetFinish(totalRight, a), 1+oldBest);
				oldBest = currentBest;
			}
			cout << "current at " << a << ":"  << currentBest << std::endl;
		}
		currentBest = min(currentBest, 2+B);
		fout.precision(7);
		fout << "Case #" << t << ": " << currentBest <<endl;
	}
	while(1) {}
	return 0;
}