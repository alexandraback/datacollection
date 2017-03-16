#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#pragma pack(1)
using namespace std;

double s[200];
double m[200];

int main()
{
	FILE *in = fopen("C:\\Users\\acer\\Desktop\\A-large.in", "r");
	FILE *out = fopen("C:\\Users\\acer\\Desktop\\A-small-attempt0.out", "w");
//	in = stdin;
//out = stdout;
	int T;
	fscanf(in, "%d", &T);
	int n;
	for (int k = 1; k <= T; k++)
	{
		fscanf(in, "%d", &n);
		
		int x = 0;
		
		for (int i = 0; i < n; i++)
		{
			fscanf(in, "%lf", &s[i]);
			x += s[i];
			m[i] = -1;
		}
		
		double mean =  2*x / n;
		int count = 0;
		while (true)
		{	
			count = 0;
			for (int i = 0; i < n; i++)
			{
				if (s[i] >= mean && m[i] != 0)
				{
					m[i] = 0;
					count++;
					cout << "AA" << endl;
				}
			}
			if (count == 0)
				break;
			
			mean = x;
			count = 0;
			for (int i = 0; i < n; i++)
				if (m[i])
				{
					mean += s[i];
					count ++;
				}
			mean /= count;
		}
		count = 0;
		mean = x;
		for(int i = 0; i < n; i++)
		{			
			if (m[i])
			{
				count++;
				mean += s[i];
			}
		}
		for(int i = 0; i < n; i++)
		{
			if (m[i])
				m[i] = (mean/(count) - s[i]) / x;
		}
		fprintf(out, "Case #%d: ", k);
		for (int i = 0; i < n; i++)
			fprintf(out, "%lf ", m[i]*100);
		fprintf(out, "\n");
	}
}
