#include  <iostream>
using namespace std;

int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	int T;
	cin >> T;

	for (int qq=1;qq<=T;qq++)
	{
			bool flag=true;
		int a[4][4]={-1};
		for (int i=0;i<4;i++)
		{
			for (int j=0;j<4;j++)
			{
				a[i][j]=-1;
			}
		}
		for (int i=0;i<4;i++)
		{
			for (int j=0;j<4;j++)
			{
				char temp;
				cin >> temp;
				if (temp=='X') a[i][j]=5;
				else 
				{
					if (temp=='O') a[i][j]=25;
					else 
					{
							if (temp=='T') a[i][j]=0;
							else 
							{
								if (temp=='.') flag=false;
							}
					}
				}
			}
		}
		int total[10]={0};
		for (int i=0;i<4;i++)
		{
			for (int j=0;j<4;j++)
			{
				total[i]+=a[i][j];
			}
		}
		for (int i=0;i<4;i++)
		{
			for (int j=0;j<4;j++)
			{
				total[i+4]+=a[j][i];
			}
		}
		for (int i=0;i<4;i++)
		{
			total[8]+=a[i][i];
			total[9]+=a[i][3-i];
		}
		cout << "Case #"<<qq<<": ";
		bool fflag=true;
		for (int i=0;i<10;i++)
		{
			if (total[i]==15 || total[i]==20) {cout << "X won"<<endl;fflag=false;break;}
			if (total[i]==75 || total[i]==100) {cout << "O won"<<endl;fflag=false;break;}
		}
		if (fflag)
		{
			if (flag) cout << "Draw"<<endl;
			else cout << "Game has not completed"<<endl;
		}
	}
	return 0;
}