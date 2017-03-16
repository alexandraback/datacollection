#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <list>
#include <set>
#include <queue>

using namespace std;

typedef long long int LL;
typedef pair<int,int> pii;

#define F first
#define S second
#define pb push_back
#define mp make_pair

int p[100];
int r[3];
int R, n, m, k;

bool test(int m1, int m2, int m3)
{
	int P = 1;
	for(int i = 0; i < 3; ++i)
		if(m1&(1<<i)) P *= r[i];
	if(P != p[0]) return false;

	P = 1;
	for(int i = 0; i < 3; ++i)
		if(m2&(1<<i)) P *= r[i];
	if(P != p[1]) return false;

	P = 1;
	for(int i = 0; i < 3; ++i)
		if(m3&(1<<i)) P *= r[i];
	if(P != p[2]) return false;

	return true;
}

int main (void)
{
	int T;
	cin >> T;

	

	cin >> R >> n >> m >> k;

	srand( time(0) );

	printf("Case #1:\n");
	for(int i = 0; i < R; ++i)
	{
		for(int i = 0; i < k; ++i) cin >> p[i];

		int ok = 0;
		for(r[0] = 2; !ok && r[0] <= m; ++r[0])
			for(r[1] = 2; !ok && r[1] <= m; ++r[1])
				for(r[2] = 2; !ok && r[2] <= m; ++r[2])
					for(int m1 = 0; m1 < 3; ++m1)
						for(int m2 = 0; m2 < 3; ++m2)
							for(int m3 = 0; m3 < 3; ++m3)
								if( test(m1, m2, m3) ) printf("%d%d%d\n", r[0], r[1], r[3]), ok = 1;
		
		if(!ok)
		{	
			int x1 = 2 + rand()%(m-1);
			sleep(0.5);
			int x2 = 2 + rand()%(m-1);
			sleep(0.5);
			int x3 = 2 + rand()%(m-1);
			if(!ok) printf("%d%d%d\n", x1, x2, x3);
		}
		
	}	
	return 0;
}
