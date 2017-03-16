#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<stack>
#include<cmath>
#include<iomanip>
#include<cstdlib>
#include<sstream>
#include<climits>
using namespace std;

int ans[30][30][30];

int main()
{
	std::ios::sync_with_stdio(false); 
	
	int n, i, j, k, l ,t, ct = 0, y, q, r, c, w;
	
	cin>>t;
	
	ans[1][1][1] = 1;
	ans[1][2][1] = 2;
	ans[1][2][2] = 2;
	ans[1][3][1] = 3;
	ans[1][3][2] = 3;
	ans[1][3][3] = 3;

	for(i = 4;i <= 25; i++)
	{		
		for(j = 1; j <=i; j++)
		{
			if(2*j >= i)
			{
				ans[1][i][j] = j + 1;
			}
			
			else
			{
				ans[1][i][j] = 1 + ans[1][i - j][j];
			}
		}

		ans[1][i][1] = i;
		ans[1][i][i] = i;
	}
	
	for(i = 2; i <= 24; i++)
	{
		for(j = 1; j <=24; j++)
		{
			for(w = 1; w <= j; w++)
			{
				if(w == j)
				{
					ans[i][j][w] = i - 1 + j;
				}
				
				else if(2*w > j)
				{
					ans[i][j][w] = i + w;
				}
				
				else
				{
					ans[i][j][w] = i + ans[i][j-w][w];
				}
			}
		}	
	}
	
	k = 0;
	
	while(t--)
	{
		k++;
		cin>>r>>c>>w;
		
		cout<<"Case #"<<k<<": "<<ans[r][c][w]<<"\n";	
	}
	
	return 0;
}
