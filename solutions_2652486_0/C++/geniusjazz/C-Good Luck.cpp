#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
   ifstream fin("C-small-1-attempt1.in");
   ofstream fout("C-small-1-attempt1.out");

    int T, R;
    int N, M, K;
    
    fin >> T >> R >> N >> M >> K;
    fout << "Case #" << T << ": " << endl;
    
    int prod[8];
    int ans[3];
    
    bool prod_exist[64][126];
    
    for (int i = 2 ; i <= 5 ; i++)
    	for (int j = 2 ; j <= 5 ; j++)
    		for (int k = 2 ; k <= 5 ; k++)
    		{
    			int idx = (i-2)*16 + (j-2)*4 + (k-2);
    			prod_exist[idx][1] = true;
    			
    			prod_exist[idx][i] = true;
    			prod_exist[idx][j] = true;
    			prod_exist[idx][k] = true;
    			    			    			    			
    			prod_exist[idx][i*j] = true;
    			prod_exist[idx][i*k] = true;
    			prod_exist[idx][j*k] = true;
    			
    			prod_exist[idx][i*j*k] = true;    			    			    			    			
    		}
    
    int sum[126];
    for (int i = 0 ; i <= 125 ; i++)
    	for (int j = 0 ; j < 64 ; j++)
	    	if (prod_exist[j][i]) sum[i]++;
    
    for (int r = 1 ; r <= R; r++)
    {  
    	for (int k = 0 ; k < K ; k++)
			fin >> prod[k];
						
		double max_like = 0;
		int ans = 0;
		
		for (int j = 0 ; j < 64 ; j++)
		{
			double like = 0;
			for (int k = 0 ; k < K ; k++)
				if (prod_exist[j][prod[k]]) 
					like += 1.0/(double)sum[prod[k]];
			
			if (max_like < like)
			{
				max_like = like;
				ans = j;
			}
		}
		
	    fout << ans/16 +2  << (ans%16)/4+2 << (ans%4)+2;
	    fout << endl;
    }
}
