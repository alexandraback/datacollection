#include <iostream>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	int te;
	cin>>te;
	for (int t = 1; t <=te ; t++)
	{
		int n, m, v;
		cin>>n>>m>>v;
		
		int rem = n*m-v;
		int possible=1;
		
		int arr[n][m];
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
				arr[i][j]=0;
		}
		
		if(rem==1)
		{
			;
		}
		else if(n==1 || m==1)
		{
			if(n==1)
			{
				if(rem>=2)
				{
					for(int i=0; i<rem; i++)
						arr[0][i]=1;
				}
				else 
					possible = 0;
			}
			else
			{
				if(rem>=2)
				{
					for(int i=0; i<rem; i++)
						arr[i][0]=1;
				}
				else 
					possible = 0;
			}
		}
		else if(n==2 || m==2)
		{
			if(rem%2==0)
			{
				if(n==2)
				{
					if(rem >= 4)
					{
						for(int i=0; i<rem/2; i++)
						{
							arr[0][i]=arr[1][i]=1;
						}
					}
					else possible=0;
				}
				else if(m==2)
				{
					if(rem >= 4)
					{
						for(int i=0; i<rem/2; i++)
						{
							arr[i][0]=arr[i][1]=1;
						}
					}
					else possible=0;
				}
			}
			else possible=0;
		}
		else 		// the general case is handled here
		{
			if(rem==4)
			{
				for(int i=0; i<2; i++)
				{
					for(int j=0; j<2; j++)
						arr[i][j]=1;
				}
			}
			else if(rem==6)
			{
				for(int i=0; i<3; i++)
				{
					for(int j=0; j<2; j++)
						arr[i][j]=1;
				}
			}
			else if(rem>=8)
			{
				for(int i=0; i<3; i++)
				{
					for(int j=0; j<2; j++)
						arr[i][j]=1;
				}
				
				rem-=6;
				// six filled
				// start with filling the 0, 1 rows
				for(int i=2; i<m; i++)
				{
					if(rem<2)
						break;
					else 
					{
						arr[0][i]=arr[1][i]=1;
						rem-=2;
					}
				}
				
				// lower filled
				// now the upper ones if possible
				for(int i=3; i<n; i++)
				{
					if(rem<2)
						break;
					else
					{
						arr[i][0]=arr[i][1]=1;
						rem-=2;
					}
				}
				
				// now the remaining is filled one by one
				for(int i=2; i<n; i++)
				{
					if(rem==0)
						break;
					for(int j=2; j<m; j++)
					{
						if(rem==0)
							break;
						else 
						{
							arr[i][j]=1;
							rem--;
						}
					}
				}
			}
			else
			{
				possible=0;
			}
		}
		cout<<"Case #"<<t<<":"<<endl;
		if(possible==0)
		{
			cout<<"Impossible"<<endl;
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				for(int j=0; j<m; j++)
				{
					if(i==0 && j==0)
						cout<<"c";
					else if(arr[i][j]==0)
						cout<<"*";
					else cout<<".";
				}
				cout<<endl;	
			}
			
		}
	}
	
}
