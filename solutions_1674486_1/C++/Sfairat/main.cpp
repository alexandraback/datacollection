#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <memory>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;
typedef pair <int, int> pii;
typedef long long ll;

struct vert
{
	vector<int> parents;
	int firstReachedAncestor;
	int exitTime;
	bool was;
	vert()
	{
		firstReachedAncestor = -1;
		was = false;
	}
} *vertexes;

int dfs1(int cur, int time)
{
	time++;
	vertexes[cur].was = true;
	for (int i = 0, iEnd = vertexes[cur].parents.size(); i < iEnd; i++)
	{
		int nn = vertexes[cur].parents[i];
		if (!vertexes[nn].was)
		{
			time = dfs1(nn, time);
		}
	}
	time++;
	vertexes[cur].exitTime = time;
	return time;
}

vector<pii> topSort(int vertCount)
{
	int time = 0;
	for (int i = 0; i < vertCount; i++)
	{
		if (!vertexes[i].was)
		{
			time = dfs1(i, time);
		}
	}

	vector<pii> sv;
	for (int i = 0; i < vertCount; i++)
	{
		sv.push_back(pii(vertexes[i].exitTime, i));
	}
	sort(sv.begin(), sv.end());
	return sv;
}

bool dfs2(int curVert, int ancestor)
{
	if (vertexes[curVert].firstReachedAncestor == ancestor)
	{
		return true;
	}
	if (vertexes[curVert].firstReachedAncestor != -1)
		return false;
	vertexes[curVert].firstReachedAncestor = ancestor;

	for (int i = 0, iEnd = vertexes[curVert].parents.size(); i < iEnd; i++)
	{
		if (dfs2(vertexes[curVert].parents[i], ancestor))
			return true;
	}
	return false;
}

void reset(int count)
{
	for (int i = 0; i < count; i++)
		vertexes[i].firstReachedAncestor = -1;
}

void test(int testNo)
{
    int N;
    scanf("%d", &N);
    
	vertexes = new vert[N];

	for (int i = 0; i < N; i++)
	{
		int ac;
		scanf("%d", &ac);

		for (int j = 0; j < ac; j++)
		{
			int ca;
			scanf("%d", &ca);
			vertexes[i].parents.push_back(ca-1);
		}
	}

	vector<pii> sv = topSort(N);

	bool res = false;
	for (int i = N-1; i >= 0; i--)
	{
		if (dfs2(sv[i].second, sv[i].second))
		{
			res = true;
			break;
		}
		reset(N);
	}

    printf("Case #%d: ", testNo+1);
	if (res)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
    
	delete [] vertexes;
}

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int TC;
    scanf("%d", &TC);
    
    for (int i = 0; i < TC; i++)
        test(i);
    
    return 0;
}