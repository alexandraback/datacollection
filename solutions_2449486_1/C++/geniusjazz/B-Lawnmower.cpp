#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
 //   ifstream fin("B-small-attempt0.in");
 //   ofstream fout("B-small-attempt0.out");
    ifstream fin("B-large.in");
    ofstream fout("B-large.out");    
    int T, N, M;
    fin >> T;
    
    int grass[101][101];
    for (int t = 1 ; t <= T; t++)
    {  
       
		fin >> N >> M;
		for (int i = 0 ; i < N ; i++)
		    for (int j = 0 ; j < M ; j++)
		        fin >> grass[i][j];
        
        int rowMax[101] = {0};
        int colMax[101] = {0};
        for (int i = 0 ; i < N ; i++)
            for (int j = 0 ; j < M ; j++)
            {
                if (rowMax[i] < grass[i][j])
                   rowMax[i] = grass[i][j];
                if (colMax[j] < grass[i][j])
                   colMax[j] = grass[i][j];
            }
                
        bool answer = true; 
        for (int i = 0 ; i < N ; i++)
        {
            for (int j = 0 ; j < M ; j++)
                if (grass[i][j] < rowMax[i] && grass[i][j] < colMax[j])
                   {answer = false; break;}
            if (answer == false) break;
        }
		
		fout << "Case #" << t << ": ";
		if (answer) fout << "YES" << endl;
		else fout << "NO" << endl;
    }
}
