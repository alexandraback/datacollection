#include <cstdio>
#include <algorithm>
using namespace std;

FILE *in,*out;

int a,b,c,m,n;
int ab[11][11],bc[11][11],ac[11][11];
struct dat{
	int a,b,c,r;
}d[1001];

int main ()
{
	int T,t;

	in = fopen("input.txt","r");
	out = fopen ("output.txt","w");

	fscanf (in,"%d",&T);
	for (t=1;t<=T;t++)
	{
		int i,j,k,l,ch,s=0;

		fscanf (in,"%d%d%d%d",&a,&b,&c,&m);
		fprintf (out,"Case #%d: ",t);


		for (i=0;i<a;i++) for (j=0;j<b;j++) ab[i][j]=0;
		for (i=0;i<a;i++) for (j=0;j<c;j++) ac[i][j]=0;
		for (i=0;i<b;i++) for (j=0;j<c;j++) bc[i][j]=0;
		for (i=0;i<a;i++)
			for (j=i;j<i+b;j++)
				for (k=j;k<j+c;k++)
				{
					//if (i==1&&j%b==2) printf ("%d %d %d : %d %d %d\n",i+1,j+1,k+1,ab[i][j%b],bc[j%b][k%c],ac[i][k%c]);
					if (ab[i][j%b]<m && bc[j%b][k%c]<m && ac[i][k%c]<m)
					{
						s++;
						ab[i][j%b]++;
						bc[j%b][k%c]++;
						ac[i][k%c]++;
					}
				}

		fprintf (out,"%d\n",s);

		for (i=0;i<a;i++) for (j=0;j<b;j++) ab[i][j]=0;
		for (i=0;i<a;i++) for (j=0;j<c;j++) ac[i][j]=0;
		for (i=0;i<b;i++) for (j=0;j<c;j++) bc[i][j]=0;
		for (i=0;i<a;i++)
			for (j=i;j<i+b;j++)
				for (k=j;k<j+c;k++)
					if (ab[i][j%b]<m && bc[j%b][k%c]<m && ac[i][k%c]<m)
					{
						fprintf (out, "%d %d %d\n",i+1,j%b+1,k%c+1);
						ab[i][j%b]++;
						bc[j%b][k%c]++;
						ac[i][k%c]++;
					}
	}

	return 0;
}

/*
for (i=0;i<a;i++) for (j=0;j<b;j++) ab[i][j]=0;
for (i=0;i<a;i++) for (j=0;j<c;j++) ac[i][j]=0;
for (i=0;i<b;i++) for (j=0;j<c;j++) bc[i][j]=0;

for (i=0;i<a;i++)
for (j=0;j<b;j++)
for (k=0;k<c;k++)
{
ab[i][j]++,bc[j][k]++,ac[i][k]++;
d[s].a=i,d[s].b=j,d[s].c=k,d[s].r=1;
s++;
}
do
{
ch=0;
for (l=0;l<s;l++)
if (d[l].r)
{
i=d[l].a,j=d[l].b,k=d[l].c;
if (ab[i][j]>m && bc[j][k]>m && ac[i][k]>m)
ch=1,d[l].r=0,ab[i][j]--,bc[j][k]--,ac[i][k]--;
}
}while (ch);
do
{
ch=0;
for (l=0;l<s;l++)
if (d[l].r)
{
i=d[l].a,j=d[l].b,k=d[l].c;
if ((ab[i][j]>m && bc[j][k]>m) || (ab[i][j]>m && ac[i][k]>m) || (bc[j][k]>m && ac[i][k]>m))
ch=1,d[l].r=0,ab[i][j]--,bc[j][k]--,ac[i][k]--;
}
}while (ch);
do
{
ch=0;
for (l=0;l<s;l++)
if (d[l].r)
{
i=d[l].a,j=d[l].b,k=d[l].c;
if ((ab[i][j]>m) || (ac[i][k]>m) || (bc[j][k]>m))
ch=1,d[l].r=0,ab[i][j]--,bc[j][k]--,ac[i][k]--;
}
}while (ch);
for (j=i=0;i<s;i++)
j+=d[i].r;
fprintf (out,"%d\n",j);
for (i=0;i<s;i++)
if (d[i].r)
fprintf (out,"%d %d %d\n",d[i].a+1,d[i].b+1,d[i].c+1);*/