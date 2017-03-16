#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;
int s[100];
int main()
{
	int T;scanf("%d",&T);
	for (int kase=1;kase<=T;++kase)
	{
		int _k,n;
		scanf("%d %d",&_k,&n);
		for (int q=0;q<n;++q) scanf("%d",&s[q]);
		sort(s,s+n);
	
		int ret = n; //remove all
		long long k = _k;
		int add = 0;

		for (int m=0;m<n;++m)
		{
			int rm = n - m - 1;  
			if (k<=s[m] && k==1) break;//no more possible
			while (k <= s[m]) //add mote
			{
				k += k - 1;
				add++;
			}
			k+=s[m];
			if (rm+add<ret) ret = rm + add;
		}
		printf("Case #%d: %d\n",kase,ret);

	}
	return 0;
}
