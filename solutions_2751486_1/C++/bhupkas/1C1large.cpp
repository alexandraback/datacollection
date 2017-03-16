#include"iostream"
#include"stdio.h"
#include"string.h"
#include"string"
#include"vector"
#include"algorithm"
#include"math.h"
using namespace std;
#define FOR(i,a,b)	for(i=a;i<b;i++)
int main()
	{
		int TC,i,j,k,t,n,l,ans=0,co=0;
		cin>>t;
		char S[1000009];
		FOR(TC,1,t+1)
			{
				getchar();
				scanf("%s",S);
				cin>>n;
				l=strlen(S);
				j=0;
				ans=0;
				i=0;
				co=0;
				if(!(S[j]=='a'||S[j]=='i'||S[j]=='o'||S[j]=='e'||S[j]=='u'))
					{
						j++;
						co++;
					}
					while(j<l && co<n)
					{
						if(!(S[j]=='a'||S[j]=='i'||S[j]=='o'||S[j]=='e'||S[j]=='u'))
							co++;
						else
							co=0;
						j++;
					}
						if(co==n)
					ans=ans+l-j+1;
				while(j<l)
				{
					ans+=j-n-i;
					if(i==j-n)
					{
						co--;
						i=j-n+1;
					}
					else
						i=j-n;
					while(j<l && co<n)
					{
						if(!(S[j]=='a'||S[j]=='i'||S[j]=='o'||S[j]=='e'||S[j]=='u'))
							co++;
						else
							co=0;
						j++;
						if(co==n)
							j--;
					}
					ans+=l-j;
					j++;
				}
				ans+=j-n-i;
				cout<<"Case #"<<TC<<": "<<ans<<endl;
			}
		return 0;
	}