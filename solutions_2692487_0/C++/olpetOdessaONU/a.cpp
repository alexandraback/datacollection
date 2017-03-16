#pragma comment(linker, "/STACK:850000000")
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<cstring>
#include<string>
#include<cmath>
#include<complex>
#include<ctime>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
typedef vi::iterator vit;
typedef vector<pii> vpi;

#define sq(x) (x)*(x)
#define all(x) (x).begin(),(x).end()
#define cl(x) memset(x,0,sizeof(x))
#define LL "%I64d"
#define RLL(x) scanf(LL,&(x))

const int sz = 200; 
const int inf = 0;
int n,a;
int dyn[2][sz];
int mas[101];

void test(int t)
{
	scanf("%d%d",&a,&n);
	for(int i=0; i<n; ++i)
		scanf("%d",mas+i+1);
	sort(mas+1,mas+n+1);
	int cur = 0;
	for(int j=0; j<sz; ++j)
		dyn[cur][j]=inf;
	dyn[cur][0]=a;
	for(int i=1; i<=n; ++i)
	{
		for(int j=0; j<sz; ++j)
			dyn[1^cur][j]=inf;
		for(int j=0; j<sz; ++j)
		{
			if(dyn[cur][j]!=inf)
			{
				if(dyn[cur][j]>1)
				{
					int ad = 0;
					int have = dyn[cur][j];
					while(have<=mas[i])
					{
						have = 2*have-1;
						++ad;
					}
					if(ad+j < 200)
						dyn[cur^1][ad+j] = max(dyn[cur^1][ad+j],have+mas[i]);
				}
				if(j+1<200)
					dyn[cur^1][j+1] = max(dyn[cur^1][j+1],dyn[cur][j]);
			}
		}
		cur = cur^1;
	}
	int answ = inf;
	for(int j=0; j<sz; ++j)
		if(dyn[cur][j])
		{
			answ = j;
			break;
		}
	printf("Case #%d: %d\n",t,answ);
}

int main()
{
	freopen("a.in","r",stdin);freopen("a.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1; i<=n; ++i)
		test(i);
	return 0;
}