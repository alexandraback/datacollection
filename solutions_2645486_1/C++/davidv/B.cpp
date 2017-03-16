#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int minOut[10000];
int maxIn[10000];
bool done[10000];
int N, R, E;

void update(int i, int used)
{
	done[i] = true;
	
	for (int j=i-1; j>=0 && !done[j] && max(minOut[i]+used-(i-j)*R, used-(i-j-1)*R) > 0; j--)
	{
		minOut[j] = max(minOut[i]+used-(i-j)*R, used-(i-j-1)*R);
	}
	for (int j=i+1; j<N && !done[j] && max(minOut[i],R)+(j-i-1)*R < E; j++)
	{
		maxIn[j] = max(minOut[i],R)+(j-i-1)*R;
	}
}

void doCase()
{
	vector<pair<int, int> > vPairs;
	
	scanf("%d %d %d", &E, &R, &N);
	
	for (int i=0; i<N; i++)
	{
		int vi;
		scanf("%d", &vi);
		vPairs.push_back(make_pair(-vi, i));
	}
	
	sort(vPairs.begin(), vPairs.end());
	
	for (int i=0; i<N; i++)
	{
		maxIn[i] = E;
		minOut[i] = 0;
		done[i] = false;
	}
	
	long long totalGain = 0;
	for (int i=0; i<N; i++)
	{
		long long vi = -vPairs[i].first;
		int idx = vPairs[i].second;
		long long avail = min(maxIn[idx]-minOut[idx]+R, maxIn[idx]);
		totalGain += vi*avail;
		update(idx, avail);
	}
	
	printf("%lld\n", totalGain);
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i=1; i<=T; i++)
	{
		printf("Case #%d: ", i);
		doCase();
	}
	return 0;
}
