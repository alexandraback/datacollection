#include<bits/stdc++.h>
#define ll long long
using namespace std;
string arr3[4][4];
string arr4[5][5];
int main(int argc, char const *argv[])
{

	string winner="RICHARD";
	int t;
	cin>>t;
	for(int t1=1;t1<=t;t1++)
	{
		int x,r,c;
		cin>>x>>r>>c;
		if(x==1)
		{
			winner="GABRIEL";
		}
		else if(x==2)
		{
			if((r*c)%2==0)
				winner="GABRIEL";
			else
				winner="RICHARD";
		}
		else if(x==3)
		{

			// if((r==1 && c==1)||(r==1 && c==2) || (r==1 && c==4) || (r==2 && c==1) || (r==4 && c==1) || (r==2 && c==2)||(r==4 && c==2)||(r==2 && c==4))
			// 	winner="RICHARD";
			for(int i=0;i<4;i++)
			{
				arr3[1][i+1]="RICHARD";
				arr3[2][i+1]="RICHARD";
			}
			arr3[3][1]="RICHARD";

			arr3[2][3]=arr3[3][2]=arr3[3][3]="GABRIEL";
			arr3[4][1]=arr3[4][2]="RICHARD";
			arr3[4][3]=arr3[3][4]="GABRIEL";
			arr3[4][4]="RICHARD";
			winner=arr3[r][c];
			//cout<<arr3[3][4];
		}
		else
		{
			for(int i=0;i<4;i++)
			{
				arr4[1][i+1]="RICHARD";
				arr4[2][i+1]="RICHARD";
			}
			arr4[3][4]=arr4[4][3]="GABRIEL";
			arr4[3][1]="RICHARD";
			arr4[3][2]="RICHARD";
			arr4[3][3]="RICHARD";
			arr4[4][1]="RICHARD";
			arr4[4][2]=arr4[2][4]="RICHARD";
			arr4[4][4]="GABRIEL";
			winner=arr4[r][c];
		}
		cout<<"Case #"<<t1<<": "<<winner<<endl;
	}
	return 0;
}
