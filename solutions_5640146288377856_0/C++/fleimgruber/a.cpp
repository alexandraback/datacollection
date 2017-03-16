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


#define MAX_N 30

int r,c,w;

int main()
{
	int tc;
	scanf("%d",&tc);
	for (int x=1; x<=tc; x++)
	{
		scanf("%d %d %d",&r,&c,&w);
		int ans=0;
		for (int i=1; i<=r; i++)
			for (int j=w; j<=c; j+=w)
				ans++;
		if (c%w!=0)
			ans++;
		printf("Case #%d: %d\n",x,ans+w-1);
	}
	return 0;
}
