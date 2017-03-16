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

const int MAXN = 105;
LL D[MAXN][MAXN];
LL A[MAXN][2],B[MAXN][2];

int n,m;
struct tri
{
	int typ,end; LL ile;
	tri(int a, LL b, int c) {typ=a;ile=b;end=c;}
};

vector<tri> T;

void dorzuc(int ty,LL il, int dl)
{
	if(T.empty()) T.push_back(tri(ty,il,dl));
	else
	{
		if(T.back().typ==ty)
		{
			T.back().ile+=il;
			T.back().end+=dl;
		}
		else if(dl) T.push_back(tri(ty,il,dl));
	}
}

LL licz()
{
//	printf("T:\n");	tr(it,T) printf("%d %lld %d\n",it->typ,it->ile,it->end);
	LL t=0;
	int p=0;
	tr(it,T)
	{
		fru(i,it->end)
		{
			if(B[p][1]==it->typ)
			{
				LL q=min(it->ile,B[p][0]);
				t+=q;
				it->ile-=q;
			}
			++p;
		}
	}
	return t;
}

LL solve()
{
	scanf("%d%d",&n,&m);
	fru(i,3) A[i][1]=101;
	fru(i,n) fru(j,2) scanf("%lld",&A[i][j]);
	fru(i,m) fru(j,2) scanf("%lld",&B[i][j]);
	LL ans=0;
	fru(i,m+1) fru(j,m+1-i)
	{
		T.clear();
		dorzuc(A[0][1],A[0][0],i);
		dorzuc(A[1][1],A[1][0],j);
		dorzuc(A[2][1],A[2][0],m-i-j);
		ans=max(ans,licz());		
	}
	return ans;
}

int main()
{
	int o;
	scanf("%d",&o);
	fru(oo,o)
	{
		 printf("Case #%d: %lld\n",oo+1,solve());


	}
    return 0;
}
