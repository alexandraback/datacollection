#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define M 2000100

int prev[M], v[M];
int a[22];

void test()
{
	int n;
	for(int i = 0; i < M; i++) v[i] = prev[i] = 0;
	v[0] = 1;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	for(int i = 0; i < n; i++)
	{
		for(int j = M-a[i]-1; j >= 0; j--) if(v[j] == 1)
		{
			//printf("i = %d, j = %d, a[i] = %d\n", i, j, a[i]);
			if(v[j+a[i]])
			{
				vector<int> q0,q1,r0,r1;
				q1.push_back(a[i]);
				int p = j+a[i];
				while(p != 0)
				{
					q0.push_back(a[prev[p]]);
					p -= a[prev[p]];
				}
				p = j;
				while(p != 0)
				{
					q1.push_back(a[prev[p]]);
					p -= a[prev[p]];
				}
				sort(q0.begin(), q0.end());
				sort(q1.begin(), q1.end());
				int a,b;
				for(a = 0, b = 0; a < q0.size() && b < q1.size(); )
				{
					if(q0[a] == q1[b])
					{
						a++;
						b++;
					}
					else if(q0[a] < q1[b])
					{
						r0.push_back(q0[a]);
						a++;
					}
					else
					{
						r1.push_back(q1[b]);
						b++;
					}
				}
				while(a < q0.size())
				{
					r0.push_back(q0[a]);
					a++;
				}
				while(b < q1.size())
				{
					r1.push_back(q1[b]);
					b++;
				}
				for(a = 0; a < r0.size(); a++) printf("%d ", r0[a]); printf("\n");
				for(a = 0; a < r1.size(); a++) printf("%d ", r1[a]); printf("\n");
				return;
			}
			v[j+a[i]] = 1;
			prev[j+a[i]] = i;
		}
	}
	printf("Impossible\n");
}

int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++)
	{
		printf("Case #%d:\n", i);
		test();
	}
}
