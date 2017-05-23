#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstdio>
#include "bigint.h"
#include <cstring>

using namespace std;

int E, R, N;
int v[10];
int ans;

void DFS(int depth, int cur, int value)
{
	if (depth == N)
	{
		if (ans < value) ans = value;
		return;
	}
	
	for (int i = 0 ; i <= cur ; i++)
		DFS(depth+1, min(cur-i+R, E), value+i*v[depth]);
}

int main()
{
   ifstream fin("B-small-attempt0.in");
  ofstream fout("B-small-attempt0.out");
//    ifstream fin("B-large.in");
//    ofstream fout("B-large.out");

    int T;
    
    fin >> T;
    
    for (int t = 1 ; t <= T; t++)
    {  
		fin >> E >> R >> N;
		for (int i = 0 ; i < N ; i++)
			fin >> v[i];
		
		ans = 0;		
		DFS(0, E, 0);
		
		fout << "Case #" << t << ": ";
        fout << ans << endl;
    }
}
