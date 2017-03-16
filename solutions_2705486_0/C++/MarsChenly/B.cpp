#include <iostream>
#include <cstdio>

using namespace std;


int lesibian[4] = {1 , 5, 9 , 13};
int len[4] = {0 , 2 , 4 , 6};

long long C(int n , int m)
{
	long long s = 1;
	for (int i = 1; i <= m; i++)
	{
		s = s * (n - m + i) / i;
	}
	return s;
}



int main()
{
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int task;
	//cout << C(5 , 2) << endl;
	cin >> task;
	for (int cases = 1; cases <= task; cases ++)
	{
		double ans  = 0;
		int n , x , y;
		cin >> n >> x >> y;
		int m = n;
		y = y + 1;
		if (x < 0) x = -x;
		for (int i = 0; i < 4; i++)
		{
			if (n - lesibian[i] >= 0)
			{
				n = n - lesibian[i];
			} else
			{
				//cout << n << endl;
				
				if ((x + y) / 2 < i)
				{
					ans = 1;
					//cout << "fuck" << endl;
				} else
				if ((x + y) / 2 == i)
				{
					//cout << "fuck" << endl;
					
					long long sum = 0;
					for (int j = 0; j <= n; j++)
					if (j <= len[i] && n - j <= len[i])
					{
						//cout << j << endl;
						sum = sum + C(n , j);
					}	
					for (int j = 0; j <= n; j++)
					{
						if (j <= len[i] && n - j <= len[i])
						if (j >= y)
						{
							ans = ans + 1.0 * C(n , j) / sum;
						}
					}
					
				} else
				{
					ans = 0;
				}
				break;
			}
		}
		
		
		
		
		cout << "Case #" << cases << ": " << m << " " << x << " " << y - 1 << " ";
		printf("%.8lf\n",ans);
	}
	
	return 0;
}