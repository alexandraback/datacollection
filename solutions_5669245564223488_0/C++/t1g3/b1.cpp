#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define mod 1000000007

char a[1005][105],la[30];
long long int b[1005][30],a1[30];

int main() 
{
	long long int i,j,k,n,t,ca=0,ans;
	char ch;
	bool flag;
	scanf("%lld",&t);
	while(t--)
	{
		++ca;
		scanf("%lld",&n);
		for(i=0;i<n;++i)
		{
			scanf("%s",a[i]);
			for(j=0;j<26;++j)
			{
				b[i][j]=0;
			}
		}
		for(i=0;i<n;++i)
		{
			++b[i][a[i][0]-'a'];
			for(j=1;a[i][j];++j)
			{
				ch=a[i][j];
				if(b[i][ch-'a'] && ch!=a[i][j-1]) break;
				++b[i][ch-'a'];
			}
			if(a[i][j]){break;}
		}
		if(i!=n)
		{
			printf("Case #%lld: 0\n",ca);
		}
		else
		{
			for(i=0;i<n;++i)
			{
				for(j=i+1;j<n;++j)
				{
					flag=false;
					for(k=0;k<26;++k)
					{
						if(b[i][k]!=0 && b[j][k]!=0 && b[i][k]==b[j][k])
						{
							if(flag)
							{
								break;
							}
							else
							{
								flag=true;
							}
						}
					}
					if(k<26) break;
				}
				if(j<n) break;
			}
			if(i<n)
			{
				printf("Case #%lld: 0\n",ca);
			}
			else
			{
				for(i=0;i<26;++i)
				{
					a1[i]=-1;
				}
				for(i=0;i<26;++i)
				{
					k=0; la[i]='a'+i; 
					for(j=0;j<n;++j)
					{
						if(a[j][0]=='a'+i)
						{
							++k;
							if(a[j][strlen(a[j])-1]!=a[j][0])
							{
								la[i]=a[j][strlen(a[j])-1];
							}
						}
					}
					if(k)
					{
						a1[i]=1; 
						if(la[i]!='a'+i) k=k-1;
						for(j=2;j<=k;++j)
						{
							a1[i]=(a1[i]*j)%mod;
						}
					}
				}
				for(i=0;i<26;++i)
				{
					while(a1[i]!=-1 && la[i]!='a'+i && a1[la[i]-'a']!=-1)
					{
						a1[i]=(a1[i]*a1[la[i]-'a'])%mod;
						a1[la[i]-'a']=-1;
						la[i]=la[la[i]-'a'];
					}
				}
				ans=1; k=0;
				for(i=0;i<26;++i)
				{
					if(a1[i]!=-1)
					{
						ans=(ans*a1[i])%mod;
						++k;
					}
				}
				for(k;k>1;--k)
				{
					ans=(ans*k)%mod;
				}
				printf("Case #%lld: %lld\n",ca,ans);
			}
			
		}
		
	}
	return 0;
}
