#include <iostream>
using namespace std;
void out(int r,int c, int m)
{
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(i==r-1 && j==c-1)
				cout<<"c";
			else if(m>0)
			{
				cout<<"*";
				m--;
			}
			else
				cout<<".";
		}
		cout<<endl;
	}
}
void outc(int r,int c, int m)
{
	int arr[r][c];
	for(int i=0;i<c;i++)
	{
		for(int j=0;j<r;j++)
		{
			if(i==c-1 && j==r-1)
				arr[j][i]=2;
			else if(m>0)
			{
				arr[j][i]=1;
				m--;
			}
			else
				arr[j][i]=0;;
		}
	}
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(arr[i][j]==1)
				cout<<"*";
			else if(arr[i][j]==0)
				cout<<".";
			else
				cout<<"c";
		}
		cout<<endl;
	}
}
void outg(int r,int c, int m)
{
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(i==r-1 && j==c-1)
				cout<<"c";
			else if(m>0 && i<r-2 && j<c-2)
			{
				cout<<"*";
				m--;
			}
			else
				cout<<".";
		}
		cout<<endl;
	}
}
int main() 
{
	int t,r,c,m,tot,l,cas=0;
	cin>>t;
	while(t--)
	{
		cout<<"Case #"<<++cas<<":"<<endl;
		cin>>r>>c>>m;
		tot=r*c;
		l=tot-m;
		if(m==0)
		{
			for(int i=0;i<r;i++)
			{
				for(int j=0;j<c;j++)
				{
					if(i==r-1 && j==c-1)
						cout<<"c";
					else
						cout<<".";
				}
				cout<<endl;
			}
		}
		else if(l==1 || r==1 || c==1)
			out(r,c,m);
		else if(r==2 || c==2)
		{
			if(l<4 || m%2==1)
				cout<<"Impossible"<<endl;
			else if (c==2)
				out(r,c,m);
			else
				outc(r,c,m);
		}
		else
		{
			if(l<4)
				cout<<"Impossible"<<endl;
			else if(m<=(r-2)*(c-2))
				outg(r,c,m);
			else if(r==3 && c==3)
			{
				if(m==2 || m==4)
					cout<<"Impossible"<<endl;
				else if(m==3)
					out(r,c,m);
				else
				{
					cout<<"***"<<endl<<"*.."<<endl<<"*.c"<<endl;
				}
			}
			else if(r==3 && c==4)
			{
				if(m==4)
					out(r,c,m);
				else if(m==3)
					cout<<"*..."<<endl<<"*..."<<endl<<"*..c"<<endl;
				else if(m==5||m==7)	
					cout<<"Impossible"<<endl;
				else if(m==6)
					cout<<"****"<<endl<<"*..."<<endl<<"*..c"<<endl;
				else if(m==8)
					cout<<"****"<<endl<<"**.."<<endl<<"**.c"<<endl;
			}
			else if(r==4 && c==3)
			{
				if(m==4)
					outc(r,c,m);
				else if(m==3)
					cout<<"***"<<endl<<"..."<<endl<<"..."<<endl<<"..c"<<endl;
				else if(m==5||m==7)	
					cout<<"Impossible"<<endl;
				else if(m==6)
					cout<<"***"<<endl<<"*.."<<endl<<"*.."<<endl<<"*.c"<<endl;
				else if(m==8)
					cout<<"***"<<endl<<"***"<<endl<<"*.."<<endl<<"*.c"<<endl;	
			}
			else if(r==3 && c==5)
			{
				if(m==5)
					out(r,c,m);
				else if(m==6)
					cout<<"*...*"<<endl<<"*.c.*"<<endl<<"*...*"<<endl;
				else if(m==4)
					cout<<"*...*"<<endl<<"*.c.."<<endl<<"*...."<<endl;
				else if(m%2==0)
					cout<<"Impossible"<<endl;
				else if(m==7)
					cout<<"*****"<<endl<<"*...."<<endl<<"*...c"<<endl;
				else if(m==9)
					cout<<"*****"<<endl<<"**..."<<endl<<"**..c"<<endl;
				else if(m==11)
					cout<<"*****"<<endl<<"***.."<<endl<<"***.c"<<endl;
			}
			else if(r==5 && c==3)
			{
				if(m==5)
					outc(r,c,m);
				else if(m==4)
					cout<<"***"<<endl<<"..."<<endl<<".c."<<endl<<"..."<<endl<<"*.."<<endl;
				else if(m==6)
					cout<<"***"<<endl<<"..."<<endl<<".c."<<endl<<"..."<<endl<<"***"<<endl;
				else if(m%2==0)
					cout<<"Impossible"<<endl;
				else if(m==7)
					cout<<"***"<<endl<<"*.."<<endl<<"*.."<<endl<<"*.."<<endl<<"*.c"<<endl;
				else if(m==9)
					cout<<"***"<<endl<<"***"<<endl<<"*.."<<endl<<"*.."<<endl<<"*.c"<<endl;
				else if(m==11)
					cout<<"***"<<endl<<"***"<<endl<<"***"<<endl<<"*.."<<endl<<"*.c"<<endl;
			}
			else if(r==4 && c==4)
			{
				if(m==5)
					cout<<"****"<<endl<<"*..."<<endl<<"..c."<<endl<<"...."<<endl;
				else if(m==7)
					cout<<"****"<<endl<<"*..."<<endl<<"*.c."<<endl<<"*..."<<endl;
				else if(m%2==1)
					cout<<"Impossible"<<endl;
				else if(m==6||m==8)
					out(r,c,m);
				else if(m==10)
					cout<<"****"<<endl<<"****"<<endl<<"*..."<<endl<<"*..c"<<endl;
				else if(m==12)
					cout<<"****"<<endl<<"****"<<endl<<"**.."<<endl<<"**.c"<<endl;
			}
			else if(r==4 && c==5)
			{
				if(m==8||m==10)
					out(r,c,m);
				else if(m==12)
					cout<<"*****"<<endl<<"*****"<<endl<<"*...."<<endl<<"*...c"<<endl;
				else if(m==14)
					cout<<"*****"<<endl<<"*****"<<endl<<"**..."<<endl<<"**..c"<<endl;
				else if(m==16)
					cout<<"*****"<<endl<<"*****"<<endl<<"***.."<<endl<<"***.c"<<endl;
				else if(m==7)
					cout<<"*****"<<endl<<"*...*"<<endl<<"..c.."<<endl<<"....."<<endl;
				else if(m==9)
					cout<<"*****"<<endl<<"*...*"<<endl<<"*.c.."<<endl<<"*...."<<endl;
				else if(m==11)
					cout<<"*****"<<endl<<"*...*"<<endl<<"*.c.*"<<endl<<"*...*"<<endl;
				else if(m%2==1)
					cout<<"Impossible"<<endl;
			}
			else if(r==5 && c==4)
			{
				if(m==8||m==10)
					outc(r,c,m);
				else if(m==12)
					cout<<"****"<<endl<<"**.."<<endl<<"**.."<<endl<<"**.."<<endl<<"**.c"<<endl;
				else if(m==14)
					cout<<"****"<<endl<<"****"<<endl<<"**.."<<endl<<"**.."<<endl<<"**.c"<<endl;
				else if(m==16)
					cout<<"****"<<endl<<"****"<<endl<<"****"<<endl<<"**.."<<endl<<"**.c"<<endl;
				else if(m==7)
					cout<<"**.."<<endl<<"*..."<<endl<<"*.c."<<endl<<"*..."<<endl<<"**.."<<endl;
				else if(m==9)
					cout<<"****"<<endl<<"*..."<<endl<<"*.c."<<endl<<"*..."<<endl<<"**.."<<endl;
				else if(m==11)
					cout<<"****"<<endl<<"*..."<<endl<<"*.c."<<endl<<"*..."<<endl<<"****"<<endl;
				else if(m%2==1)
					cout<<"Impossible"<<endl;
			}
			else
			{
				if(m==11||m==13||m==15||m==10||m==12)
					out(r,c,m);
				else if(m==14)
					cout<<"*****"<<endl<<"*****"<<endl<<"**..."<<endl<<"*...."<<endl<<"*...c"<<endl;
				else if(m==16)
					cout<<"*****"<<endl<<"*...*"<<endl<<"*.c.*"<<endl<<"*...*"<<endl<<"*****"<<endl;
				else if(m==17)
					cout<<"*****"<<endl<<"*****"<<endl<<"*****"<<endl<<"*...."<<endl<<"*...c"<<endl;
				else if(m==19)
					cout<<"*****"<<endl<<"*****"<<endl<<"*****"<<endl<<"**..."<<endl<<"**..c"<<endl;
				else if(m==21)
					cout<<"*****"<<endl<<"*****"<<endl<<"*****"<<endl<<"***.."<<endl<<"***.c"<<endl;
				else if(m%2==0)
					cout<<"Impossible"<<endl;
			}
		}
	}
	return 0;
}