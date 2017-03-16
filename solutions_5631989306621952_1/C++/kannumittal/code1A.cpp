#include<bits/stdc++.h>
#define f_in(st) freopen(st,"r",stdin);
#define f_out(st) freopen(st,"w",stdout);
using namespace std;
int main()
{
	f_in("large1a.in");
	f_out("large1aout.txt")
	long long t,i,j,k;
	char temp,temp1;
	char s[1003];
	
	cin>>t;
	getchar();
	j=0;
	while(t--)
	{
		char ans[1003];
		j++;
		cin>>s;
		int len=strlen(s);
		cout<<"Case #"<<j<<": ";
		k=0;
		for(i=0;i<len;i++)
		{
			//cout<<s[i]<<" ";
			if(k==0)
			{
				ans[0]=s[i];
				k++;
				//cout<<ans[0]<<" ";
			}
			else
			{
			
				if(ans[0]<=s[i])
				{
					temp=ans[0];
					ans[0]=s[i];
					k++;
					for(int m=1;m<k;m++)
					{
						temp1=ans[m];
						ans[m]=temp;
						temp=temp1;
					}
				}
				else
				{
					ans[k]=s[i];
					
					k++;
				}
			}
			
	    }
		for(i=0;i<k;i++)
		{
			cout<<ans[i];
		}
		cout<<endl;
	}
	return 0;
}
