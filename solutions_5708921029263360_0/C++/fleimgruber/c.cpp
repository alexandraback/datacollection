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


int J,P,S,K,had[3][4][4];

int main()
{
	int tc;
	scanf("%d",&tc);
	for (int asdf=1; asdf<=tc; asdf++)
	{
		printf("Case #%d: ",asdf);
		scanf("%d %d %d %d",&J,&P,&S,&K);
		printf("%d\n",J*P*min(S,K));
		for (int i=0; i<3; i++)
			for (int j=1; j<=3; j++)
				for (int k=1; k<=3; k++)
					had[i][j][k]=0;
		for (int i=1; i<=J; i++)
			for (int j=1; j<=P; j++)
				for (int k=1; k<=S; k++)
				{
					if (max(had[0][i][j],max(had[1][i][k],had[2][j][k]))==K)
						continue;
					had[0][i][j]++;
					had[1][i][k]++;
					had[2][j][k]++;
					printf("%d %d %d\n",i,j,k);
				}
	}
	return 0;
}
