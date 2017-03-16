#include<cstdio>
#include<iostream>
#include<cstring>
#define maxN 1000
#define maxE 1000
using namespace std;
int v[maxN];
int f[maxN][maxE];

int main()
{
	int T,E,R,N;
	cin>>T;
	for (int run=1;run<=T;run++)
	{
		printf("Case #%d: ",run);
		cin>>E>>R>>N;
		for (int i=1;i<=N;i++) cin>>v[i];
		memset(f,0,sizeof(f));

		// f[i][j] after ith day's work, we have j energy remains

		for (int j=0;j<=E;j++) f[1][j]=v[1]*(E-j);

		for (int i=2;i<=N;i++)
			for (int j=0;j<=E;j++)
				for (int k=0;k<=E;k++)
				{
					int e=min(k+R,E)-j;
					if (e<0) continue;
					f[i][j]=max(f[i][j],f[i-1][k]+e*v[i]);
				}
		cout<<f[N][0]<<endl;
	}
	return 0;
}
