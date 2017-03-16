#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <math.h>

using namespace std;


int main()
{
	ifstream myfile;
	//myfile.open("testC.in");
	myfile.open("C-small-attempt1.in");
	
	int T;
	myfile >> T;
	
	for (int t=0; t<T; t++)
	{
		int J, P, S, K;
		myfile >> J >> P >> S >> K;
		
		int comb[J*P*S][3];
		
		int c = 0;
		for (int j=0; j<J; j++)
			for (int p = 0; p<P; p++)
				for (int s=0; s<S; s++)
				{
					comb[c][0]=j+1;
					comb[c][1]=p+1;
					comb[c][2]=s+1;
					c++;
				}
				
		int val[J*P*S] = {0};
		int valid = 0;
	
		
        int jp[J+1][P+1] = {0};
		int js[J+1][S+1] = {0};
		int ps[P+1][S+1] = {0};
		
		for (c=0; c<J*P*S; c++)
		{
			if (jp[comb[c][0]][comb[c][1]] < K && js[comb[c][0]][comb[c][2]] < K && ps[comb[c][1]][comb[c][2]] <K)
			{
				jp[comb[c][0]][comb[c][1]]++;
				js[comb[c][0]][comb[c][2]]++;
				ps[comb[c][1]][comb[c][2]]++;
				valid++;
				val[c]++;
			}
		}
		
		cout << "Case #" << t+1 << ": " << valid << endl;
		
		for (c=0; c<J*P*S; c++)
		{
			if (val[c])
			cout << comb[c][0] << " " << comb[c][1] << " " << comb[c][2] << endl;
		}
		
	

	}
}
