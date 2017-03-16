#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

int main()
{
	int dp[111][111];
	int v[333];
	int e, r, n, m, i, j, k, t, tt;
	long long ans;
	int t1, t2;

	ifstream fin("B-small-attempt1.in");
	ofstream fout("out.txt");
	fin >> tt;
	for (t=1; t<=tt; t++)
	{
		fin >> e >> r >> n;
		ans =0;
		for (i=1; i<=n; i++) {
			fin >> v[i];
			ans += v[i];
		}

		if (r>=e)
		{
			 fout << "Case #" << t << ": " << ans*e << endl;
		}
		else
		{
			for (i=e; i>=0; i--) dp[1][i] = v[1]*(e-i);
			for (i=2; i<=n; i++)
				for (j=e; j>=0; j--)
				{
					t1 = -22222222;
					for (k=e;k>=r; k--) if ((t1<dp[i-1][k-r]+v[i]*(k-j)) && (k>=j))
						{
							t1=dp[i-1][k-r]+v[i]*(k-j);
						}

					dp[i][j]=t1;
				}
				
			fout << "Case #" << t << ": " << dp [n][0] << endl;
		}
	}

}