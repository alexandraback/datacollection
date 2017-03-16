#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<math.h>
#include<set>
#include<vector>
#include<string.h>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

char was[2001326];
int use[2001326];

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif

	const double EPS = 1e-12;

	int T;

	cin >> T;

	for (int cs = 1; cs <= T; cs ++)
	{

		memset(use,0,sizeof(use));
		memset(was,0,sizeof(was));

		printf("Case #%d:\n",cs);

		int n;
		cin >> n;

		vector<int>arr(n);

		for (int i=0; i<n; i++)
			cin >> arr[i];

		int upto = (1 << n);

		bool ok = false;

		for (int curr = 1; curr < upto; curr++)
		{
			int sum = 0;
			for (int i=0; i<n; i++)
				if (curr & (1 << i))
					sum += arr[i];
			if (!was[sum])
			{
				was[sum] = 1;
				use[sum] = curr;
			}
			else
			{
				for (int i=0; i<n; i++)
					if (use[sum] & (1 << i))
						printf("%d ",arr[i]);
				printf("\n");
				for (int i=0; i<n; i++)
					if (curr & (1 << i))
						printf("%d ",arr[i]);
				printf("\n");
				ok = true;
				break;
			}
		}

		if (!ok)
			printf("Impossible\n");

		printf("\n");
	}

	return 0;
}