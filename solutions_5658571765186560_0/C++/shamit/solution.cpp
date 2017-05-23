#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,i,j,ii,x,r,c,te;
	scanf("%d",&t);
	/*for(ii=1;ii<=t;ii++)
	{
		scanf("%d",&d);
		for(i=0;i<d;i++)
			scanf("%d",&arr[i]);
		sort(arr,arr+d);
		
	}*/
	for(ii=1;ii<=t;ii++)
	{
		scanf("%d%d%d",&x,&r,&c);
		if(x==1)
			cout<<"Case #"<<ii<<": "<<"GABRIEL\n";
		else if(x==2)
		{
			if((r*c)%2==0)
				cout<<"Case #"<<ii<<": "<<"GABRIEL\n";
			else cout<<"Case #"<<ii<<": "<<"RICHARD\n";
		}
		else if(x==3)
		{
			te=r*c;
			if(te==6 || te==9 || te==12 || te==15)
				cout<<"Case #"<<ii<<": "<<"GABRIEL\n";
			else
				cout<<"Case #"<<ii<<": "<<"RICHARD\n";
		}
		else
		{
			te=r*c;
			if(te==12 || te==16)
				cout<<"Case #"<<ii<<": "<<"GABRIEL\n";
			else
				cout<<"Case #"<<ii<<": "<<"RICHARD\n";
		}
	}
}
