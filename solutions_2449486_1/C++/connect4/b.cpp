#include <string.h>       
#include <vector>       
#include <set>       
#include <map>       
#include <algorithm>       
#include <math.h>       
#include <sstream>       
#include <ctype.h>       
#include <queue>       
#include <stack>       
#include <iostream> 
#include <gmp.h>	// if GMP is not allowed, I apologize
#include <fstream>
using namespace std;


int main(int argc, char** argv)
{
string fName = argv[1];

fstream In((fName+".in").c_str(), ios::in);
fstream Out((fName + ".out").c_str(), ios::out);

int tests;

In >> tests;

int N, M;

for(int h=0; h<tests; h++)
{
	In >> N >> M;
	vector<vector <int> > board(N, vector<int>(M, 100) );

	for(int i=0; i<N; i++) for(int j=0; j<M; j++)
		In >> board[i][j];

	int flag = true;

	for(int z=1; z<=100; z++)
	{
		for(int i=0; i<N; i++)
		{
			int j;
			for(j=0; j<M; j++)
				if(board[i][j] && board[i][j]!=z)
					break;
			if(j==M)
			for(j=0; j<M; j++)
				board[i][j] = 0;
		}
		for(int j=0; j<M; j++)
		{
			int i;
			for(i=0; i<N; i++)
				if(board[i][j] && board[i][j]!=z)
					break;
			if(i==N)
			for(i=0; i<N; i++)
				board[i][j] = 0;
		}
	}
	string s = "YES";
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			if(board[i][j])
				s = "NO";

	
	Out << "Case #" << h+1 << ": " << s << endl;

}

In.close();

Out.close();

return 0;

}
 
