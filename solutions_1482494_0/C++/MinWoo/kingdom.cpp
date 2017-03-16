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

bool cmp(const pii& p1, const pii& p2)
{
	if ( p1.second == p2.second ) return p1.first < p2.first;
	return p1.second < p2.second;
}

int main()
{
	int TC;
	cin >> TC;
	for ( int tc=1 ; tc<=TC ; ++tc )
	{
		int N;
		cin >> N;
		vpii level(N);
		for ( int i=0 ; i<N ; ++i )
		{
			cin >> level[i].first >> level[i].second;
		}
		sort(level.begin(), level.end(), cmp);
/*
		for ( int i=0 ; i<N ; ++i )
		{
			cout << level[i].first << " " << level[i].second << endl;
		}
		puts("");
*/
		int res = 0;
		int earn = 0;
		vpii complete(N);
		bool bad = false;
		for ( int i=0 ; i<N ; ++i )
		{
			if ( level[i].second > earn )
			{
				for ( int j=i+1 ; j<N ; ++j )
				{
					if ( !complete[j].first && level[j].first <= earn )
					{
						earn += 1;
						complete[j].first = 1;
						//printf("complete %d-%d: %d stars\n", j, 1, earn);
						++res;
						break;
					}
				}
			}

			if ( level[i].second <= earn )
			{
				if ( complete[i].first )
				{
					earn += 1;
				}
				else 
				{
					earn += 2;
				}
				complete[i].second = 1;
				//printf("complete %d-%d: %d stars\n", i, 2, earn);
				++res;
			}
			else 
			{
				bad = true;
				break;
			}
		}
		if ( bad )
		{
			printf("Case #%d: Too Bad\n", tc);
		}
		else 
		{
			printf("Case #%d: %d\n", tc, res);
		}
	}
	return 0;
}
