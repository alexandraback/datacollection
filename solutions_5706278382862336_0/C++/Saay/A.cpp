#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;

typedef long long int grand;

int smallest(grand P)
{
	int res = 0;
	grand a = 1;
	while (a <= P)
	{
		a = 2*a;
		res++;
	}
	return res;
}

int main (int argc, char* argv[])
{
	int T;
	cin >> T;
	grand P,Q;
	for (int cas = 0; cas < T; cas += 1)
	{
		cout << "Case #" << cas +1 << ": ";
		cin >> P >> Q;
		int p=0;
		int q=0;	
		while (P%2==0)
		{
			P = P/2;
			p++;
		}
		while (Q%2==0)
		{
			Q = Q/2;
			q++;
		}
		if (P%Q != 0 or q-p > 40)
		{
			cout << "impossible" << endl;
			continue;
		}
		P = P/Q;
		int sol = -(smallest(P) +p-q-1);
		cout << sol << endl;
	}
	return 0;
}
