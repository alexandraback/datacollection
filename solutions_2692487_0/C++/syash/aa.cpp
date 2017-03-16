#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

void main() {



	ifstream in;
	ofstream out;
	out.open("out.txt");
	in.open("input.txt");
	int min;
	int c,d,n,swap;
	int  mots[100];
	int need[100];
	int left,next;
	int T;
	int j;
	int me, N;
	in >> T;
	for (int i=0;i<T; i++)
	{
		in >> me >> N;

		for (j=0; j<N; j++)
		{
			in >> mots[j];
		}

		//sort

		for (c = 0 ; c < ( N - 1 ); c++)
		{
			for (d = 0 ; d < N - c - 1; d++)
			{
				if (mots[d] > mots[d+1]) /* For decreasing order use < */
				{
					swap       = mots[d];
					mots[d]   = mots[d+1];
					mots[d+1] = swap;
				}
			}
		}


		left = N;
		next = 0;
		for (j=0; j<N; j++)
		{
			need[j] = 0;
		}
		next=0;
		j=0;
		while (next<N)
		{
			if (mots[next] < me)
			{
				me +=mots[next];
				next++;
				need[next] = need[next-1];
			}
			else
			{
				need[next] ++;
				me +=(me-1);
				if (need[next]==N)
					break;
			}

		}
		min=N;
		for (j=0;j<next;j++)
		{
			if (need[j]+N-j-1 < min)
			{
				min = need[j]+N-j-1;
			}
		}
		out << "Case #" << i+1 << ": " << min << endl;

	}


	in.close();
	out.close();
	system("pause");

}
