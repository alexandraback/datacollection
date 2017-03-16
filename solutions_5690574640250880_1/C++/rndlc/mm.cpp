#include<iostream>
using namespace std;
int main()
{
	int t,r,c,m,i,j,k,x,y,ts,ps,l;
	cin>>t;
	bool flag;
	char mat[51][51];
	for(i=1;i<=t;i++)
	{
		flag=true;
		cin>>r>>c>>m;
		ts=r*c;
		for(j=0;j<r;j++)
			for(k=0;k<c;k++)
				mat[j][k]='*';
		if(ts-m==1)
			mat[0][0]='c';
		else if(m==0)
		{
			for(j=0;j<r;j++)
				for(k=0;k<c;k++)
					mat[j][k]='.';
			mat[0][0]='c';
		}
		else if(r==1||c==1)
		{
			if(r==1)
			{
				k=0;
				mat[k][0]='c';
				for(j=1;j<c;j++)
				{
					if(j<ts-m)
						mat[k][j]='.';
					else
						mat[k][j]='*';
				}
			}
			else
			{
				j=0;
				mat[0][j]='c';
				for(k=0;k<r;k++)
				{
					if(k<ts-m)
						mat[k][j]='.';
					else
						mat[k][j]='*';
				}
			}
			mat[0][0]='c';
		}
		else if((r==2||c==2)&&(ts-m)%2==1)
			{flag=false;}
		else
		{
			ts=ts-m;
			l=ts;
			if((ts<4||ts==5)||ts==7)
				{flag=false;}
			else if(ts%2==0)
			{
				mat[0][0]=mat[0][1]=mat[1][0]=mat[1][1]='.';
				ts-=4;
				for(j=2;j<max(r,c)&&ts>0;j++)
				{
					if(j<r)
					{
						mat[j][0]=mat[j][1]='.';ts-=2;
					}
					if(ts>0&&j<c)
					{
						mat[0][j]=mat[1][j]='.';ts-=2;
					}
				}
				j=k=2;
				while(ts>0)
				{
					for(ps=j;ps<r;ps++)
					{
						if(ts>0)
							{mat[ps][k]='.';ts--;}
					}
					for(ps=k+1;ps<c;ps++)
					{
						if(ts>0)
							{mat[j][ps]='.';ts--;}
						
					}
					j++;k++;
					
				}
			}
			else
			{
				ts=l-1;mat[2][2]='.';
				mat[0][0]=mat[0][1]=mat[1][0]=mat[1][1]='.';
				ts-=4;
				for(j=2;j<max(r,c)&&ts>0;j++)
				{
					if(j<r)
					{
						mat[j][0]=mat[j][1]='.';ts-=2;
					}
					if(ts>0&&j<c)
					{
						mat[0][j]=mat[1][j]='.';ts-=2;
					}
				}
				for(j=3;j<r&&ts>0;j++)
					{mat[j][2]='.';ts--;}
				for(k=3;k<c&&ts>0;k++)
					{mat[2][k]='.';ts--;}
				j=3;k=3;
				while(ts>0)
				{
					for(ps=j;ps<r;ps++)
					{
						if(ts>0)
							{mat[ps][k]='.';ts--;}
					}
					for(ps=k+1;ps<c;ps++)
					{
						if(ts>0)
							{mat[j][ps]='.';ts--;}
					}
				}	
			}
			mat[0][0]='c';
		}
		if(flag==false)
			cout<<"Case #"<<i<<":\nImpossible\n";
		else
		{
			cout<<"Case #"<<i<<":\n";
			for(k=0;k<r;k++)
			{
				for(j=0;j<c;j++)
					cout<<mat[k][j];
				cout<<endl;
			}
		}
		
	}
}