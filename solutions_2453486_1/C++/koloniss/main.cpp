#include <iostream>
#include <string>
using namespace std;

char mas[4][4];
bool xwin,owin,ended;

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	cin>>T;
	for (int t = 0;t < T;t++)
	{
		cout<<"Case #"<<t+1<<": ";
		ended = true;
		for (int i = 0;i<4;i++)
			for (int j = 0;j<4;j++)
			{
				cin>>mas[i][j];
				if (mas[i][j]=='.') ended = false;
			}
			xwin = false;
			owin = false;
		for (int i = 0;i<4;i++)
		{
			if (((mas[i][0]=='X') || (mas[i][0]=='T')) && ((mas[i][1]=='X') || (mas[i][1]=='T'))&& ((mas[i][2]=='X') || (mas[i][2]=='T')) && ((mas[i][3]=='X') || (mas[i][3]=='T'))) 
			{
				xwin = true;
			}
			if (((mas[i][0]=='O') || (mas[i][0]=='T')) && ((mas[i][1]=='O') || (mas[i][1]=='T'))&& ((mas[i][2]=='O') || (mas[i][2]=='T')) && ((mas[i][3]=='O') || (mas[i][3]=='T'))) 
			{
				owin = true;
			}
			if (((mas[0][i]=='X') || (mas[0][i]=='T')) && ((mas[1][i]=='X') || (mas[1][i]=='T'))&& ((mas[2][i]=='X') || (mas[2][i]=='T')) && ((mas[3][i]=='X') || (mas[3][i]=='T'))) 
			{
				xwin = true;
			}
			if (((mas[0][i]=='O') || (mas[0][i]=='T')) && ((mas[1][i]=='O') || (mas[1][i]=='T'))&& ((mas[2][i]=='O') || (mas[2][i]=='T')) && ((mas[3][i]=='O') || (mas[3][i]=='T'))) 
			{
				owin = true;
			}
		}
		if (((mas[0][0]=='X') || (mas[0][0]=='T')) && ((mas[1][1]=='X') || (mas[1][1]=='T'))&& ((mas[2][2]=='X') || (mas[2][2]=='T')) && ((mas[3][3]=='X') || (mas[3][3]=='T'))) 
			{
				xwin = true;
			}
		if (((mas[0][0]=='O') || (mas[0][0]=='T')) && ((mas[1][1]=='O') || (mas[1][1]=='T'))&& ((mas[2][2]=='O') || (mas[2][2]=='T')) && ((mas[3][3]=='O') || (mas[3][3]=='T'))) 
			{
				owin = true;
			}
		if (((mas[0][3]=='X') || (mas[0][3]=='T')) && ((mas[1][2]=='X') || (mas[1][2]=='T'))&& ((mas[2][1]=='X') || (mas[2][1]=='T')) && ((mas[3][0]=='X') || (mas[3][0]=='T'))) 
			{
				xwin = true;
			}
		if (((mas[0][3]=='O') || (mas[0][3]=='T')) && ((mas[1][2]=='O') || (mas[1][2]=='T'))&& ((mas[2][1]=='O') || (mas[2][1]=='T')) && ((mas[3][0]=='O') || (mas[3][0]=='T'))) 
			{
				owin = true;
			}
		if (xwin) cout<<"X won"<<endl;
		else if(owin) cout<<"O won"<<endl;
		else if (!ended) cout<<"Game has not completed"<<endl;
		else cout<<"Draw"<<endl;
	}
	return 0;
}