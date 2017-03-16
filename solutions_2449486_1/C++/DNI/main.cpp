
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;



//struct cell
//{
//	cell(int x, int y, int h): x(x), y(y), h(h){};
//	int x;
//	int y;
//	int h;
//};

//int cmp(const cell &a, const cell &b)
//{
//	if(a)
//}


int pattern[100][100];
//int curr[100][100];
int maxR[100], maxC[100];
int n,m, temp;

void init()
{
	for(int i = 0; i < n; i++)
	{
		int max__ = -1000;
		for(int j = 0; j < m; j++)
			max__ = max(max__, pattern[i][j]);
		maxR[i] = max__;
	}

	for(int j = 0; j < m; j++)
	{
		int max__ = -1000;
		for(int i = 0; i < n; i++)
			max__ = max(max__, pattern[i][j]);
		maxC[j] = max__;
	}
}


bool IsPosible(int x, int y, int h)
{
	return (maxR[x] <= h || maxC[y] <= h);
}

//bool canSetAndSet(int x, int y, int h)
//{
//	bool bRet = true;
//	for(int i = 0; i < n; i++)
//	{
//		if(pattern[i][y] < h)
//		{
//			bRet = false;
//			break;
//		}
//	}
//
//	if(bRet)
//}

int main()
{
	freopen("output.out", "w", stdout);
	freopen("input.in", "r", stdin);

	int t;
	cin >> t;
	//vector<cell> ar;
	//ar.reserve(100 * 100);
	
	for(int tt = 0; tt < t; tt++)
	{
		
		//ar.resize(0);

		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				scanf("%d", &temp);
				pattern[i][j] = temp;
				//curr[i][j] = 100;
			}
			
		}
		

		bool bRes = true;
		init();

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				if(!IsPosible(i,j,pattern[i][j]))
				{
					bRes = false;
					break;
				}
			}
		}

		printf("Case #%d: %s", tt+1, (bRes ? "YES" : "NO"));

		if(tt != t-1)
			printf("\n");
	}
	return 0;
}