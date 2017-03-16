#include <stdio.h>
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int cases;
	cin >> cases;
	cout.precision(15);

	for(int i = 0; i < cases; i++)
	{
		int typed; int passlen;
		cin >> typed;
		cin >> passlen;
//cout << passlen << endl;

		double prob[typed];
		double cprob[typed+1];
		cprob[0] = 1;
		double pac = 1;
		for(int j = 0; j < typed; j++)
		{
			cin >> prob[j];
			pac *= prob[j];
			cprob[j+1] = cprob[j] * prob[j]; 
//cout << prob[j] << endl;
		}

		double pressenter = passlen+2;
		double keeptype = (pac*(passlen-typed+1)) + ((double)(1-pac)*((passlen-typed)+passlen+2)); 
		//cout << keeptype << endl;

		double minbs = 1000000000;
		for(int k = 0; k < typed; k++)
		{
			double currbs = ( cprob[k]*((typed - k) + 1 + (passlen-k)) ) + 
			( (double)(1-cprob[k])* ( (typed - k) + 1 + (passlen-k) + passlen + 1 ) ); 
			
			if(currbs < minbs) { minbs = currbs; }
		}

		if(keeptype < pressenter){ pressenter = keeptype; }
		if(pressenter < minbs){ minbs = pressenter; }
		cout << "Case #" << (i+1) << ": " << minbs << endl;
	}

}
