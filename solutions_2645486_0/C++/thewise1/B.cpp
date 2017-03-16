/*
ID : thewise1
PROG: 
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bitset>

using namespace std;



int main()
{
	ofstream cout ("BS.out");
        ifstream cin ("B-small-attempt1.in");

	int T;
	cin >> T;
	
	for (int GCJ = 0; GCJ < T; GCJ++)
	{
		
	int E, R, N;
	cin >> E >> R >> N;
	int v[10];
	int o[10];
	
	int maxGain = 0;
	int Ec = E;

	for (int i = 0; i < 10; i++)
	{
		v[i] = 0;
		o[i] = 0;
	}

	for (int i = 0; i < N; i++)
		cin >> v[i];	

	while (true)
	{
		int gain = 0;
		for (int i = 0; i < N; i++)
		{
			if (o[i] != E)
			{
				o[i] = o[i] + 1;
				break;
			}
			else
				o[i] = 0;
		}

		Ec = E;
		bool works = true;
		for (int i = 0; i < N; i++)
		{
			Ec -= o[i];
			if (Ec < 0)
				works = false;
			Ec += R;
			Ec = min(Ec, E);
		}
		if (works)
		{
			for (int i = 0; i < N; i++)
			{
				gain += v[i]*o[i];
			}
			maxGain = max(maxGain, gain);
		}


		bool atMax = true;
		for (int i = 0; i < N; i++)
		{
			if (o[i] != E)
				atMax = false;
		}
		if (atMax)
			break;
	}
	cout << "Case #" << GCJ+1 << ": " << maxGain << endl;
	}

	return 0;	
}
