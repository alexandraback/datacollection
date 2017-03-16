#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	for(int j1=1;j1<=t;j1++)
	{
		int r,c,m;
		cin>>r>>c>>m;
		cout<<"Case #"<<j1<<":\n";
		if(m==r*c-1)
		{
			for(int i=0;i<r;i++)
			{
				for(int j=0;j<c;j++)
				{
					if(i==r-1&&j==c-1)
						cout<<"c";
					else
						cout<<"*";
				}
				cout<<endl;
			}
			continue;
		}	
		if(r==2&&c==2)
		{
			if(m==0)
				cout<<"c.\n..\n";
			else
				cout<<"Impossible\n";
			continue;
		}
		if(r==1&&c==1)
		{
			cout<<'c'<<endl;
			continue;
		}
		if(m==r*c-1)
		{
			for(int i=0;i<r;i++)
			{
				for(int j=0;j<c;j++)
				{
					if(i==r-1&&j==c-1)
						cout<<"c";
					else
						cout<<"*";
				}
				cout<<endl;
			}
			continue;
		}	
		if(r==1)
		{
			if(m>c-2)
			{
				cout<<"Impossible\n";
			}
			else
			{
				int i;
				for(i=0;i<m;i++)	
					cout<<"*";
				for(;i<c-1;i++)
					cout<<".";
				cout<<'c'<<endl;
			}
			continue;
		}
		if(c==1)
		{
			if(m>r-2)
				cout<<"Impossible\n";
			else
			{
				int i;
				for(i=0;i<m;i++)	
					cout<<"*\n";
				for(;i<r-1;i++)
					cout<<".\n";
				cout<<'c'<<endl;
			}
			continue;
		}
		int d=(r*c)-m;
		int s[100]={};
		int k=2;
		if(d==2||d==3||d==7||d==5)
		{
			cout<<"Impossible\n";
			continue;
		}
		if(r==2)
		{
			if(d%2!=0)
			{
				cout<<"Impossible\n";
				continue;
			}
			else
			{
				s[0]=s[1]=d/2;
				d=0;
			}
		}
		else if(c==2)
		{
			if(d%2!=0)
			{
				cout<<"Impossible\n";
				continue;
			}
			else
			{
				for(k=0;k<d/2;k++)
					s[k]=2;
				d=0;
			}
		}
		else if(d==4)
		{
			s[0]=s[1]=2;
			d=0;
		}
		else
		{
			s[0]=min(c,(d-2)/2);
			d-=2*s[0];
			s[1]=s[0];
		}
		while(d)
		{
			if(d==s[0])
			{
				s[k]=d;
				k++;
				d=0;
			}
			else if(d-2>s[0])
			{
				s[k]=s[0];
				d-=s[k];
				k++;
			}
			else
			{
				if(d<c)
				{
					s[k]=d;
					k++;
				}
				else if(d==2)
				{
					s[k]=2;
					k++;
				}
				else
				{
					s[k]=d-2;
					k++;
					s[k]=2;
					k++;
				}
				d=0;
				
			}
		}
		int i;
		for(i=0;i<r;i++)
		{
			int j;
			for(j=0;j<s[i];j++)
			{
				if(i==0&&j==0)
					cout<<'c';
				else
					cout<<".";
			}
			for(;j<c;j++)
				cout<<'*';
					
			cout<<endl;
			
		}
	}
	return 0;
}




