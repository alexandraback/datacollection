#include <fstream>
#include <cmath>
using namespace std;
ifstream f("Input");
ofstream g("Output");
long long n,m,v[101],maxim,actual,t,T,jucarii[101][1010],a,b,cutii[101][101],i,viz[101],jucariii[101][101],cutiii[101][101];
int valid (int k)
{
	long long i;
	for(i=1;i<k;i++)
		if(v[i]>v[k])
			return 0;
		
	return 1;

}
void afis()
{
	for(long long qq=1;qq<=n;qq++)
		jucariii[qq][1]=jucarii[qq][1],jucariii[qq][2]=jucarii[qq][2];
	for(long long qq=1;qq<=m;qq++)
		cutiii[qq][1]=cutii[qq][1],cutiii[qq][2]=cutii[qq][2];
	actual=0;
	long long i;
	for( i=1;i<=m;i++)
		if(cutiii[i][1]==jucariii[v[i]][1])
		{
			actual=actual + min(cutiii[i][2],jucariii[v[i]][2]);
			cutiii[i][2]-=actual;
			jucariii[v[i]][2]-=actual;
		}
				
		if(maxim<actual)
			maxim=actual;

}
void permutari(int k)
{
	int i;
	for(i=1;i<=n;i++)
	{
		v[k]=i;
		if(valid(k))
			if(k==m)afis();
		else permutari(k+1);
	}

}
int main()
{
	f>>T;
	for(t=1;t<=T;t++)
	{
		f>>n>>m;
		for(i=1;i<=n;i++)
			f>>a>>b,jucarii[i][1]=b,jucarii[i][2]=a;
		for(i=1;i<=m;i++)
			f>>a>>b,cutii[i][1]=b,cutii[i][2]=a;
		permutari(1);
		g<<"Case #"<<t<<": "<<maxim<<'\n';
		maxim=0;
	}
		f.close();
		g.close();
		return 0;
}