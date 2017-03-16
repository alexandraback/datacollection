#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char ss[2000];
int main()
{
	ll t,i;
	string str;
	cin>>t;
	FILE * pFile;
	pFile = fopen ("output.txt","w");
	ll c=0;
	while(t--)
	{
		c++;
		string s="";
		cin>>str;
		ll n=str.size();
		for(i=0;i<n;i++)
		{
			if(i==0)
			s+=str[i];
			else
			{
				if(int(str[i])>=int(s[0]))
				{
					s=str[i]+s;
				}
				else
				{
					s+=str[i];
				}
			}
		}
		ll k=0;
		for(i=0;i<s.size();i++)
		{
			ss[k++]=s[i];
		}
		ss[k++]='\0';
		fprintf (pFile, "Case #%lld: %s\n",c,ss);
	}
}
