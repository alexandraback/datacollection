#include<cstdio>
#include<iostream>
#include<fstream>
using namespace std;
char a[4][4];
bool match(int,int);
bool dmatch(int);
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A.out","w",stdout);
	int t;
	scanf("%d",&t);
	int i=0;
	while(i<t)
	{
		int j=0;
		int m=0,y=0;
		bool x = false;
		while(j<4)
		{
			scanf("%s",&a[j]);
			int k=0;
			while(k<4)
			{
				//cin>>a[j][k];
				//cout<<a[i][j]<<endl;
				//scanf("\n%[^\n]",a[j]);
				if(a[j][k]=='.')
				{
					y=1;
				}
				k++;
			}
			j++;
		}
		j=0;
		while(j<4)
		{
			//y=0;
			x=match(j,1);
			//cout<<x<<" "<<j<<" 1"<<endl;
			if(x==true)
			{
				//printf("1 %d\n",j);	
				if(a[j][0]=='X'||a[j][1]=='X')
					y=1;
				else
					y=0;
				m=1;
				break;
			}
			j++;
		}
		if(m==0)
		{
			j=0;
			while(j<4)
			{
				x=match(j,2);
				//cout<<x<<" "<<j<<" 2 "<<endl;
				if(x==true)
				{
					//printf("2 %d\n",j);
					if(a[0][j]=='X'||a[1][j]=='X')
					{
						y=1;
					}
				else
					y=0;
				m=1;
				break;
				}
				j++;
			}
		}
		if(m==0)
		{
			x=dmatch(1);
			if(x==true)
			{
				if(a[0][0]=='X'||a[1][1]=='X')
					y=1;
				else
					y=0;
				m=1;
			}
			else
			{
				//y=0;
				x=dmatch(2);
				if(x==true)
				{
					if(a[0][3]=='X'||a[3][0]=='X')
					y=1;
					else
						y=0;
					m=1;
				}
			}
		}
		printf("Case #%d: ",i+1);
		if(m==1)
		{
			if(y==1)
			printf("X won\n");
			else
			printf("O won\n");
		}
		else
		{
			if(y==1)
				printf("Game has not completed\n");
			else
				printf("Draw\n");
		}
		i++;
	}
	return 0;
}
bool match(int i,int k)
{
	int xcount=0,tcount=0,ocount=0,j;
	if(k==1)
	{
		j=0;
		while(j<4)
		{
			if(a[i][j]=='.')
				return false;
			else if(a[i][j]=='X')
				xcount++;
			else if(a[i][j]=='O')
				ocount++;
			else 
				tcount++;
			j++;
		}
		//cout<<"x="<<xcount<<"o="<<ocount<<endl;
		if((xcount>0)&&(ocount>0))
				return false;
		else
			return true;
	}
	else
	{
		j=0;
		while(j<4)
		{
			if(a[j][i]=='.')
				return false;
			else if(a[j][i]=='X')
				xcount++;
			else if(a[j][i]=='O')
				ocount++;
			else 
				tcount++;
			j++;
		}
		if((xcount>0)&&(ocount>0))
				return false;
		else
			return true;
	}
}
bool dmatch(int i)
{
	int xcount=0,tcount=0,ocount=0;
	if(i==1)
	{
		int j=0;
		while(j<4)
		{
			if(a[j][j]=='.')
				return false;
			else if(a[j][j]=='X')
				xcount++;
			else if(a[j][j]=='O')
				ocount++;
			else 
				tcount++;
			j++;
		}
		if((xcount>0)&&(ocount>0))
				return false;
		else
			return true;
	}
	else
	{
		int j=0;
		while(j<4)
		{
			if(a[j][3-j]=='.')
				return false;
			else if(a[j][3-j]=='X')
				xcount++;
			else if(a[j][3-j]=='O')
				ocount++;
			else 
				tcount++;
			j++;
		}
		//cout<<"x"<<xcount<<"o"<<ocount<<endl;
		if((xcount>0)&&(ocount>0))
				return false;
		else
			return true;
	}
}