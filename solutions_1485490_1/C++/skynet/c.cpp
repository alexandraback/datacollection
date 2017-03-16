#include <iostream>
#include <iomanip>
#include <queue>

using namespace std;

int main()
{
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int t, A[111], B[111];	
	long long a[111], b[111], mem[111][111];
	cin >> t;
	for (int i=1;i<=t;i++)
	{		
		memset(mem, 0, sizeof(mem));
		int n, m;
		cin >> n >> m;				
		for (int j=0;j<n;j++)
			cin >> a[j] >> A[j];
		for (int j=0;j<m;j++)
			cin >> b[j] >> B[j];
		for (int j=0;j<n;j++)
			for (int h=0;h<m;h++)
			{
				long long acc1 = 0, acc2 = 0;
				for (int j1=j+1;j1<=n;j1++)
				{
					if (A[j] == A[j1-1])
						acc1+=a[j1-1];
					acc2 = 0;
					for (int h1=h+1;h1<=m;h1++)
					{						
						if (A[j] == B[h1-1])
							acc2+=b[h1-1];
						mem[j1][h1] = max(mem[j1][h1], mem[j][h] + min(acc1, acc2));
					}
				}
				acc1 = 0, acc2 = 0;
				for (int j1=j+1;j1<=n;j1++)
				{
					if (B[h] == A[j1-1])
						acc1+=a[j1-1];
					acc2 = 0;
					for (int h1=h+1;h1<=m;h1++)
					{
						
						if (B[h] == B[h1-1])
							acc2+=b[h1-1];
						mem[j1][h1] = max(mem[j1][h1], mem[j][h] + min(acc1, acc2));
					}
				}
			}
		cout << "Case #" << i << ": " << mem[n][m] << endl;
	}
	return 0;
}