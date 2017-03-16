#include<cstdio>
#define ll long long

ll a[30];

ll MIN(ll a,ll b){return a<b?a:b;}

ll Fun(ll n,ll m)
{
	ll k1,k2,l,i,k3;
	for(i=1;i*i<n;i*=10);
	if(!(n%i))
	{
		n=n-i+1;
		if(n<m)return m*10;
		k3=i-1;
	}
	else k3=0;
	for(l=0;n;n/=10)a[l++]=n%10;
	for(k1=0,i=l/2;i<l;i++)k1=k1*10+a[i];
	for(k2=0,i=l/2-1;i>=0;i--)k2=k2*10+a[i];
	return k1+k2+k3;
}

int main()
{
	int Case,TestCase;
	ll Ans,n,m,k;
	//freopen("a.in","rb",stdin);
	//freopen("a.out","wb",stdout);
	scanf("%d",&TestCase);
	for(Case=1;Case<=TestCase;Case++)
	{
		scanf("%I64d",&n);
		Ans=1;
		for(m=1;m*10ll<=n;m*=10)
		if(m==1)Ans+=9;
		else
		{
			for(k=1;k*k<m;k*=10);
			Ans+=k;
			if(k*k==m*10)
				Ans+=k-1;
			else
				Ans+=k*10-1;
		}
		Ans+=MIN(Fun(n,m),n-m);
		printf("Case #%d: %I64d\n",Case,Ans);
	}
	return 0;
}
