#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int n, m;
int nt;
int A, B;

long long cnt;

char s[100];
char z[100];

set<int> was;

int main()
{
	scanf("%d", &nt);
	
	for(int tt = 1; tt <= nt; tt++)
	{	
		printf("Case #%d: ", tt);
		
		scanf("%d %d", &A, &B);
		cnt = 0;
		
		for(int n = A; n < B; n++)
		{
			sprintf(s, "%d", n);
			was.clear();
			for(int j = 1; s[j]; j++)
			{
				int p = j, k;
				for(k = 0; s[k]; k++)
				{
					z[k] = s[p];
					p++;
					if (!s[p]) p = 0;
				}
				z[k] = 0;
				sscanf(z, "%d", &m);
				if (n < m && A <= m && m <= B && !was.count(m))
				{
					cnt++;
					was.insert(m);
					//printf("%d\t%d\n", n, m);
				}
			}
		}
		
		cout << cnt << endl;
	}
	
	return 0;
}
