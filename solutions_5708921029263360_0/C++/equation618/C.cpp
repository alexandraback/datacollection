#include <bits/stdc++.h>
using namespace std;

int A,B,C,K,S,n,a[30],u[5][5],v[5][5],w[5][5],b[30][3];

void init()
{
	scanf("%d%d%d%d",&A,&B,&C,&K);
	S=0;
	for (int i=1; i<=A; i++)
		for (int j=1; j<=B; j++)
			for (int k=1; k<=C; k++) S++,b[S][0]=i,b[S][1]=j,b[S][2]=k;
}

bool check()
{
	memset(u,0,sizeof(u));
	memset(v,0,sizeof(v));
	memset(w,0,sizeof(w));
	for (int i=1; i<=n; i++)
	{
		int x=b[a[i]][0],y=b[a[i]][1],z=b[a[i]][2];
		//cout<<"  "<<i<<' '<<a[i]<<' '<<x<<' '<<y<<' '<<z<<endl;
		u[x][y]++;
		v[x][z]++;
		w[y][z]++;
		if (u[x][y]>K||v[x][z]>K||w[y][z]>K) return 0;
	}
	return 1;
}

void doit()
{
	int ma=0,p;
	for (int i=0; i<1<<S; i++)
	{
		n=0;
		for (int j=0; j<S; j++) if ((i>>j)&1) a[++n]=j+1;
		if (n>ma&&check()) ma=n,p=i;
		if (ma==S) break;
	}
	n=0;
	for (int j=0; j<S; j++) if ((p>>j)&1) a[++n]=j+1;
	printf("%d\n",ma);
	for (int i=1; i<=ma; i++) printf("%d %d %d\n",b[a[i]][0],b[a[i]][1],b[a[i]][2]);
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int i=1; i<=T; i++)
	{
		init();
		printf("Case #%d: ",i);
		cerr<<i<<endl;
		doit();
	}
	return 0;
}
