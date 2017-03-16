#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <set>
#include <sstream>
#include <cmath>

using namespace std;

typedef long long ll;

//*
ifstream fin("A-small-attempt1.in");
#define cin fin
//ofstream fout("A-small-attempt1.out");
FILE *fout;
#define cout fout
//*/

const int maxn = 100005;
double p[maxn];
double correct[maxn];

int main()
{
	int tc;
	cin>>tc;
	fout = fopen("A-small-attempt1.out", "w");
	for(int t=1; t<=tc; t++)
	{
		int typed, total;
		cin>> typed >> total;
		for(int i=0; i<typed; i++)
			cin>>p[i];

		double bestE = 1000000000.0;
		int rest = total - typed;

		correct[0] = 1;
		for(int i=1; i<=typed; i++)
			correct[i] = correct[i-1]*p[i-1];
		
		for(int backspaces=0; backspaces<=typed; backspaces++)
		{
			double E = correct[typed - backspaces]*(backspaces + rest+backspaces + 1) + (1.0-correct[typed-backspaces])*(backspaces + rest+backspaces + 1 + total + 1) ;
			if(bestE > E)
				bestE = E;
		}
		
		if(bestE > 1.+total+1.)
			bestE = 1.+total+1.;
		
		fprintf(fout, "Case #%d: %.6f\n", t, bestE);
		//cout<<"Case #"<< t<<": "<<bestE <<endl;
	}

	return 0;
}
