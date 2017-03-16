#include<stdio.h>
#include<fstream>
using namespace std;
int n;
int f[1010][1010];
int s[1010];
int doit[1010];
int yes=0;
void begin(int n)
{
	int i;
	if (yes) return ;
	for (i=1;i<=s[n];i++)
	{
		if (doit[f[n][i]]==1)
			yes=1;

		else
			doit[f[n][i]]=1;
		begin(f[n][i]);
	}
}
int main()
{
	int i,j,t,tt;
	ifstream in("D:/A-small-attempt0.in");
	ofstream out("D:/A-small-attempt0.out");
	in>>t;
	for (tt=1;tt<=t;tt++)
	{
		yes=0;
		in>>n;
		for (i=1;i<=n;i++)
		{
			doit[i]=0;
			in>>s[i];
			for (j=1;j<=s[i];j++)
				in>>f[i][j];
		}
		for (i=1;i<=n;i++)
		{
			for (j=1;j<=n;j++)doit[j]=0;
			begin(i);
			if (yes)
				break;
		}
		if (yes) out<<"Case #"<<tt<<": Yes"<<endl; 
		else out<<"Case #"<<tt<<": No"<<endl; 
	}

}