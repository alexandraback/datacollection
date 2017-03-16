#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll t,i,j;
	FILE * pFile;
	pFile = fopen ("output.txt","w");
	cin>>t;
	string str1,str2,ans1,ans2;
	ll cc=0;
	while(t--)
	{
		ans1="";
		ans2="";
		cc++;
		fprintf (pFile, "Case #%lld: ",cc);
	ll flag1=0;
	ll flag2=0;
		cin>>str1>>str2;
		ll n1=str1.size();
		ll n2=str2.size();
		for(i=0;i<n1;i++)
		{
			if(flag1==0 && flag2==0)
			{
			
				if(str1[i]=='?' && str2[i]=='?')
				{
					ans1+='0';
					ans2+='0';
				}
				else if(str1[i]=='?' && str2[i]!='?')
				{
					ans1+=str2[i];
					ans2+=str2[i];
				}
				else if(str2[i]=='?' && str1[i]!='?')
				{
					ans1+=str1[i];
					ans2+=str1[i];
				}
				else
				{
					if(str1[i]>str2[i])
					{
						flag1==1;
						
					}
					else if(str1[i]<str2[i])
					{
						flag2=1;
					}
					ans1+=str1[i];
					ans2+=str2[i];
				}
			}
			else if(flag1==1)
			{
				if(str1[i]=='?' && str2[i]=='?')
				{
					ans1+='0';
					ans2+='9';
				}
				else if(str1[i]=='?' && str2[i]!='?')
				{
					ans1+='0';
					ans2+=str2[i];
				}
				else if(str2[i]=='?' && str1[i]!='?')
				{
					ans1+=str1[i];
					ans2+='9';
				}
			}
			else if(flag2==1)
			{
				if(str1[i]=='?' && str2[i]=='?')
				{
					ans1+='9';
					ans2+='0';
				}
				else if(str1[i]=='?' && str2[i]!='?')
				{
					ans1+='9';
					ans2+=str2[i];
				}
				else if(str2[i]=='?' && str1[i]!='?')
				{
					ans1+=str1[i];
					ans2+='0';
				}
			}
		}
		ll k=0;
		char str[10000];
		for(i=0;i<ans1.size();i++)
		{
			str[k++]=ans1[i];
		}
		str[k++]='\0';
		fprintf (pFile, "%s ",str);
		k=0;
		for(i=0;i<ans2.size();i++)
		{
			str[k++]=ans2[i];
		}
		str[k++]='\0';
		fprintf (pFile, "%s",str);
		fprintf (pFile, "\n");
		//cout<<ans1<<" "<<ans2<<endl;
	}
}
