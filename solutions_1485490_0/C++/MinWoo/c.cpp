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
typedef pair<int,int64> pii;
typedef vector<pii> vpii;

int N, M;
vpii A, B;
int64 memo[128][128];

int64 solve(int a, int b)
{
    if ( memo[a][b] > 0LL ) return memo[a][b];
    int64& res = memo[a][b];

    for ( int i=0 ; i<=b ; ++i )
    {
        if ( A[a].first == B[i].first )
        {
            int64 made = min(A[a].second, B[i].second);
            res = max(res, made);
            for ( int j=0 ; j<a ; ++j )
            {
                for ( int k=0 ; k<=i ; ++k )
                {
                    res = max(res, solve(j, k) + made);
                }
            }
        }
    }
/*
    for ( int i=0 ; i<a ; ++i )
    {
        if ( A[i].first == B[b].first )
        {
            int64 made = min(A[i].second, B[b].second);
            res = max(res, made);
            for ( int j=0 ; j<a ; ++j )
            {
                for ( int k=0 ; k<b ; ++k )
                {
                    res = max(res, solve(j, k) + made);
                }
            }
        }
    }
*/

    return res;
}

int main()
{
	int TC;
    cin >> TC;
	for ( int tc=1 ; tc<=TC ; ++tc )
	{
        A.clear();
        B.clear();

        cin >> N >> M;
        for ( int i=0 ; i<N ; ++i )
        {
            pii p;
            cin >> p.second >> p.first;
            A.push_back(p);
        }
        for ( int i=0 ; i<M ; ++i )
        {
            pii p;
            cin >> p.second >> p.first;
            B.push_back(p);
        }
        
        memset(memo, 0, sizeof(memo));
		printf("Case #%d: ", tc);
        cout << solve(N-1, M-1) << endl;
/*
        for ( int i=0 ; i<N ; ++i )
        {
            for ( int j=0 ; j<M ; ++j )
            {
                printf("%3lld ", memo[i][j]);
            }
            puts("");
        }
*/
    }
	return 0;
}
