#include <fstream>

using namespace std;

char a[4][4];
int f[256];
int s[4];
int t,tt,i,j,state;
char c;

ifstream fin("in.txt");
ofstream fout("out.txt");

void check()
{
	for(i=0;i<4;i++)
	{
		memset(s,0,sizeof(s));
		for(j=0;j<4;j++)
		   s[f[a[i][j]]]++;
		if (s[0]==4 ||(s[0]==3 && s[3]==1))
			state=1;
		if (s[1]==4 ||(s[1]==3 && s[3]==1))
			state=2;
	}
	for(i=0;i<4;i++)
	{
		memset(s,0,sizeof(s));
		for(j=0;j<4;j++)
		   s[f[a[j][i]]]++;
		if (s[0]==4 ||(s[0]==3 && s[3]==1))
			state=1;
		if (s[1]==4 ||(s[1]==3 && s[3]==1))
			state=2;
	}
	memset(s,0,sizeof(s));
	for(j=0;j<4;j++)
	   s[f[a[j][j]]]++;
	if (s[0]==4 ||(s[0]==3 && s[3]==1))
		state=1;
	if (s[1]==4 ||(s[1]==3 && s[3]==1))
		state=2;
	memset(s,0,sizeof(s));
	for(j=0;j<4;j++)
	   s[f[a[j][3-j]]]++;
	if (s[0]==4 ||(s[0]==3 && s[3]==1))
		state=1;
	if (s[1]==4 ||(s[1]==3 && s[3]==1))
		state=2;

	if(!state)
	{
		for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			if(a[i][j]=='.')
				state=3;
	}
}

int main()
{
	f['X']=0;f['O']=1;f['.']=2;f['T']=3;
	fin>>t;

	for(tt=1;tt<=t;tt++)
	{
		for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			fin>>a[i][j];
		state=0;
		check();

		fout<<"Case #"<<tt<<": ";
		switch(state)
		{
			case 0:fout<<"Draw";break;
			case 1:fout<<"X won";break;
			case 2:fout<<"O won";break;
			case 3:fout<<"Game has not completed";break;
		}
		fout<<endl;
	}

	return 0;
}