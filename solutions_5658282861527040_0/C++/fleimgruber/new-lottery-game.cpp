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
typedef unsigned long long ull;
typedef vector<int> vi;


int a,b,k;

int main()
{
	int tc;
	scanf("%d",&tc);
	for (int x=1; x<=tc; x++)
	{
		scanf("%d %d %d",&a,&b,&k);
		int cnt=0;
		for (int i=0; i<a; i++)
			for (int j=0; j<b; j++)
				if ((i&j)<k)
					cnt++;
		printf("Case #%d: %d\n",x,cnt);
	}
	return 0;
}
