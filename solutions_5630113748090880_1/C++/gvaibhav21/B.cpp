#include<bits/stdc++.h>
using namespace std;

#define sd(a) scanf("%d",&a)
#define ss(a) scanf("%s",&a)
#define sl(a) scanf("%lld",&a)
#define clr(a) memset(a,0,sizeof(a))
#define debug(a) printf("check%d\n",a)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define ll long long
int List[110][110];
int f[10010];
int main()
{
	//freopen("B_2.in","r",stdin);
	//freopen("B_2.out","w",stdout);
	int t,i,j,k,n;
	sd(t);
	for(int tt=1;tt<=t;tt++)
	{
		sd(n);
		clr(f);
		for(i=0;i<2*n-1;++i)
		{
			for(j=0;j<n;++j)
			{
				sd(List[i][j]);
				f[List[i][j]]++;
			}
		}
		vector<int> v;
		v.clear();
		for(i=0;i<=2500;++i)
			if(f[i]%2==1)
				v.PB(i);
		printf("Case #%d: ",tt);
		for(i=0;i<n;++i)
			printf("%d ",v[i]);
		printf("\n");
	}
}