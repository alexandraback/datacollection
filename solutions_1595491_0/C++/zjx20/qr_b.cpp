#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool can(int tot, int q)
{
	int tmp = tot/3;
	int r = tot%3;
	if(r>0) return tmp+1 >= q;
	return tmp >= q;
}

int main()
{
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("qr_b_output.txt", "w", stdout);

	int t,n,s,q;
	int ss[200];
	int aa[200];
	int len;
	scanf("%d",&t);
	for(int ca=1;ca<=t;ca++)
	{
		printf("Case #%d: ",ca);
		scanf("%d%d%d", &n,&s,&q);
		for(int i=0;i<n;i++)
			scanf("%d",&ss[i]);
		sort(ss, ss+n);

		int must = 0;
		int cs = 0;
		len = 0;
		for(int i=n-1;i>=0;i--)
		{
			if(ss[i]-q>=0 && q - (ss[i]-q)/2 <= 2)
			{
				// all sup large than q
				aa[len++] = ss[i];
				if(!can(aa[len-1], q)) must++;
				if(aa[i]<29 && aa[i]>1) cs++;
			}
		}

		if(must > s) printf("%d\n", len-(must-s));
		else
		{
			printf("%d\n",len);
		}
	}

	return 0;
}
