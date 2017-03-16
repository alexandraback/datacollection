#include <iostream>
using namespace std;

int main()
{
	int T,t=1,i,C,D,V,denom[100],checking,ans;
	bool finished;
	cin>>T;
	while(t<=T)
	{
		ans=0;
		cin>>C>>D>>V;
		for(i=0;i<D;i++)
			cin>>denom[i];
		if(D!=0)
			finished=false;
		i=0;
		checking=1;
		while(checking<=V)
		{
			if(!finished)
			{			
				while(denom[i]<checking)
				{
					checking = (C+1)*denom[i];
					i++;
					if(checking>V)
						break;
				}
				if(checking>V)
					break;
				if(denom[i]!=checking)
				{
					ans+=1;
				}
				else
				{
					i++;
					if(i==D)
						finished=true;
				}	
				checking = (C+1)*checking;
			}
			else
			{
				ans+=1;
				checking = (C+1)*checking;
			}
		}
		cout<<"Case #"<<t<<": "<<ans<<endl;
		t++;
	}
	return 0;
}
