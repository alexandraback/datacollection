#include <stdio.h>

const long long P = 1000000007;
long long f[150];

int main()
{
	long long tc,t,r=0;
	f[0]=1;
	for (int i=1;i<150;++i) f[i]=(i*f[i-1])%P;
	scanf("%lld\n",&t);
	for (tc=0;tc<t;++tc)
	{
		int n;
		long long r=1;
		char s[120];
		int x['z'+1];
		int y['z'+1];
		int q[150];
		int w[150];
		int qw=0;
		for (int i='a';i<='z';++i) x[i]=y[i]=0;
		scanf("%d",&n);
		for (int i=0;i<n;++i)
		{
			scanf("%s",s);
			int j,k;
			char a,b;
			a=s[0];
			j=1;
			while (s[j]==a) ++j;
			k=j;
			while (s[k]) ++k;
			if (k==j)
			{
				++x[a];
			} else
			{
				--k;
				b=s[k];
				while (s[k]==b) --k;
				q[qw]=a;
				w[qw]=b;
				++qw;
				for (int ii=j;ii<=k;++ii) y[s[ii]]=1;
			}
		}
		for (int i=0;i<qw;++i) if (x[q[i]])
		{
			n-=x[q[i]];
			r=(r*f[x[q[i]]])%P;
			x[q[i]]=0;
		}
		for (int i=0;i<qw;++i) if (x[w[i]])
		{
			n-=x[w[i]];
			r=(r*f[x[w[i]]])%P;
			x[w[i]]=0;
		}
		for (int i='a';i<='z';++i) if (x[i])
		{
			n=n-x[i]+1;
			r=(r*f[x[i]])%P;
			x[i]=0;
		}
		for (int i=0;i<qw;++i) for (int j=i+1;j<qw;++j) if (q[i]==q[j] || w[i]==w[j]) r=0;
		while (1)
		{
			int found=0;
			for (int i=0;i<qw;++i) for (int j=0;j<qw;++j) if (i!=j && w[i]==q[j])
			{
				found=1;
				y[w[i]]=1;
				w[i]=w[j];
				--qw;
				q[j]=q[qw];
				w[j]=w[qw];
				--n;
			}
			if (!found) break;
		}
		for (int i='a';i<='z';++i) if (x[i] && y[i]) r=0;
		for (int i=0;i<qw;++i) if (y[q[i]] || y[w[i]]) r=0;
		for (int i=0;i<qw;++i) if (q[i]==w[i]) r=0;
		r=(r*f[n])%P;
		printf("Case #%lld: %lld\n",tc+1,r);
	}
	return 0;
}
