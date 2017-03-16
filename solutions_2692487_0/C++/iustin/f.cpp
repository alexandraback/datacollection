# include <iostream>
# include <fstream>
# define P 2007
using namespace std;
int t, n, p[16], c[300][300];

int main ()
{
	p[0]=1;
	for(int i=1;i<=10;++i)
		p[i]=2*p[i-1];
	//ifstream fin ("f.in");
	cin>>t;
	
	int k, m;
	for(int i=0;i<=252;++i)
		c[i][0]=c[i][i]=1;

	for(int i=1;i<=252;++i)
		for(int j=1;j<i;++j)
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%P;
			
	for(;t--;)
	{
		cin>>n;
		if (n==0)cout<<"0\n";
		else if (n==1)cout<<"1\n";
		else
		{
			k=0;
			while(p[k]-1<n)++k;
			m=p[k]-p[k-1];
			k=n-p[k-1]+1;
			cout<<c[m][k]<<"\n";
		}
	}
	return 0;
}
