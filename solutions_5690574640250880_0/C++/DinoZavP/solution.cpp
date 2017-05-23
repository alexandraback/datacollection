#include<iostream>
using namespace std;
char A[50][50];
void main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int R, C, M, k, a1, a2;
	int T;
	bool flag, flag1;
	
	cin>>T; 
	
	for(int t=1;t<=T;t++)
	{
		cin>>R>>C>>M;
		k=M;
		flag=false;
		flag1=false;
		for (int i=0;i<R;i++)
			for(int j=0;j<C;j++)
				A[i][j]=NULL;
		A[0][0]='c';
		cout<<"Case #"<<t<<": "<<endl;
		if (R*C-1==M) 
			{
				flag=true;
				for(int i=0;i<R;i++)
				{
						for(int j=0;j<C;j++)
							if ((i!=0)||(j!=0)) cout<<"*"; else cout<<"c";
				cout<<endl;
				}
			}
		if ((M==0)&&!flag)
		{
			cout<<"c";
			for(int i=0;i<R;i++)
			{
				for(int j=0;j<C;j++)
					if ((i!=0) || (j!=0)) cout<<".";
				cout<<endl;
			}
			flag=true;
		}
		if (!flag && (R<=2) && (C<=2))
		{ 
			flag=true;
			cout<<"Impossible"<<endl;
		}
		if (!flag && ((R<=2) || (C<=2)))
		{
			if (R>C)
			{
				if ((M>C*(R-2))||(M%C>0)&&!flag) 
				{
					flag=true;
					cout<<"Impossible"<<endl;
				}
				if (!flag)  
				{
					for(int i=R-1;((i>=2)&&(k>0));i--)
						for(int j=C-1;((j>=0)&&(k>0));j--)
						{
							A[i][j]='*';
							k--;
						}
				}
			} else
			{
				if ((M>R*(C-2))||(M%R>0)&&!flag) 
				{
					flag=true;
					cout<<"Impossible"<<endl;
				}
				if (!flag)  
				{
					for(int j=C-1;((j>=2)&&(k>0));j--)
						for(int i=R-1;((i>=0)&&(k>0));i--)
						{
							A[i][j]='*';
							k--;
						}
				}
			}
			if (!flag)
			for (int i=0;i<R;i++)
			{
				for(int j=0;j<C;j++)
					if (A[i][j]==NULL) cout<<"."; else cout<<A[i][j];
				cout<<endl;
				flag=true;
			}
		}
		if (!flag)
		{
			for(int i=R-1;((i>=2)&&(k>0));i--)
				for(int j=C-1;((j>=2)&&(k>0));j--)
				{
					A[i][j]='*';
					k--;
				}
			a1=R-1;
			a2=C-1;
			while ((k>1)&&((a1>=2)||(a2>=2)))
			{
				while((k>1)&&(a1>=a2)&&(a1>=2))
				{
					A[a1][0]='*';
					A[a1][1]='*';
					k-=2;
					a1--;
				}
				while((k>1)&&(a2>=a1)&&(a2>=2))
				{
					A[0][a2]='*';
					A[1][a2]='*';
					k-=2;
					a2--;
				}
			}	
			if (k==0)
				for (int i=0;i<R;i++)
				{
						for(int j=0;j<C;j++)
							if (A[i][j]==NULL) cout<<"."; else cout<<A[i][j];
						cout<<endl;
				}
			if ((a1==1)&&(a2==1)&&(k!=0)) 
				if (k==3)
				{
					A[0][1]='*';
					A[1][0]='*';
					A[1][1]='*';
					k=0;
				for (int i=0;i<R;i++)
				{
						for(int j=0;j<C;j++)
							if (A[i][j]==NULL) cout<<"."; else cout<<A[i][j];
						cout<<endl;
				}
					flag=true;
				} else
				{
					cout<<"Impossible"<<endl;
					flag=true;
				}
			if ((k==1) &&!flag)
			{
				if ((a1>2)||(a2>2))
				{
				A[2][2]=NULL;
				k++;
				while ((k>1)&&((a1>=2)||(a2>=2)))
			{
				while((k>1)&&(a1>=a2)&&(a1>=2))
				{
					A[a1][0]='*';
					A[a1][1]='*';
					k-=2;
					a1--;
				}
				while((k>1)&&(a2>=a1)&&(a2>=2))
				{
					A[0][a2]='*';
					A[1][a2]='*';
					k-=2;
					a2--;
				}
			}	
				for (int i=0;i<R;i++)
				{
						for(int j=0;j<C;j++)
							if (A[i][j]==NULL) cout<<"."; else cout<<A[i][j];
						cout<<endl;
				}
				} else cout<<"Impossible"<<endl;
			}
		}
		//cout<<R<<" "<<C<<" "<<M<<endl;
	}
}