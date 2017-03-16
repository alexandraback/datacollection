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

int ans[100][100];

int main()
{
	std::ios::sync_with_stdio(false); 
	
	int n, i, j, k, l ,t, ct = 0, y, q, r, c, w;
	
	cin>>t;
	
	ans[1][1] = 1;
	ans[2][1] = 2;
	ans[2][2] = 2;
	ans[3][1] = 3;
	ans[3][2] = 3;
	ans[3][3] = 3;

	for(i = 4;i <= 10; i++)
	{		
		for(j = 1; j <=i; j++)
		{
			if(2*j >= i)
			{
				ans[i][j] = j + 1;
			}
			
			else
			{
				ans[i][j] = 1 + ans[i - j][j];
			}
		}

		ans[i][1] = i;
		ans[i][i] = i;
	}
	
	k = 0;
	while(t--)
	{
		k++;
		cin>>r>>c>>w;
		
		cout<<"Case #"<<k<<": "<<ans[c][w]<<"\n";	
	}
	
	return 0;
}
