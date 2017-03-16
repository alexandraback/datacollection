#include<iostream>
using namespace std;
string s;
long long cum[1000010],ans[1000010];

int isvowel(char x)
{
	if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u')
		return 0;
	return 1;
}

int main()
{
	int t;
	int p=1;
	cin>>t;
	while(t--)
	{
		int n;
		long long sum=0;
		cin>>s;
		cin>>n;
		int len=s.length();
	
		for(int i=0;i<len;i++) cum[i]=ans[i]=0;
		cum[0]=isvowel(s[0]);		
				
		for(int i=1;i<len;i++)
		{					
				if(isvowel(s[i])==0)
				  cum[i]=0;
				else 	
					cum[i]=cum[i-1]+1;
				//cout<<cum[i]<<" ";
		}
		//cout<<"\n";
		int flag=0;
		for(int i=0;i<len;i++)
		{
			if(cum[i]>=n)
			{
				ans[i]=i-n+2;
				flag=1;		
			}		
			else if(flag==1)
			{
				ans[i]=ans[i-1];
			}	
			//cout<<i<<" "<<cum[i]<<" "<<ans[i]<<"\n";
		}
		//cout<<"\n";		
		for(int i=0;i<len;i++)
		  sum+=ans[i];
		  
		printf("Case #%d: %lld\n",p,sum);
		p++;
	}
}
