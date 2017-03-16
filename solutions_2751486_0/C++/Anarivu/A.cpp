#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<string>
#include<queue>
using namespace std;


char s[1000005];


vector<pair<int, int> > a;
 
int main()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);

	int T;
	scanf("%d", &T);
	int tc = 1;

	while(T > 0)
	{
		T--;
		printf("Case #%d: ", tc);
		tc++;

		a.clear();

		scanf("%s", s);
		long long n = strlen(s);
		long long k;
		scanf("%lld", &k);

		//a, e, i, o, and u
		long long st = -1, ln = 0;

		for(int i = 0; i < n; i++)
		{
			if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
			{
				if(ln >= k)
					a.push_back(make_pair(st, i-1));
				ln = 0;
			}
			else
			{
				if(ln == 0)
					st = i;
				ln++;
			}
		}
		if(ln >= k)
			a.push_back(make_pair(st, n-1));

		if(a.size() == 0)
		{
			printf("0\n");
			continue;
		}
		
		long long res = 0;

		for(int i = 0, j = 0; i < n; i++)
		{
			if(i > a[j].second - (k-1))
				j++;
			if(j == a.size())
				break;
			res += n - (max(a[j].first, i) + k-1);
		}

		printf("%lld\n", res);
	}

	return 0;
}