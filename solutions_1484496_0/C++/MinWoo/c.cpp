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

int main()
{
	int TC;
	scanf("%d", &TC);
	for ( int tc=1 ; tc<=TC ; ++tc )
	{
		printf("Case #%d:\n", tc);
        int n;
        cin >> n;
        int a[64];
        for ( int i=0 ; i<n ; ++i )
        {
            cin >> a[i];
        }

        map<int, vector<int> > mv;
        for ( int m=0 ; m<(1<<n) ; ++m )
        {
            int sum = 0;
            for ( int i=0 ; i<n ; ++i )
            {
                if ( m & (1<<i) )
                {
                    sum += a[i];
                }
            }
            mv[sum].push_back(m);
        }
        
        map<int, vector<int> >::iterator it = mv.begin();
        while ( it != mv.end() )
        {
            if ( it->second.size() == 2 )
            {
                vector<int>& v = it->second;
                for ( int k=0 ; k<v.size() ; ++k )
                {
                    for ( int i=0 ; i<n ; ++i ) 
                    {
                        if ( v[k] & (1<<i) )
                        {
                            printf("%d ", a[i]);
                        }
                    }
                    puts("");
                }
                break;
            }
            ++it;
        }
	}
	return 0;
}
