#include<iostream>
using namespace std;
int main()
{	int t,i,x,y,cx,cy,j;
	cin>>t;
	for(i=1;i<=t;i++)
	{	cin>>x>>y;
		cx=cy=0;
		j=1;
		cout<<"Case #"<<i<<": ";
		while(cx!=x)
		{	if(cx<x)
			{	cx+=j;
				cout<<"E";	
			}
			else
			{	cx+=j;
				j++;
				cx-=j;
				cout<<"EW";
			}
			j++;
		}
		while(cy!=y)
		{	if(cy<y)
			{	cy+=j;
				cout<<"N";	
			}
			else
			{	cy+=j;
				j++;
				cy-=j;
				cout<<"NS";
			}
			j++;
		}
		cout<<endl;
	}
	return 0;
}