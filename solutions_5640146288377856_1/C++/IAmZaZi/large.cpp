#include<iostream>
using namespace std;
void solve(int row,int col,int width)
{
	if(row==1)
	{
		if(width==col)
		{
			cout<<width;
			return;
		}
		else
		{
			int x=col/width;
			int a1=width-1;
			int a2=col-x*width;
			if(a2>1)
				a2=1;
			cout<<x+(a2+a1);
		}
	}
	else
	{
		if(width==col)
			cout<<(width+row-1);
		else
		{
			int xyz=0;
			for(int point=0; point<row; point++)
				xyz=xyz+(col/width);
			int t1=width-1;
			int temp=col/width;
			int t2=col-temp*width;
			if(t2>1)
				t2=1;
			cout<<xyz+(t2+t1);
		}
	}
}
int main()
{
	int test,r,c,w;
		cin>>test;
	for(int i=1;i<=test;i++)
	{
		cin>>r>>c>>w;
		cout<<"Case #"<<i<<": ";
		solve(r,c,w);
		cout<<endl;
	}
}
