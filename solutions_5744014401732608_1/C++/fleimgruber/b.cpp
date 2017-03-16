#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define all(a) (a).begin(),(a).end()
#define pb push_back
#define sz(a) ((int)(a).size())
#define mp make_pair
#define fi first
#define se second

typedef pair<int,int> pint;
typedef long long ll;
typedef vector<int> vi;


int b;
ll m;

int main()
{
	int tc;
	scanf("%d",&tc);
	for (int asdf=1; asdf<=tc; asdf++)
	{
		printf("Case #%d: ",asdf);
		scanf("%d %lld",&b,&m);
		if (m<=(1LL<<((ll)(b-2))))
		{
			printf("POSSIBLE\n");
			putchar('0');
			if (m==(1LL<<((ll)(b-2))))
				for (int i=2; i<=b; i++)
					putchar('1');
			else
			{
				for (int i=2; i<b; i++)
					putchar('0'+((m>>(i-2))&1));
				putchar('0');
			}
			printf("\n");
			for (int i=2; i<b; i++)
			{
				putchar('0');
				for (int j=2; j<b; j++)
					if (j>=i)
						putchar('0');
					else
						putchar('1');
				printf("1\n");
			}
			for (int i=1; i<=b; i++)
				putchar('0');
			printf("\n");
		}
		else
			printf("IMPOSSIBLE\n");
	}
	return 0;
}
