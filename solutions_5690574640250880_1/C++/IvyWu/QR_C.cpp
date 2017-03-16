#include<iostream>
using namespace std;
int R,C,M;
char map[50][50];
int mo[8][2];
bool calcu(int i,int j)
{
	int p,q,k,B=R*C-M-1,maxnow,temp;
	for (p=0;p<R;p++)
		for (q=0;q<C;q++)
			map[p][q]='*';
	map[i][j]='c';
	if (B==0) return true;
	for (k=0;k<8;k++)
		if (i+mo[k][0]>=0&&i+mo[k][0]<R&&j+mo[k][1]>=0&&j+mo[k][1]<C&&map[i+mo[k][0]][j+mo[k][1]]=='*')
		{
			map[i+mo[k][0]][j+mo[k][1]]='.';
			B--;
		}
	if (B<0) return false;
	while (B>0)
	{
		maxnow=0;
		for(p=0;p<R;p++)
			for (q=0;q<C;q++)
				if (map[p][q]=='.')
				{
					temp=0;
					for (k=0;k<8;k++)
						if (p+mo[k][0]>=0&&p+mo[k][0]<R&&q+mo[k][1]>=0&&q+mo[k][1]<C&&map[p+mo[k][0]][q+mo[k][1]]=='*') temp++;
					if (temp>maxnow&&temp<=B)
					{
						maxnow=temp;
						i=p;
						j=q;
					}
				}
		if (maxnow==0) return false;
		map[i][j]='0';
		for (k=0;k<8;k++)
			if (i+mo[k][0]>=0&&i+mo[k][0]<R&&j+mo[k][1]>=0&&j+mo[k][1]<C&&map[i+mo[k][0]][j+mo[k][1]]=='*') map[i+mo[k][0]][j+mo[k][1]]='.';
		B=B-maxnow;
	}
	if (B==0) return true;
	else return false;
}
int main()
{
	int T,k,B,i,p,q,j;
	bool flag;
	mo[0][0]=-1;
	mo[0][1]=-1;
	mo[1][0]=-1;
	mo[1][1]=0;
	mo[2][0]=-1;
	mo[2][1]=1;
	mo[3][0]=0;
	mo[3][1]=-1;
	mo[4][0]=0;
	mo[4][1]=1;
	mo[5][0]=1;
	mo[5][1]=-1;
	mo[6][0]=1;
	mo[6][1]=0;
	mo[7][0]=1;
	mo[7][1]=1;
	freopen("QR_C.in","r",stdin);
	freopen("QR_C.out","w",stdout);
	cin>>T;
	for (int k=0;k<T;k++)
	{
		cout<<"Case #"<<k+1<<":"<<endl;
		cin>>R>>C>>M;
		flag=false;
		for (i=0;i<R*C;i++)
			if (calcu(i/C,i%C))
			{
				flag=true;
				break;
			}
		B=R*C-M;
		if (flag==false&&B>4)
		{
			for (p=0;p<R;p++)
				for (q=0;q<C;q++)
					map[p][q]='*';
			for (i=2;i<=C;i++)
			{
				j=(B+4-i*2)/2;
				if (j<=R&&(i*2+j*2-4==B||(i>2&&j>2)))
				{
					for (p=0;p<i;p++)
					{
						map[0][p]='.';
						map[1][p]='.';
					}
					for (p=0;p<j;p++)
					{
						map[p][0]='.';
						map[p][1]='.';
					}
					if (i*2+j*2-4!=B) map[2][2]='.';
					map[0][0]='c';
					flag=true;
					break;
				}
			}
			if (flag==false&&B>C*2+R*2-4)
			{
			}
		}
		if (flag==false)
		{
			cout<<"Impossible"<<endl;
		}
		else
		{
			for (p=0;p<R;p++)
			{
				for (q=0;q<C;q++)
				{
					if (map[p][q]=='0') map[p][q]='.';
					cout<<map[p][q];
				}
				cout<<endl;
			}
		}
	}
}