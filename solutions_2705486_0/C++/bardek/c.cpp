#include <cstdio>
#include <algorithm>
#include <vector>

#define fru(j,n) for(int j=0;j<n;++j)
#define tr(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();++it)
#define x first
#define y second

using namespace std;

typedef pair<int,int> pii;
typedef long long LL;

const int MAXN = 4005;
char S[MAXN];
int D[MAXN][5];
FILE *FI;
char P[15];
int Q[15];

int dls,inf=1<<18;

void go(int p)
{
	rewind(FI);
	while(fscanf(FI,"%s",P)!=-1)
	{
		bool ok=1;
		int d=0,qs=0;
		while(P[d])
		{
			if(p+d>=dls)
			{
				ok=0;
				break;
			}
			if(P[d]!=S[p+d])
			{
				if(qs && (d-Q[qs-1]<5)) {ok=0;break;}
				Q[qs++]=d;
			}
			++d;
		}
		if(!ok) continue;
		if(qs==0)
		{
			fru(i,5) if(i>=d)
			{
				D[p][i]=min(D[p][i],D[p+d][i-d]);
			}
			else D[p][i]=min(D[p][i],D[p+d][0]);
		}
		else
		{
			int w=Q[0];
			int h=inf,ile=d-Q[qs-1];
			for(int i=max(5-ile,0);i<5;++i) h=min(h,D[p+d][i]);
			D[p][w]=min(D[p][w],qs+h);
		}
	}
	for(int i=3;i>=0;--i) D[p][i]=min(D[p][i],D[p][i+1]);
}

int solve()
{
	scanf("%s",S);
	dls=0;
	while(S[dls]) ++dls;
	fru(i,dls) fru(j,5) D[i][j]=inf;
	fru(i,5) D[dls][i]=0;

	for(int i=dls-1;i>=0;--i) go(i);
	int ans=inf;
	fru(i,5) ans=min(ans,D[0][i]);
	return ans;
}

int main()
{
	FI=fopen("garbled_email_dictionary.txt","r");
	int o;
	scanf("%d",&o);
	fru(oo,o)
	{
		printf("Case #%d: %d\n",oo+1,solve());
	}
	fclose(FI);
	return 0;
}
