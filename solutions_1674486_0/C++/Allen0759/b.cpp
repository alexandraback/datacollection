#include <iostream>
using namespace std;
 
const int maxnum = 50;
int c[maxnum][maxnum];


int searchPath(int c[maxnum][maxnum], int s, int d, int n, int times)
{
	if(times >= n) return 0;

	int count = 0;
	if(c[s][d] == 1)
		count++;

	for(int i = 0; i < n; i++)
	{
		if(c[s][i] == 1)
		{
			times++;
			count += searchPath(c, i, d, n, times);
		}
	}

	return count;
}

int main()
{
	
	int T;
	int count = 0;
	int N  = 0;

	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);


	scanf( "%d", &T );

	
	for(int i = 0; i < T; i++)
	{
		// ³õÊ¼»¯c[][]
		for(int i = 0; i < maxnum; ++i)
			for(int j = 0; j < maxnum; ++j)
				c[i][j] = 0;

		cin >> N;
		for(int j = 0; j < N; j++)
		{
			int num = 0;
			cin >> num;
			//cout << "num is " << num << endl;
			for(int k = 0; k < num; k++)
			{
				int inhs;
				cin >> inhs;
				//cout << j << " " <<inhs << endl;
				c[j][inhs - 1] = 1;
			}
		}

		bool b = false;

		for(int s = 0; s < N; s++)
		{
			for(int d = 0; d < N; d++)
			{
				int times = 0;
				if(searchPath(c, s, d, N, times) >= 2)
				{
					b = true;
					break;
				}
			}

			if(b) break;
		}

		if(b)
			printf("Case #%d: Yes\n", i+1);
		else
			printf("Case #%d: No\n", i+1);


	}
	
	
}