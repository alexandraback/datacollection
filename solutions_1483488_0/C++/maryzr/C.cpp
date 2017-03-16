#include <iostream>
//#include <vector>
//#include <algorithm>
using namespace std;
typedef long long ll;

int t;
int l, r;
int f[2000001];
int ten; 
ll countt, t_countt;
int p, q;

void count_ten()
{
	int k = l;
	ten = 1;
	while(k>9)
	{
		ten *= 10;
		k /= 10;		
	}
}

int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	//freopen("C-large.in", "r", stdin);
	//freopen("C-large.out", "w", stdout);

	scanf("%d", &t);

	for(int x=1; x<=t; x++)
	{
		scanf("%d%d", &l, &r);
		for(int i=1; i<=2000000; i++) f[i] = 1;
		count_ten();
		countt = 0;

		if(ten > 1)
		{
			for(int i=l; i<=r; i++)
			{
				if(f[i])
				{
					t_countt = 0;
					q = i;
					do
					{
						p = q % 10;
						q /= 10;
						q = ten * p + q;
						if(q >=l && q <=r)
						{
							t_countt++;
							f[q] = 0;
						}

					}while(q != i);

					countt += t_countt * (t_countt - 1);
				}
			}
		}

		printf("Case #%d: %lld\n", x, countt >> 1);
	}
	
	return 0;
}