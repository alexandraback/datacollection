#include<iostream>
using namespace std;

char c[10][10];

int main()
{
	int n, t=0, k, wo, wx, x, o;
	cin>>n;
	while(t<n)
	{
		t++;
		k=0;
		wo=0;
		wx=0;
		for(int i=0; i<4; i++)
		{
			for(int j=0; j<4; j++)
			{
				cin>>c[i][j];
				if(c[i][j]=='.')
				k=1;
			}
		}
		for(int i=0; i<4; i++)
		{
			x=0;
			o=0;
			for(int j=0; j<4; j++)
			{
				if(c[i][j]=='X')
				x++;
				if(c[i][j]=='O')
				o++;
				if(c[i][j]=='T')
				{	
					x++;
					o++;
				}
				if(x==4)
				wx=1;
				if(o==4)
				wo=1;
			}
		}
		for(int j=0; j<4; j++)
		{
			x=0;
			o=0;
			for(int i=0; i<4; i++)
			{
				if(c[i][j]=='X')
				x++;
				if(c[i][j]=='O')
				o++;
				if(c[i][j]=='T')
				{	
					x++;
					o++;
				}
				if(x==4)
				wx=1;
				if(o==4)
				wo=1;
			}
		}
		if((c[0][0]=='X' || c[0][0]=='T') && (c[1][1]=='X' || c[1][1]=='T') && (c[2][2]=='X' || c[2][2]=='T') && (c[3][3]=='X' || c[3][3]=='T'))
		wx=1;
		if((c[0][0]=='O' || c[0][0]=='T') && (c[1][1]=='O' || c[1][1]=='T') && (c[2][2]=='O' || c[2][2]=='T') && (c[3][3]=='O' || c[3][3]=='T'))
		wo=1;
		if((c[0][3]=='X' || c[0][3]=='T') && (c[1][2]=='X' || c[1][2]=='T') && (c[2][1]=='X' || c[2][1]=='T') && (c[3][0]=='X' || c[3][0]=='T'))
		wx=1;
		if((c[0][3]=='O' || c[0][3]=='T') && (c[1][2]=='O' || c[1][2]=='T') && (c[2][1]=='O' || c[2][1]=='T') && (c[3][0]=='O' || c[3][0]=='T'))
		wo=1;
		if(wo==1)
		{
			cout<<"Case #"<<t<<": O won\n";
		}
		else
		{
			if(wx==1)
			{
				cout<<"Case #"<<t<<": X won\n";
			}
			else
			{
				if(k)	
				{
					cout<<"Case #"<<t<<": Game has not completed\n";
				}
				else	
				{
					cout<<"Case #"<<t<<": Draw\n";
				}
			}
		}
	}
	return 0;
}

