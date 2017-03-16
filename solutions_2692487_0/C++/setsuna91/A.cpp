#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <bitset>
#include <sstream>
#include <string>

#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

#define FILL(arr,n) memset(arr,n,sizeof(arr))
#define FORUP(i,m,n) for(int i=(m); i<(n); i++)
#define FORDOWN(i,m,n) for(int i=(m)-1; i>=(n); i--)

#define PB push_back
#define MP make_pair
#define F first
#define S second

#define INF 2000000000
#define EPS 1e-11
#define PI acos(-1.0)
#define MAX_N 1000005
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<pii> vii;

int
main()
{
	int T;
	int A;
	int N;
	vector<int> motes;
	scanf("%d", &T);
	for(int tc = 1;tc <= T;tc++)
	{
		motes.clear();
		scanf("%d %d", &A,&N);
		for(int i = 0;i < N;i++)
		{
			int tmp;
			scanf("%d", &tmp);
			motes.PB(tmp);
		}
		sort(motes.begin(), motes.end());
		
		/*
		printf("%d %d\n",A,N);
		for(int i = 0;i < N;i++)
		{
			printf("%d ", motes[i]);
		}
		printf("\n");
		*/

		int minAct = N;
		int actnow = 0;
		int motesnow = A;
		bool yes = true;
		for(int i = 0;i < N;i++)
		{
			if(actnow > minAct)
			{
				yes = false;
				break;
			}
			if(motesnow > motes[i])
			{
				motesnow += motes[i];
			}
			else
			{
				int allDelete = actnow + (N - i);
				if(motesnow > 1)
				{
					int need = 0;
					int multi = motesnow - 1;
					bool yes2 = true;
					while(motesnow <= motes[i])
					{
						actnow++;
						motesnow = motesnow + multi;
						multi = motesnow - 1;
						if(actnow > minAct)
						{
							yes2 = false;
							break;
						}
					}
					minAct = min(minAct, allDelete);
					motesnow += motes[i];
					if(!yes2)
					{
						yes = false;
						break;
					}
				}
				else
				{
					minAct = min(minAct, allDelete);
					yes = false;
					break;
				}
			}
		}
		if(yes)minAct = min(minAct,actnow);
		printf("Case #%d: %d\n",tc,minAct);
	}
return 0;
}