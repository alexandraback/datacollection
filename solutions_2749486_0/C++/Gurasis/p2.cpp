#include<iostream>
using namespace std;
int main()
{int x,y,t,m;
cin>>t;
for(m=0;m<t;m++)
	{cin>>x;
	cin>>y;
	int i;
	cout<<"Case #"<<m+1<<": ";
	if(x<0)
		{x=x*-1;
		for(i=0;i<x;i++)
			{cout<<"EW";
			
			}
		
		x=x*-1;}
	if(x>0)
		{for(i=0;i<x;i++)
			{cout<<"WE";
			}
		}
	if(y>0)
		{for(i=0;i<y;i++)
			{cout<<"SN";}
		
		}	

	else if(y<0)
		{y=y*-1;
		for(i=0;i<y;i++)
			{cout<<"NS";}
		}
cout<<endl;
}


}
