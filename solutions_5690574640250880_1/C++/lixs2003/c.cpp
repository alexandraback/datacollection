#include<iostream>
#include<string.h>
#include<stdio.h>
#include<memory.h>
#include<algorithm>
using namespace std;

int flag[60][60],n1,i1,c,r,m,ii,jj,k,i,j,t;

int main()
{
	cin>>n1;
	for(i1=1;i1<=n1;i1++)
	{
		cin>>r>>c>>m;
		t=0;
		memset(flag,0,sizeof(flag));
		flag[1][1]=1;
		if(r==1)
		{
			for(i=2;i<=c-m;i++)
				flag[1][i]=-1;
		}
		else if(c==1)
		{
			for(i=2;i<=r-m;i++)
				flag[i][1]=-1;
		}
		else
		{
			k=c*r-m;
			if(k==1)
			{
				
			} 
			else if(k<4)
			{
				t=1;
			}
			else{
				flag[1][2]=-1;
				flag[2][1]=-1;
				flag[2][2]=-1;
				k=k-4;
				i=2;j=2;
				while(k>=2&&(i<r||j<c))
				{
					if(i<r)
					{
						i++;
						flag[i][1]=-1;
						flag[i][2]=-1;
						k-=2;
					}
					if(k>=2&&j<c)
					{
						j++;
						flag[1][j]=-1;
						flag[2][j]=-1;
						k-=2;
					}
				}
				if(k>0)
				{
					if((i-2)*(j-2)<k)
						t=1; 
					else
					{
						for(ii=3;ii<=i;ii++)
						{
							for(jj=3;jj<=j;jj++)
							{
								k--;								
								flag[ii][jj]=-1;
								if(k==0)
									break;
							}
								if(k==0)
									break;
						}
					}
				}
			}
		}
		cout<<"Case #"<<i1<<":"<<endl;
		if(t==1)
		{
			cout<<"Impossible"<<endl;
			continue;
		}
		for(i=1;i<=r;i++)
		{
			for(j=1;j<=c;j++)
			{
				if(flag[i][j]==0)
					cout<<'*';
				if(flag[i][j]==1)
					cout<<'c';
				if(flag[i][j]==-1)
					cout<<'.';
			}
			cout<<endl;
		}
	}
}
