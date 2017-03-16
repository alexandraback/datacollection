#include<cstdio>
using namespace std;
int main()
{
int N,T; scanf("%d",&N);
for(T=1;T<=N;T++)
{
	int a,s,d,f,g,n,m;
	int i[300][200],b[200],c[200],r[300],v[300],o[300],r2[200][300],r2l[200],e[300][200],ec[300];
	scanf("%d%d",&m,&n);
	for(s=0;s<200;s++) b[s]=0;
	for(d=0;d<m;d++){ int t; scanf("%d",&t); t--; b[t]++; }
	for(s=0;s<200;s++) c[s]=0;
	for(s=0;s<200;s++) r2l[s]=0;
	for(a=0;a<n;a++) ec[a]=0;
	for(a=0;a<n;a++)
	{
		scanf("%d%d",&r[a],&m);
		r[a]--;
		c[r[a]]++;
		r2[r[a]][r2l[r[a]]]=a;
		r2l[r[a]]++;
		for(s=0;s<200;s++) i[a][s]=0;
		for(d=0;d<m;d++){ int t; scanf("%d",&t); t--; if( i[a][t]==0 ){ e[a][ec[a]]=t; ec[a]++; } i[a][t]++; }
	}
	for(a=0;a<n;a++) v[a]=0;
	for(d=0;d<n;d++)
	{
		for(a=0;a<n;a++)
		{
			if( v[a]==1 ) continue;
			if( b[r[a]]==0 ) continue;
//printf("%d %d %d %d %d\n",d,a,c[r[a]],b[r[a]],i[a][r[a]]);
			if( c[r[a]]==1 ) goto choose;
			if( b[r[a]]>1 ) goto choose;
			if( i[a][r[a]]>0 ) goto choose;
			int b2[200],v2[300],q[300],ql,qr;
			for(s=0;s<200;s++) b2[s]=b[s]+i[a][s];
			b2[r[a]]--;
			for(f=0;f<n;f++) v2[f]=v[f];
			v2[a]=1;
			ql=0; qr=0;
			for(f=0;f<n;f++) if( v2[f]==0 && b2[r[f]]>0 ){ v2[f]=1; q[qr]=f; qr++; }
			while( qr>ql )
			{
				int x=q[ql];
				ql++;
				for(f=0;f<ec[x];f++)
				{
					int y=e[x][f];
					if( b2[y]>0 ) continue;
					b2[y]+=i[x][y];
					if( y==r[a] ) goto found;
					for(g=0;g<r2l[y];g++)
					{
						int z=r2[y][g];
						if( v2[z]==1 ) continue;
						v2[z]=1;
						q[qr]=z;
						qr++;
					}
				}
			}
			if( false ) found: goto choose;
		}
		break;
		if( false )
		{ choose:
//printf("Chose: %d %d %d\n",a,c[r[a]],b[r[a]]);
			o[d]=a;
			v[a]=1;
			b[r[a]]--;
			c[r[a]]--;
			for(s=0;s<200;s++) b[s]+=i[a][s];
		}
	}
	printf("Case #%d:",T);
	if( d<n ) printf(" IMPOSSIBLE");
	else for(d=0;d<n;d++) printf(" %d",o[d]+1);
	printf("\n");
}
	return 0;
}
