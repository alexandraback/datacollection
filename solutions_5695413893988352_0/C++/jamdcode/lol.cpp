#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll t,i,j;
	FILE * pFile;
	pFile = fopen ("output.txt","w");
	cin>>t;
	string str1,str2;
	ll cc=0;
	while(t--)
	{
		cc++;
		
		ll ans1=0;
		ll ans2=0;
		ll mini=999999999999LL;
		cin>>str1>>str2;
		ll n1=str1.size();
		ll n2=str2.size();
		ll num1=1;
		for(i=0;i<n1;i++)
		{
			num1*=10;
		}
		ll num2=1;
		for(i=0;i<n2;i++)
		{
			num2*=10;
		}
		//cout<<num1<<" "<<num2<<endl;
		for(i=0;i<num1;i++)
		{
			//cout<<i<<endl;
			ll kk=n1-1;
			ll flag=0;
			ll sss=i;
			while(kk>=0)
			{
				ll d=sss%10;
				sss/=10;
				if(!(str1[kk]=='?' || (int(str1[kk]-'0')==d)))
				{
					flag=1;
					break;
				}
				kk--;
			}
		
			if(flag==0)
			for(j=0;j<num2;j++)
			{
				//cout<<i<<endl;
				ll kk=n2-1;
				ll flag=0;
				ll sss=j;
				while(kk>=0)
				{
					ll d=sss%10;
					sss/=10;
					if(!(str2[kk]=='?' || (int(str2[kk]-'0')==d)))
					{
						flag=1;
						break;
					}
					kk--;
				}
				if(flag==0)
				{
					//cout<<i<<" "<<j<<endl;
					if(abs(i-j)<mini)
					{
						mini=abs(i-j);
						ans1=i;
						ans2=j;
					}
				}				
			}
		}
		ll count=0;
		ll ssp=ans1;
		while(ans1)
		{
			count+=1;
			ans1/=10;
		}
		if(ssp==0)
		count=1;
		fprintf (pFile, "Case #%lld: ",cc);
		if(count<n1)
		{
			for(i=0;i<(n1-count);i++)
			{
					fprintf (pFile, "0");
			}
		}
			fprintf (pFile, "%lld ",ssp);
			count=0;
		ll spp=ans2;
		while(ans2)
		{
			count+=1;
			ans2/=10;
		}
		if(spp==0)
		count=1;
		if(count<n2)
		{
			for(i=0;i<(n2-count);i++)
			{
				fprintf (pFile, "0");
			}
		}
		fprintf (pFile, "%lld\n",spp);
	}
}
