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


int n;
ll d[2],m[2];

int main()
{
	int tc,cse=1;
	scanf("%d",&tc);
	while (tc--)
	{
		scanf("%d",&n);
		int cnt=0;
		while (n--)
		{
			int cd,ch,cm;
			scanf("%d %d %d",&cd,&ch,&cm);
			while (ch--)
			{
				d[cnt]=cd;
				m[cnt]=cm;
				cm++;
				cnt++;
			}
		}
		int ans=0;
		if (cnt==2)
		{
			if (m[0]>m[1])
			{
				swap(m[0],m[1]);
				swap(d[0],d[1]);
			}
			if (m[0]!=m[1])
			{
				int m0=360-d[0],
					m1=360-d[1];
				ll t0=m[0]*m0,
					t1=m[1]*m1;
				if (t0<=t1)
				{
					m0+=360;
					if (m0*m[0]<=t1)
						ans=1;
				}
			}
		}
		printf("Case #%d: %d\n",cse,ans);
		cse++;
	}
	return 0;
}
