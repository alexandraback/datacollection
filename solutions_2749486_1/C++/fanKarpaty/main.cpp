#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX(x,y) (x > y ? x : y)
#define MIN(x,y) (x > y ? y : x)
bool flmin[10000];
bool fluse[10000];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	cin>>T;
	int tt=T;
	
	while(T--)
	{
		int X,Y;
		cin>>X>>Y;
		string res="";
		int x=0, y=0;
		int i=0;
		bool fX=false;
		bool fY=false;
		if(X<0){
			fX=true;
			X=-X;
		}
		if(Y<0)
		{
			fY=true;
			Y=-Y;
		}
		int sum=0;
		while(sum<X+Y)
		{
			i++;
			sum+=i;
		}
		while((sum-X-Y)%2)
		{
			i++;
			sum+=i;
		}
		memset(flmin,0,sizeof(flmin));
		memset(fluse,0,sizeof(fluse));
		int j=i+1;
		while(sum!=X+Y)
		{
			j--;
			if(sum-2*j>=X+Y)
			{
				flmin[j]=1;
				sum-=2*j;
			}
		}
		j=i;
		while(flmin[j])
		{
			x-=j;
			fluse[j]=1;
			j--;
		}
		while(x<X)
		{
			if(x+j<=X)
			{
				if(!flmin[j])
					{
						x+=j;
						fluse[j]=1;
				}
				else
				{
					if(!fluse[j+1])
					{
						x++;
						fluse[j+1]=1;
						fluse[j]=1;
					}
				}
			}
			j--;
		}
		res="";
		for(j=1;j<=i;j++)
		{
			if(fluse[j])
			{
				if(flmin[j])res+="W";
				else res+="E";
			}
			else
			{
				if(flmin[j])res+="S";
				else res+="N";
			}
		}
		for(j=1;j<=i;j++)
		{
			if(fX)
			{
				int f=0;
				if(res[j-1]=='W')f=1;
				if(res[j-1]=='E')f=2;
				if(f==1)res[j-1]='E';
				if(f==2)res[j-1]='W';
			}
			if(fY)
			{
				int f=0;
				if(res[j-1]=='S')f=1;
				if(res[j-1]=='N')f=2;
				if(f==1)res[j-1]='N';
				if(f==2)res[j-1]='S';
			}
		}
		cout<<"Case #"<<(tt-T)<<": "<<res<<endl;
		
	}
	return 0;
}