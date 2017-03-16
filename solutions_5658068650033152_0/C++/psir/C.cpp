#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <cstdlib>
#include <string>
#include <sstream>
#include <gmpxx.h>

using namespace std;

#define VS vector<string>
#define VI vector<int>
#define VVI vector< VI >
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORC(it,kont) for(__typeof((kont).begin()) it = (kont).begin(); it!=(kont).end(); ++it)

char buff[20000];
int N,M,K;

int ok( int x)
	{
	if( M <= 2 )
		{
		return (x>= K);
		}
	int w = x / 4;
	int dosta = 0;
	if( 2*w + 1 <= M ) dosta = 1;
	if( dosta )
		{
		int covered = w*w + (w-1)*(w-1);
		int visak = x - 4*w;
		if ( visak >= 2 && 2*w + 2 <= N )
			{
			visak -= 2; covered += 2*w+1;
			} 
		if ( visak > 0 )
			{visak = 0; covered += w*visak; }
		return (covered >= K);
		}
	else if ( M % 2 == 1 )
		{
		w = (M-1)/2;
		int used = 4*w;
		int lused = 2*w+1;
		int covered = w*w + (w+1)*(w+1);
		int ostalo = min(N-lused,(x-used)/2);
		//cout << w << endl;
		//cout << lused << endl;
		//cout << covered << endl;
		//cout << ostalo << endl;
		used += ostalo * 2;
		covered += ostalo*(2*w+1);
		//cout << used << endl;
		//cout << covered << endl;
		int zadodati = w;
		while ( x - used )
			{
			int touse = min(x-used,4);
			used += touse;
			covered += touse*zadodati;
			--zadodati;
			zadodati = max(zadodati,1);
			}
		return (covered >= K);
		}
	else
		{
		w = M/2;
		int used = 4*w-2;
		int lused = 2*w-1;
		int covered = 2*w*w;
		int ostalo = min(N-lused,(x-used)/2);
		used += ostalo * 2;
		covered += ostalo*(2*w);
		int zadodati = w-1;
		while ( x - used )
			{
			int touse = min(x-used,4);
			used += touse;
			covered += touse*zadodati;
			--zadodati;
			zadodati = max(zadodati,1);
			}
		return (covered >= K);
		}
	return 1;
	}

int main()
    {
    int T;
    gets(buff);
    sscanf(buff,"%d",&T);

    FOR( t, 0, T )
        {
	cin >> N >> M >> K;
	if ( N < M ) swap (N,M);
        int sol = 0;
	int min = 1; int max = N*M;
	while (min != max)
		{
		int mid = (min + max)/2;
		if( ok (mid) )
			max = mid;
		else min = mid+1;
		}
	sol = max;
	//cout << N << " " << M << " " << K << endl;
	//cout << ok(11);
        printf("Case #%d: %d\n",t+1,sol);
        }
    return 0;
    }
