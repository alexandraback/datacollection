#include <iostream>
using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int tt=1;tt<=T;tt++)
	{
		char pic[4][5];
		for(int i=0;i<4;i++)
			cin>>pic[i];
		bool flag=false;
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				if(pic[i][j]=='.')
				{
					flag=true;
					break;
				}
		char win='Z';
		for(int i=0;i<4;i++)
		{
			int x=0,o=0,t=0;
			for(int j=0;j<4;j++)
				if(pic[i][j]=='X')
					x++;
				else if(pic[i][j]=='O')
					o++;
				else if(pic[i][j]=='T')
					t++;
			if(x==4||(x==3&&t==1)){win='X';break;}
			if(o==4||(o==3&&t==1)){win='O';break;}
		}
		if(win=='Z')
		{
			for(int j=0;j<4;j++)
			{
				int x=0,o=0,t=0;
				for(int i=0;i<4;i++)
					if(pic[i][j]=='X')
						x++;
					else if(pic[i][j]=='O')
						o++;
					else if(pic[i][j]=='T')
						t++;
				if(x==4||(x==3&&t==1)){win='X';break;}
				if(o==4||(o==3&&t==1)){win='O';break;}
			}
		}
		if(win=='Z')
		{
			int x=0,o=0,t=0;
			for(int i=0;i<4;i++)
				if(pic[i][i]=='X')
					x++;
				else if(pic[i][i]=='O')
					o++;
				else if(pic[i][i]=='T')
					t++;
			if(x==4||(x==3&&t==1)){win='X';}
			if(o==4||(o==3&&t==1)){win='O';}
		}
		if(win=='Z')
		{
			int x=0,o=0,t=0;
			for(int i=0;i<4;i++)
				if(pic[i][3-i]=='X')
					x++;
				else if(pic[i][3-i]=='O')
					o++;
				else if(pic[i][3-i]=='T')
					t++;
			if(x==4||(x==3&&t==1)){win='X';}
			if(o==4||(o==3&&t==1)){win='O';}
		}	
		cout<<"Case #"<<tt<<": ";
		if(win!='Z')
			cout<<win<<" won"<<endl;
		else if(!flag)
			cout<<"Draw"<<endl;
		else
			cout<<"Game has not completed"<<endl;
	}
	return 0;
}
