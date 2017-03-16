#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

int N;
int inhe[1024][1024];
int incnt[1024];
int d[1024][1024];
int visited[1024];

bool go(int k)
{
    visited[k]++;
    if ( visited[k] == 2 ) return true;
    for ( int i=0 ; i<incnt[k] ; ++i )
    {
        if ( go(inhe[k][i]) ) return true;
    }
    return false;
}

bool solve()
{
    for ( int i=0 ; i<N ; ++i )
    {
        memset(visited, 0, sizeof(visited));
        if ( go(i) ) return true;
    }
    return false;
}

int main()
{
	int TC;
	scanf("%d", &TC);
	for ( int tc=1 ; tc<=TC ; ++tc )
	{
		printf("Case #%d: ", tc);
        
        memset(incnt, 0, sizeof(incnt));
        memset(d, 0, sizeof(d));
        scanf("%d", &N);
        for ( int i=0 ; i<N ; ++i )
        {
            scanf("%d", &incnt[i]);
            for ( int j=0 ; j<incnt[i] ; ++j ) 
            {
                scanf("%d", &inhe[i][j]);
                inhe[i][j]--;
                d[i][inhe[i][j]] = 1;
            }
        }
        
        puts(solve()?"Yes":"No");
	}
	return 0;
}
