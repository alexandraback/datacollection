/*
    Author:-Sarthak Taneja
    CSE 2nd year,MNNIT Allahabad
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair< int,int > ii;
typedef vector< ii > vii;

#define sfd(x) scanf("%d",&x)
#define sfs(x) scanf("%s",x)
#define sff(x) scanf("%lf",&x)
#define mod 1000000007
#define MAX 1000000
#define INF 1000000000
#define pb push_back
#define mp make_pair
#define fr first 
#define sc second
#define testcases scanf("%d",&t);while(t--)
#define ffor(a,b,c) for(a=b;a<c;a++)
#define rfor(a,b,c) for(a=b;a>=c;a--)

ll power(ll base, ll exp)
{
	if(exp == 0)
	return 1;
	ll r = power(base, exp/2);
	r=(r*r)%mod;
	if(exp&1)
		r=(r*base)%mod;
	return r;
}

/**********************************************/

int grid[55][55];
int b,m;

void fil()
{
	int i;
	for(i=0;i<b-1;i++)
		grid[i][i+1] = 1;
}

int main()
{
	int i,j,t;
	int casecnt=1;


	testcases
	{
		memset(grid, 0 , sizeof(grid));
		printf("Case #%d: ",casecnt++);

		scanf("%d%d",&b,&m);
		int dim=b;

		fil();

		if(m > b-1)
			printf("IMPOSSIBLE\n");
		else
		{
			m--;
			int x=2;
			while(m--)
			{
				grid[0][x] = 1;
				x++;
			}

			printf("POSSIBLE\n");
			for(i=0;i<dim;i++)
			{
				for(j=0;j<dim;j++)
					printf("%d",grid[i][j]);
				printf("\n");
			}

		}
	}
	return 0;
}