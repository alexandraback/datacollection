#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXB = 50;

int B;
long long M;

void init()
{
	cin >> B >> M;
}


int gmap[MAXB][MAXB];

void solve(int caseNum)
{
	cout << "Case #" << caseNum+1 << ": ";
	
	if(M > (1LL<<(B-2))) { cout << "IMPOSSIBLE\n"; return; }
	cout << "POSSIBLE\n";
	
	for(int i=0; i<B; i++) for(int j=0; j<B; j++) gmap[i][j] = false;
	
	for(int i=0; i<B-1; i++)
	{
		for(int j=i+1; j<B-1; j++) gmap[i][j] = true;
	}
	
	if((M&1) == 1)
	{
		gmap[0][B-1] = true;
		for(int i=2; i<B-1; i++) if((M&(1LL<<(i-1))) > 0) gmap[i][B-1] = true;
	} else {
		if(M == (1LL<<max(B-2, 0)))
		{
			for(int i=0; i<B-1; i++) gmap[i][B-1] = true;
		} else {
			for(int i=2; i<B-1; i++) if((M&(1LL<<(i-1))) > 0) gmap[i][B-1] = true;
		}
	}
	
	for(int i=0; i<B; i++)
	{
		for(int j=0; j<B; j++)
		{
			cout << gmap[i][j];
		}
		cout << "\n";
	}
}


int main()
{
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	
	int T;
	cin >> T;
	for(int i=0; i<T; i++)
	{
		init();
		solve(i);
	}
	
	return 0;
}
