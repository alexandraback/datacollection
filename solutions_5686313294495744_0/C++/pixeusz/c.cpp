#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

#define MAXN 1002
#define MAXL 22
char rawFirst[MAXL];
char rawSecond[MAXL];
string Firsts[MAXN];
string Seconds[MAXN];
bool used[MAXN];

void SolveCase(int caseId);

int main()
{
	int T;
	scanf("%d", &T);
	for(int i = 1; i <= T; ++i)
		SolveCase(i);
	return 0;
}

void SolveCase(int caseId)
{
	int n;
	scanf("%d" ,&n);
	int maxFakeCount = 0;
	
	for(int i = 0; i < n; ++i)
	{
		scanf("%s%s", rawFirst, rawSecond);
		Firsts[i] = string(rawFirst);
		Seconds[i] = string(rawSecond);
	}
	
	int e = (1<<n) - 1;
	for(int i = 1; i <= e; ++i)
	{
		int fakeCount = n;
		for(int j = i, k = 0; k < n; j >>= 1, ++k)
		{
			bool isReal = j & 1;
			if(isReal)
				--fakeCount;
		}
		if(fakeCount < maxFakeCount) continue;
		
		set<string> fSet, sSet;
		//fSet.clear(), sSet.clear();
		for(int j = i, k = 0; k < n; j >>= 1, ++k)
		{
			bool isReal = j & 1;
			if(isReal)
			{
				fSet.insert(Firsts[k]);
				sSet.insert(Seconds[k]);
			}
		}

		
		bool isValid = true;
		for(int k = 0; k < n && isValid; ++k)
			isValid = fSet.find(Firsts[k]) != fSet.end() && sSet.find(Seconds[k]) != sSet.end();

		if(isValid)
			maxFakeCount = fakeCount;
	}

	printf("Case #%d: %d\n", caseId, maxFakeCount);
}


