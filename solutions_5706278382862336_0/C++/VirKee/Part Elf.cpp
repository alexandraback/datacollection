//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <queue>
using namespace std;

void solve()
{
	int P,Q;
	char c;

	cin >> P >> c >> Q;

	if( (Q & Q-1) != 0 ) cout << "impossible" << endl;
	else
	{
		int generation = 0;
		for(int i = 1; i <= 40; ++i)
		{
			P *= 2;
			generation++;
			if( P >= Q ) break;
		}

		cout << generation << endl;
	}
}

int main(int argc, char* argv[])
{	
	FILE* fp;
	freopen_s(&fp, "A-small-attempt0.in", "r", stdin );
	freopen_s(&fp, "A-small-practice.out", "w", stdout );

	int n;

	cin >> n;
	
	for(int caseN = 1; caseN <= n; ++caseN)
	{
		printf_s("Case #%d: ", caseN);

		solve();
	}
}
