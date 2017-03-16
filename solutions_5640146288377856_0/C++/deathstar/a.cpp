#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t,i,j,k,w,r,c;
	freopen("output.txt","w",stdout);
	freopen("input.txt","r",stdin);
	cin>>t;
	
	for(int g=1;g<=t;g++)
	{
		printf("Case #%d: ",g);
		cin>>r>>c>>w;
		if(w==1)
		{
			cout<<r*c<<endl;
		}
		else if(w==c)
		{
			cout<<r+w-1<<endl;
		}
		else
		{
			if(w>c/2)
			cout<<r+w<<endl;
			
			else
			{
			
			int k=0;
			for(i=w-1;i<c;i+=w)
			k+=r;
			if(i-w==c-1)
			k+=w-1;
			else if(c-(i-w)>0)
			k+=w;
			
			cout<<k<<endl;
			}
		}
	}
return 0;
}
