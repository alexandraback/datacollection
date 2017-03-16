#include<fstream>
#include<cstdio>
#include<map>
#define pii pair<int,int>
using namespace std;
int T,n,X,Y;
long long bun,total;
double sol;
map <pii,bool> viz;

inline void Back(int k,int x,int y,int slide)
{
	if(k==n+1)
	{
		total+=1LL;
		if(viz[make_pair(X,Y)]==true)
			bun+=1LL;
		return;
	}
	if(y==0)
	{
		viz[make_pair(x,y)]=true;
		Back(k+1,0,n+5,0);
		viz[make_pair(x,y)]=false;
		return;
	}
	if(!slide)
	{
		if(!viz[make_pair(x,y-2)])
			Back(k,x,y-1,0);
		else
		{
			bool ok=false;
			if(!viz[make_pair(x-1,y-1)])
			{
				ok=true;
				Back(k,x-1,y-1,-1);
			}
			if(!viz[make_pair(x+1,y-1)])
			{
				ok=true;
				Back(k,x+1,y-1,1);
			}
			if(!ok)
			{
				viz[make_pair(x,y)]=true;
				Back(k+1,0,n+5,0);
				viz[make_pair(x,y)]=false;
				return;
			}
		}
	}
	else
	{
		if(!viz[make_pair(x+slide,y-1)])
			Back(k,x+slide,y-1,slide);
		else
		{
			viz[make_pair(x,y)]=true;
			Back(k+1,0,n+5,0);
			viz[make_pair(x,y)]=false;
			return;
		}
	}
}

int main()
{
	int t;
	ifstream fin("B.in");
	freopen("B.out","w",stdout);
	fin>>T;
	for(t=1;t<=T;t++)
	{
		fin>>n>>X>>Y;
		bun=total=0LL;
		Back(1,0,n+5,0);
		sol=1.0*bun;
		sol/=(1.0*total);
		printf("Case #%d: %.8lf\n",t,sol);
	}
	fin.close();
	return 0;
}
