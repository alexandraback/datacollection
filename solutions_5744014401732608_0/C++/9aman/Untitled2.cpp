#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int B[100][100];
void reset()
{
	for(int i=0;i<100;i++)
	{
		for(int j = 0;j<100;j++)
		B[i][j] = 0;
	}
}
int main()
{
	int t , p = 0 , b , m;
		freopen("B-small-attempt0.in" , "r",stdin);
	freopen("ut2.out","w",stdout);
	cin>>t;

	while(t--)
	{
		reset();
		int flag = 0;
		p++;
		cin>>b>>m;
		cout<<"Case #"<<p<<": ";
		if(((b-2)*(b-1))/2 + 1 < m)
		cout<<"IMPOSSIBLE"<<endl;
		else
		{
			cout<<"POSSIBLE"<<endl;
				for(int i=0;i<b;i++)
				{
					for(int j=0;j<b;j++)
					{
						if(m)
						{	if(i!=j)
						     {
						     	B[i][j] = 1;
						     	if(j != b-1)
						     	B[j][b-1] = 1;
						     	m--;
						     }
					    }
						else
						flag = 1;
					}
					if(flag)
					break;
				}
				for(int i =0 ;i<b;i++)
		{
		for(int j = 0;j<b;j++)
		{
			cout<<B[i][j];
		}
		cout<<endl;
	    }
		}
	}
}
