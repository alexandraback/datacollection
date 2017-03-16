#include <bits/stdc++.h>

using namespace std;

int ans[50][50];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tn;
	cin>>tn;
	for(int tc=1; tc<=tn; tc++)
	{
		int n;
		long long m;
		bool ok = true;
		cin>>n>>m;
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				ans[i][j]=0;
		long long bn=1;
		for(int i=0; i<n-2; i++) bn*=2;
		if(m>bn)
			ok=false;
		else
		{
			//solution here
			for(int i=1; i<n; i++)
				for(int j=i+1; j<n; j++)
					ans[i][j]=1;
			if(bn==m)
				for(int i=1; i<n; i++)
					ans[0][i]=1;
			else
				for(int i=2; m; i++, m/=2)
					if(m%2)
						ans[0][n-i]=1;
		}
		cout << "Case #" << tc << ": ";
		if(ok)
		{
			cout << "POSSIBLE" << endl;
			for(int i=0; i<n; i++)
			{
				for(int j=0; j<n; j++)
					cout<<ans[i][j];
				cout<<endl;
			}
		}
		else
			cout << "IMPOSSIBLE" << endl;
	}

	return 0;
}