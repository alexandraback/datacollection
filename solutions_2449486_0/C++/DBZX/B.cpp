// A.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <string>
#include <vector>
#include <cassert>
#include <map>
#include <set>
using namespace std;
#include "stdafx.h"
#include <fstream>
#include <vector>
using namespace std;
ifstream in("B-small-attempt0.in");
ofstream out("out.txt");
int game[200][200];
int N,M;

int gameMaxN[200];
int gameMaxM[200];
bool Solve()
{
	for(int n = 0;n<N;++n)
	{
		gameMaxN[n] = 0;
		for(int m = 0;m<M;++m)
			gameMaxN[n] = max(gameMaxN[n],game[n][m]);
	}
	for(int m = 0;m<M;++m)
	{
		gameMaxM[m] = 0;
		for(int n = 0;n<N;++n)
			gameMaxM[m] = max(gameMaxM[m],game[n][m]);
	}
	for(int n = 0;n<N;++n)
	{
		for(int m = 0;m<M;++m)
		{
			if(game[n][m] != gameMaxN[n] && game[n][m] != gameMaxM[m])
				return false;
		}
	}


	return true;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int T;
	in >> T;
	for(int i = 0;i<T;++i)
	{
		in >> N >> M;
		for(int n = 0;n<N;++n)
		{
			for(int m = 0;m<M;++m)
				in >> game[n][m];
		}
		out << "Case #" << (i+1) << ": " << (Solve()?"YES":"NO") << endl;
	}
	return 0;
}

