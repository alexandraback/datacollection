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
typedef double D;

const int MAXN = 1001;

pii P[22];

LL sum(int s)
{
	return 1LL*(s+1)*(s+2)/2;
}
D licz(int k, int n)
{
	D t=1.0;
	if(k==0) 
	{
		fru(i,n) t/=2.0;
		return t;
	}
	int d=n/k;
	fru(i,k)
	{
		D e=1.0*(n-i)/(i+1);
		fru(j,d) e/=2.0;
		t*=e;
	}
	fru(i,n%k) t/=2.0;
	return t;
}

D DP[1002][1002];

D solve()
{
int n,X,Y;
	scanf("%d%d%d",&n,&X,&Y);
	X=abs(X);
	int s=X+Y;
	if(s==0) return 1.0;
	if(n>=sum(s)) return 1.0;
	if(n<=sum(s-2)) return 0.0;
	if(X==0) return 0.0;
	n-=sum(s-2);
//	if(n>s+1) return 1.0;
	fru(i,s+1) fru(j,s+1) DP[i][j]=0.0;
	DP[0][0]=1.0;
	fru(i,n) 
	{
		fru(a,s+1) 
		{
			int b=i-a;
			if(b>=0)
			{
				D q=DP[a][b];
				if(a==s)
				{
					DP[a][b+1]+=q;
				}
				else if(b==s)
				{
					DP[a+1][b]+=q;
				}
				else
				{
					DP[a+1][b]+=q/2.0;
					DP[a][b+1]+=q/2.0;
				}
			}
		}
	}
//	printf("n = %d\n",n);	fru(i,s+1) fru(j,s+1) printf("D[%d,%d] = %.2lf\n",i,j,DP[i][j]);
	D ans=0.0;
	for(int i=Y+1;i<=s;++i) if(n-i<=s && n-i>=0) 
	{
		ans+=DP[i][n-i];
//		printf("dodaje DP[%d,%d] = %.2lf\n",i,n-i,DP[i][n-i]);
	}
	return ans;
}

int main()
{
	int o;
	scanf("%d",&o);
	fru(oo,o)
	{
		 printf("Case #%d: %.6lf\n",oo+1,solve());
	}
    return 0;
}
