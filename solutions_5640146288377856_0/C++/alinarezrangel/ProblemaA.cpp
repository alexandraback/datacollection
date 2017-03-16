/*
Programa creado por Alejandro Linarez Rangel.
Para la Google Code Jam
Problema B a resolver.
En ISO C++11.
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <functional>
#include <utility>
#include <complex>
#include <bitset>
#include <fstream>
#include <sstream>
#include <tuple>
#include <regex>

using namespace std;

typedef unsigned long long int uent;
typedef long long int ent;

int main (int argc, const char* argv[])
{
	int T = 0;
	cin >> T;
	for(int cuenta = 1;cuenta <= T;cuenta++)
	{
		cout << "Case #" << cuenta << ": ";
		int R = 0,C = 0, W = 0, Res = 0;
		cin >> R >> C >> W;
		ent porColumnasAnteriores = floor(static_cast<long double>(C) / static_cast<long double>(W));
		Res = porColumnasAnteriores * R;
		if(static_cast<long double>(porColumnasAnteriores) != (static_cast<long double>(C) / static_cast<long double>(W)))
		{
			// Es inexacto
			Res += W;
		}
		else
		{
			Res += W - 1;
		}
		cout << Res << endl;
	}
	return 0;
}
