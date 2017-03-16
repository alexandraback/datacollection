#include <iostream>
#include <string>
using namespace std;

char Mat[200][200];
int R,C,n;
string imps="Impossible";
void write(char Mat[][200],bool f)
{
	int RR=R;
	int CC=C;
	if(!f)
		swap(RR,CC);
	//cout<<RR<<"\t"<<CC<<"\t";
	//int sum=0;
	for(int r=0;r<RR;r++)
	{
		for(int c=0;c<CC;c++)
		{
			//if(f & Mat[r][c]=='*')
			//	sum++;
			//if(!f & Mat[c][r]=='*')
			//	sum++;
			//continue;
			if(f)
				cout<<Mat[r][c];
			else
				cout<<Mat[c][r];
		}
		cout<<endl;
	}
	//cout<<sum<<endl;
	
}

void doatest()
{
	
	cin>>R>>C>>n;
	//cout<<R<<"\t"<<C<<"\t"<<n<<endl;
	int m=R*C;
	//int mn=m-n;
	//if(R>2 & C>2)
	//{
	//	if(mn==2 || mn==3 || mn==5 || mn==7)
	//		cout<<"/////////"<<endl;
	//}else if(min(R,C)==2)
	//{
	//	if(mn!=1 && (n%2==1 || mn==2))
	//		cout<<"/////////"<<endl;
	//}


	if(m-n==1)
	{
		for(int r=0;r<R;r++)
			for(int c=0;c<C;c++)
				Mat[r][c]='*';
		Mat[0][0]='c';
		write(Mat,true);
		return;
	}
	bool f=true;
	if(C>R)
	{
		swap(R,C);
		f=false;
	}
	if(C==1)
	{
		for(int r=0;r<R;r++)
			Mat[r][0]='.';
		for(int r=R-1;n>0;n--,r--)
			Mat[r][0]='*';
		Mat[0][0]='c';
		write(Mat,f);
		return;
	}
	if(C==2)
	{
		swap(C,R);
		f=!f;
	}
	for(int r=0;r<R;r++)
		for(int c=0;c<C;c++)
			Mat[r][c]='.';
	for(int r=R-1;r>=0;r--)
	{
		int cc=min(n,C);
		if(cc==0)
			break;
		if(r==1)
		{
			if(2*C-n==2)
			{
				cout<<imps<<endl;
				return;
			}
			if(n%2==1)
			{
				if(R<=2 || C<=4)
				{
					cout<<imps<<endl;
					return;
				}
				Mat[2][C-1]=Mat[2][C-2]=Mat[2][C-3]='.';
				n+=3;
				if(n>2*C-6)
				{
					cout<<imps<<endl;
					return;
				}
			}
			for(int c=0;n>0;n-=2,c++)
			{
				Mat[0][c]=Mat[1][c]='*';
			}
			break;
		}
		if(cc==C-1)
		{
			if(r>2)
			{
				cc--;
				Mat[r-1][0]='*';
				n--;
			}else if(C==3)
			{
				cout<<imps<<endl;
				return;
			}else
			{
				cc-=2;
				Mat[r-1][0]=Mat[r-2][0]='*';
				n-=2;
			}
		}
		for(int c=0;c<cc;c++)
			Mat[r][c]='*',n--;
	}
	Mat[0][C-1]='c';
	write(Mat,f);
}

void main()
{
	int T;
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		cout<<"Case #"<<i<<":"<<endl;
		doatest();
	}
}