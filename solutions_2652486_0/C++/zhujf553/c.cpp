#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	int T;
	int R, N, M, K;
	int a[100];
	cin >> T;
	for(int tt = 1 ; tt <= T ; tt++)
	{
		cout << "Case #1:" << endl;
		cin >> R >> N >> M >> K;
		for(int i = 1 ; i <= R ; i++)
		{
			
			for(int j = 1 ; j <= K ; j++)
				cin >> a[j];
			
			for(int k1 = 2 ; k1 <= M ; k1++)
				for(int k2 = 2 ; k2 <= M ; k2++)
					for(int k3 = 2 ; k3 <= M ; k3++)
					{
						int j;
						
						for(j = 1 ; j <= K ; j++)
						{
							if(a[j] % k1 != 0 && a[j] % k2 != 0 && a[j] % k3 != 0 && a[j] != 1)
								break;
							if(k1 * k2 * k3 < a[j]) 
								break;
						}
						if(j > K)
						{
							cout << k1 << k2 << k3 << endl;
							k1 = k2 = k3 = M+1;
						}
					}
		}
	}
	return 0;
}
