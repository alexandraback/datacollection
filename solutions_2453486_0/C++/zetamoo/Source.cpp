#include<iostream>
#include<algorithm>
#include<sstream>
#include<stack>
#include<math.h>
#include<cmath>
#include<stdio.h>
#include<string>
#include<set>
using namespace std;
int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);
	int n,N=0;
	double row[4]={0},col[4],diag1,diag2;
	cin>>n;
	bool comp;
	string map[4];
	while(++N<=n)
	{
		comp=true;
		diag1=diag2=0;
		for(int f=0;f<4;f++)
		{
			cin>>map[f];
			row[f]=col[f]=0;
		}
		diag1=(map[0][0]=='X')+(map[1][1]=='X')+(map[2][2]=='X')+(map[3][3]=='X')+0.5*((map[0][0]=='T')+(map[1][1]=='T')+(map[2][2]=='T')+(map[3][3]=='T'))-((map[0][0]=='O')+(map[1][1]=='O')+(map[2][2]=='O')+(map[3][3]=='O'));
		diag2=(map[0][3]=='X')+(map[1][2]=='X')+(map[2][1]=='X')+(map[3][0]=='X')+0.5*((map[0][3]=='T')+(map[1][2]=='T')+(map[2][1]=='T')+(map[3][0]=='T'))-((map[0][3]=='O')+(map[1][2]=='O')+(map[2][1]=='O')+(map[3][0]=='O'));
		for(int f=0;f<4;f++)
		{
			for(int f1=0;f1<4;f1++)
			{
				if(map[f][f1]=='.')
					comp=false;
				row[f]+=((map[f][f1]=='X')+0.5*(map[f][f1]=='T')-(map[f][f1]=='O'));
				col[f1]+=((map[f][f1]=='X')+0.5*(map[f][f1]=='T')-(map[f][f1]=='O'));
			}
		}
		for(int f=0;f<4;f++)
		{
			if(row[f]==4||row[f]==3.5||col[f]==4||col[f]==3.5||diag1==4||diag1==3.5||diag2==4||diag2==3.5)
			{
				printf("Case #%d: X won\n",N);
				break;
			}
			if(row[f]==-4||row[f]==-2.5||col[f]==-4||col[f]==-2.5||diag1==-4||diag1==-2.5||diag2==-4||diag2==-2.5)
			{
				printf("Case #%d: O won\n",N);
				break;
			}
			if(f==3)
			{
				if(comp)
					printf("Case #%d: Draw\n",N);
				else
					printf("Case #%d: Game has not completed\n",N);
			}
		}
	}
}
//Case #1: X won
//Case #2: Draw
//Case #3: Game has not completed
//Case #4: O won