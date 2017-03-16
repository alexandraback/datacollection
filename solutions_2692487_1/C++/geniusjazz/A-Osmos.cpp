#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstdio>
#include "bigint.h"
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
//    ifstream fin("A-small-attempt2.in");
//    ofstream fout("A-small-attempt2.out");
    ifstream fin("A-large.in");
    ofstream fout("A-large.out");

    int T; fin >> T;
    int A, N;
	vector<int> M;
    
    for (int t = 1 ; t <= T; t++)
    {  
		fout << "Case #" << t << ": ";
		
		fin >> A >> N;
		M.clear();
		int temp;
		for (int i = 0 ; i < N ; i++)
		{
			fin >> temp;
			M.push_back(temp);
		}		
		sort(M.begin(), M.end());
		
		if (A == 1) {fout << N << endl; continue;}
		
		vector<int> ans;
		int total = 0;
		for (int i = 0 ; i < N ;i++)
		{
			if (A > M[i]) 
			{
				A += M[i]; 
				ans.push_back(0);
				continue;
			}
			else
			{
				int c = 0;
				while (A <= M[i])
				{
					A += (A-1);
					c++;
				}
				A += M[i];
				ans.push_back(c);
				total += c;
			}	
			
		}
		
		int final = 100;
		if (final > total) final = total;
		for (int i = N-1 ; i >= 0 ; i--)
		{	
            
			total -= ans[i]; total++;
			if (final > total)
				final = total;
		}		
		
        fout << final << endl;
    }
}
