#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define NINF -0x3f3f3f3f

using namespace std;

typedef pair<int,int> pii;

string wordA[20];
string wordB[20];
int maskA[20];
int maskB[20];

void solve ()
{
	int N;
	scanf("%d",&N);
	
	for (int i = 0; i < N; i += 1)
	{
		cin >> wordA[i] >> wordB[i];
	}
	
	memset(maskA,0,sizeof maskA);
	memset(maskB,0,sizeof maskB);
	for (int i = 0; i < N; i += 1)
	{
		for (int j = 0; j < N; j += 1)
		{
			if (i == j) continue;
			
			if (wordA[i] == wordA[j])
			{
				maskA[i] |= (1<<j);
				maskA[j] |= (1<<i);
			}
			
			if (wordB[i] == wordB[j])
			{
				maskB[i] |= (1<<j);
				maskB[j] |= (1<<i);
			}
		}
	}
	
	int ans = 0;
	for (int i = 1; i < (1<<N); i += 1)
	{
		bool valid = true;
		int curAns = 0;
		for (int j = 0; j < N; j += 1)
		{
			if (!(i & (1<<j)))
			{
				if ((maskA[j] & i) && (maskB[j] & i))
					curAns++;
				else
					valid = false;
			}	
		}
		
		if (valid)
			ans = max(ans,curAns);
	}
	
	printf("%d\n",ans);
}

int main (int argc, char const* argv[])
{
	int T;
	scanf("%d",&T);
	
	for (int t = 1; t <= T; ++t)
	{
		printf("Case #%d: ",t);
		solve();
	}
	
	return 0;
}
