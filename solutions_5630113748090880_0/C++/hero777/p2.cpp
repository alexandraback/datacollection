#include<iostream>
#include<cstdio>
#include<string>
#include<fstream>
#include <algorithm>


using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int main ()
{
	ifstream input;
	ofstream output;
	input.open("in.txt");
	output.open("out.txt");
	int test,tests;
	input >> tests;
	//printf("%d", tests);
	forn (test,tests)
	{	
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		int N;
		input >> N;
		printf("%d\n", N);
		int h[2500];
		forn (i, 2500)
			h[i] = 0;
		forn (i, (2*N-1)*N)
		{
		
			int k;
			input >> k;
			printf("%d\n",k);
			h[k-1] +=1;
			printf("\n");
		}
		printf("%d\n", h[13]);
		int o[N];
		forn(i, N)
			o[i] = 0;
		int pres = 0;
		forn (i, 2500)
		{
			if (h[i] %2 !=0)
			{
				printf("%d\n",i);
				o[pres] = i+1;
				pres++;
			}
		}
		sort(o,o+N);
		output << "Case #"<< test+1 << ": ";
		forn(i, N)
			output<< o[i] << " ";
		output << "\n";
	}
}
		
		
