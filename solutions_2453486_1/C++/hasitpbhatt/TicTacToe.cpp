#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
using namespace std;

int cal(char);

int arr[4][4];

string out(int a[4][4]);

int main(int argc,char*argv[])
{
	int n,cnt=0,i,j;
	string s;
	fstream in(argv[1]);
	in >> n;
	while(n--)
		{
			cnt++;
			for(i=0;i<4;i++)
				{
				in >> s;
				for(j=0;j<4;j++)
					arr[i][j]=cal(s[j]);
				}
			cout << "Case #" << cnt << ": " << out(arr) << endl;
		}
	return 0;
}

int cal(char x)
{
	if(x=='T')
		return 25;
	else if(x=='X')
		return 5;
	else if(x=='O')
		return 1;
	else
		return 0;
}

string out(int arr[4][4])
{
	int i,j,cnt;
	for(i=0;i<4;i++)
		{
			cnt=0;
			for(j=0;j<4;j++)
				{
					cnt+=arr[i][j];
				}
			if((cnt==4)||(cnt==28))
				return "O won";
			else if((cnt==20)||(cnt==40))
				return "X won";
		}
	for(i=0;i<4;i++)
		{
			cnt=0;
			for(j=0;j<4;j++)
				{
					cnt+=arr[j][i];
				}
			if((cnt==4)||(cnt==28))
				return "O won";
			else if((cnt==20)||(cnt==40))
				return "X won";
		}
	cnt=0;
	for(i=0;i<4;i++)
		cnt+=arr[i][i];
	if((cnt==4)||(cnt==28))
				return "O won";
			else if((cnt==20)||(cnt==40))
				return "X won";
	cnt=0;
	for(i=0;i<4;i++)
		cnt+=arr[i][3-i];
	if((cnt==4)||(cnt==28))
				return "O won";
	else if((cnt==20)||(cnt==40))
				return "X won";
	cnt=0;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			if((arr[i][j])==0)
				return "Game has not completed";
	
	return "Draw";
}
