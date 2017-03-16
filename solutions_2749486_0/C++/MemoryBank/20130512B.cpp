#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

const long long maxl=100;

string s;
int t1,t2,x,y,i,j,k;
int f[4*maxl][4*maxl][maxl];
int g[4*maxl][4*maxl][maxl];

ifstream fin("b.in");
ofstream fout("b.out");


int main()
{
	fin>>t1;
	for(t2=1;t2<=t1;t2++)
	{
		fin>>x>>y;
		x=x+2*maxl;
		y=y+2*maxl;
		memset(f,sizeof(f),0);
		f[2*maxl][2*maxl][0]=1;
		for(i=1;i<maxl-1;i++)
		{
			for(j=0;j<4*maxl;j++)
			for(k=0;k<4*maxl;k++)
			if (f[j][k][i-1]==1){
				if (j+i<4*maxl)
				{
					f[j+i][k][i]=1;
					g[j+i][k][i]=0;
				}
				if (j-i>=0)
				{
					f[j-i][k][i]=1;
					g[j-i][k][i]=1;
				}
				if (k-i>=0)
				{
					f[j][k-i][i]=1;
					g[j][k-i][i]=2;
				}
				if (k+i<4*maxl)
				{
					f[j][k+i][i]=1;
					g[j][k+i][i]=3;
				}
			}
			if (f[x][y][i]==1)
				break;
		}
		fout<<"Case #"<<t2<<": ";
		s="";
		for(j=i;j>0;j--)
		{
			if (g[x][y][j]==0)
			{
				x=x-j;
				s="E"+s;
			}else
			if (g[x][y][j]==1)
			{
				x=x+j;
				s="W"+s;
			}else
			if (g[x][y][j]==2)
			{
				y=y+j;
				s="S"+s;
			}else
			if (g[x][y][j]==3)
			{
				y=y-j;
				s="N"+s;
			}
		}
		fout<<s<<endl;
	}

	return 0;
}