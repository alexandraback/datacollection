#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <string>
#define uint long long int
#define MAXN 1005
#define MAXM 15005
#define MP make_pair
using namespace std;
char odp[MAXM];
int tmp[MAXM];
pair<int, int> dp[MAXN][MAXN];
char r[4]={'W', 'N', 'E', 'S'};
int dp2[MAXM];
bool rek(int x, int y, int n, int gl)
{
	int tmpx = 0;
	int tmpy = 0;
	if(gl==n)
	{
		for (int i = 1; i <= n; i++)
		{
			if(tmp[i] == 'N')
			{
				tmpy+=i;
			}
			if(tmp[i]=='W')
			{
				tmpx -= i;
			}
			if(tmp[i]=='S')
			{
				tmpy-=i;
			}
			if(tmp[i]=='E')
			{
				tmpx+=i;
			}
		}
		if(tmpx==x && tmpy==y)
		{
			for (int i = 1; i<=n; i++)
			{
				odp[i] = tmp[i];
			}
			return true;
		}
		return false;
	}
	bool odpo = false;
	for (int i = 0; i < 4; i++)
	{
		tmp[gl+1]=r[i];
		odpo |= rek(x, y, n, gl+1);
	}
	return odpo;
}
	
bool tryn(int x, int y, int n)
{
	if (abs(x)+abs(y) > n*(n+1)/2 || (abs(x)+abs(y))%2 != (n*(n+1)/2)%2)
	{
		return false;
	}
	int zx=0, zy=0;
	if (n<=6)
	{
		//cout<<n<<endl;
		return rek(x, y, n, 0);
	}
	if (x<0)
	{
		x = -x;
		zx = 1;
	}
	if (y<0)
	{
		y = -y;
		zy = 1;
	}
	/* bool git = rek2(x, y, 5, n, 0);
	if (git)
	{
		for (int i = 1; i <= n; i++)
		{ */
	int cof = (n*(n+1)/2 - x - y)/2;
	int odw = 0;
	if (x>y)
	{
		odw = 1;
		swap(x, y);
	}
	int akt;
	int ind = n;
	if(x==1 && cof==1)
	{
		odp[1]='W';
		odp[2]='E';
		for (int i = 3; i<=n; i++)
		{
			odp[i]='N';
		}
		goto A;
	}
	if(x==2 && cof==2)
	{
		odp[2]='W';
		odp[4]='E';
		odp[1]='N';
		odp[3]='N';
		for (int i = 5; i<=n; i++)
		{
			odp[i]='N';
		}
		goto A;
	}
	for (int i = 1; i<=n; i++)
	{
		odp[i]='i';
	}
	
	while(ind>=1)
	{
		if(x-ind<0)
		{
			ind--;
			continue;
		}
		if(x-ind >=min(n, MAXN))
		{
			odp[ind]='E';
			x-=ind;
			ind--;
			
			continue;
		}
		else
		{
			if( (x-ind==1 && cof ==1) || (x-ind == 2 && cof==2))
			{
				ind--;
				continue;
			}
			else
			{
				odp[ind]='E';
				x-=ind;
				ind--;
				
			}
		}
	}
	for (int i = 0; i<=MAXM-2; i++)
	{
		dp2[i]=-1;
	}
	/* for(int i = 1; i<=n; i++)
	{
		cout<<odp[i];
	}
	cout<<endl;
	cout<<"hehe "<<x<<" "<<cof<<endl; */
	if(cof)
	{
	dp2[0]=0;
	for(int i = 1; ; i++)
	{
		if(odp[i]=='i')
		{
			for(int j = cof; j>=0; j--)
			{
				if(dp2[j]>=0)
				{
					dp2[i+j]=j;
					if(i+j==cof)
					{
						goto B;
					}
				}
			}
		}
	}
	}
	B: ;
	//cout<<"no tu"<<endl;
	akt=cof;
	while(akt)
	{
		odp[akt-dp2[akt]]='S';
		akt=dp2[akt];
	}
	for(int i = 1; i<=n; i++)
	{
		if(odp[i]=='i')
		{
			odp[i]='N';
		}
	}
				
	
	
	
	
	A: ;
	for (int i = 1; i<=n; i++)
	{
		if(odw)
		{
			if(odp[i]=='W')
			{
				odp[i]='S';
			}
			else
			{
				if(odp[i]=='S')
				{
					odp[i]='W';
				}
				else
				{
					if(odp[i]=='E')
					{
						odp[i]='N';
					}
					else
					{
						odp[i]='E';
					}
				}
			}
		}
		if(zx==1)
		{
			if(odp[i]=='W')
			{
				odp[i]='E';
			}
			else
			{
				if(odp[i]=='E')
				{
					odp[i]='W';
				}
			}
		}
		if(zy==1)
		{
			if(odp[i]=='S')
			{
				odp[i]='N';
			}
			else
			{
				if(odp[i]=='N')
				{
					odp[i]='S';
				}
			}
		}
	}
	return true;
}
	
	
	
int main()
{
	ios_base::sync_with_stdio(0);
	
	/* for (int i = 0; i<=MAXN-2; i++)
	{
		for (int j = 0; j<=MAXN-2; j++)
		{
			dp[i][j] = MP(-1, -1);
		}
	}
	dp[0][0] = MP(0, 0);
	for (int s = 1; s<=MAXN-2; s++)
	{
		for(int i=0; i<=MAXN-2; i++)
		{
			for(int j = 0; j<=MAXN-2; j++)
			{
				if(dp[i][j]!=MP(-1, -1))
				{
					if(i+s<=MAXN-2 && dp[i+s][j]==MP(-1, -1))
					{
						dp[i+s][j]=MP(i, j);
					}
					if(j+s<=MAXN-2 && dp[j+s][i]==MP(-1, -1))
					{
						dp[i][j+s]=MP(i, j);
					}
				}
			}
		}
	} */
	
	
	
	
	int test;
	cin>>test;
	for (int z = 1; z <= test; z++)
	{
		cout<<"Case #"<<z<<": ";
		int x, y;
		cin>>x>>y;
		for (int i = 1; ; i++)
		{
			if (tryn(x, y, i) )
			{
				for (int j = 1; j <= i; j++)
				{
					cout<<odp[j];
				}
				cout<<endl;
				break;
			}
		}
	}
	return 0;
}