#include <fstream>
using namespace std;
ifstream f("Input");
ofstream g("Output");
long C[1001][1001],n,i,j,k;
unsigned T,t,tz,a,ok;

int main()
{
	f>>T;
	for(t=1;t<=T;t++)
	{
		ok=0;
		f>>n;
		for(i=1;i<=n;i++)
		{
				f>>tz;
				for(j=1;j<=tz;j++)
					f>>a,C[a][i]=1;
		}
		
		for(k=1;k<=n;k++)	
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)		
				if(i!=j)
					{	if(C[i][k] > 0 && C[k][j] > 0 && C[i][j] >0)
						g<<"Case #"<<t<<": Yes\n",k=n+1,ok=1;
						else if(C[i][k] > 0 && C[k][j] > 0 && C[i][j] ==0)
							C[i][j] = C[i][k] + C[k][j];
		
					}
				for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
					C[i][j]=0;
			if(ok==0)
				g<<"Case #"<<t<<": No\n";
	}	
	f.close();
	g.close();
	return 0;
}