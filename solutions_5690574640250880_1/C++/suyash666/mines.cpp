
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(i=a;i<b;i++)
#define vi vector<int>

int main()
{
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	int i,j,k;
	int grid[51][51];
	FOR(i,1,t+1)
	{
		memset(grid,0,sizeof(grid));
		int r,c,m;		
		cin>>r>>c>>m;
		cout<<"Case #"<<i<<":"<<endl;
		int e = r*c-m;
		if(r==1 || c==1 ||e==1)
		{
			int cnt=0;
			FOR(j,0,r)
			{
				FOR(k,0,c)
				{
					if(cnt==0)
						cout<<'c';
					else if(cnt<e)
						cout<<'.';
					else
						cout<<'*';
					cnt++;
				}
				cout<<endl;
			}		
			continue;		
		}
		bool flag=false;
		if(e%2==1)
		{
			flag=true;
			if(e<9 || r==2 || c==2)
			{
				cout<<"Impossible"<<endl;
				continue;
			}
			e-=3;
		}
		if(e<4)
		{
			cout<<"Impossible"<<endl;
			continue;
		}
		int nr = e/(2*c);
		FOR(j,0,2*nr)
			FOR(k,0,c)
				grid[j][k]=1;
		e-=(2*nr*c);
		int r1=2*nr;
		int r2=2*nr+1;
		bool done=false;
		if(r2==r)
		{
			if(flag)
			e+=3;
			FOR(j,0,e)
				grid[r1][j]=1;
			done=true;		
		}
		if(!done)
		{
			bool state=false;
			if(e==2)
			{
				state=true;
				e=0;
				grid[r1][0]=1;
				grid[r1][1]=1;
			}
			int c1=0;
			while(c1<c && e>0)
			{
				grid[r1][c1]=1;
				grid[r2][c1]=1;
				c1++;
				e-=2;
			}
			if(flag)
			{
				if(state)
				{
					grid[r1][2]=1;
					if(c>4)
					{
						grid[r1][3]=1;
						grid[r1][4]=1;
					}
					else
					{
						grid[r2][0]=1;
						grid[r2][1]=1;
					}
				}
				else
				{
					int s=3;
					if(c1<c-1)
					{				
						if(c1==0)
							r2-=2;
						if(nr>0 && c1>0)
						{
							grid[r1][c1]=1;
							grid[r1][c1+1]=1;
							grid[r2][c1]=1;
						}
						else
						{
							FOR(j,0,3)
								grid[r2+1][j]=1;
						}
					}
					else if(c1==c-1)
					{
						int cnt=0;
						if(nr>0)
						{
							grid[r1][c1]=1;
							cnt++;
						}
						FOR(j,0,3-cnt)
							grid[r2+1][j]=1;
					}	
					else
					{
						FOR(j,0,3)
							grid[r2+1][j]=1;
					}
				}				
			}	
		}
		grid[0][0]=2;
		FOR(j,0,r)
		{
			FOR(k,0,c)
			{
				if(grid[j][k]==2)
					cout<<'c';
				else if(grid[j][k]==1)
					cout<<'.';
				else
					cout<<'*';
			}
			cout<<endl;
		}			
	}
				
	return 0;
}
	
