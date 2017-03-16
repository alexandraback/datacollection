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

const int MAXN = 101;
int A[MAXN];
int solve()
{
	int n;
	LL a;
	scanf("%lld%d",&a,&n);
	fru(i,n) scanf("%d",&A[i]);
	if(a==1) return n;
	int ans=55;
	sort(A,A+n);
	int juz=0;
	fru(i,n)
	{
		if(A[i]>=a) ans=min(ans,juz+n-i);
		while(A[i]>=a)
		{
			a+=a-1;
			juz++;
		}
		a+=A[i];
	}
	ans=min(ans,juz);
	return ans;

}

int main()
{
	int o;
	scanf("%d",&o);
	fru(oo,o)
	{
		 printf("Case #%d: ",oo+1);
		 printf("%d\n",solve());
	}
    return 0;
}
