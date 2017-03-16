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


int b,m;
bool a[10][10],vis[10];

int check(int i)
{
	if (vis[i])
		return m+1;
	if (i==b)
		return 1;
	vis[i]=true;
	int ans=0;
	for (int j=1; j<=b; j++)
		if (a[i][j])
			ans+=check(j);
	vis[i]=false;
	return ans;
}

bool solve(int i, int j)
{
	if (i==b)
		return check(1)==m;
	if (i==j)
		return solve(i,j+1);
	if (j>b)
		return solve(i+1,1);
	a[i][j]=0;
	if (solve(i,j+1))
		return true;
	if (j<i&&a[j][i])
		return false;
	a[i][j]=1;
	return solve(i,j+1);
}

int main()
{
	int tc;
	scanf("%d",&tc);
	for (int asdf=1; asdf<=tc; asdf++)
	{
		printf("Case #%d: ",asdf);
		scanf("%d %d",&b,&m);
		for (int i=1; i<=b; i++)
			for (int j=1; j<=b; j++)
				a[i][j]=0;
		if (solve(1,1))
		{
			printf("POSSIBLE\n");
			for (int i=1; i<=b; i++,printf("\n"))
				for (int j=1; j<=b; j++)
					printf("%d",a[i][j]);
		}
		else
			printf("IMPOSSIBLE\n");
	}
	return 0;
}
