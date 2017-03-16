#include<cstdio>
using namespace std;
long long L,X;
int i=2,j=3,k=4;
int tab[5][5];
char st[200000];
int len;
int l;
char ch[10004];
void pre()
{
	for(int a=1;a<5;a++)
	for(int b=1;b<5;b++)
	{
		if(a==1) tab[a][b]=b;
		if(b==1) tab[a][b]=a;
		if(a==b && a!=1) tab[a][b]=-1; 
	}
	tab[i][j]=k; tab[j][i]=-k; tab[i][k]=-j; tab[k][i]=j;
	tab[j][k]=i; tab[k][j]=-i;
	
/*	printf("table is : \n");
	for(int i=1;i<5;i++)
	{
		for(int j=1;j<5;j++) printf("%d ",tab[i][j]); printf("\n");
	}
	*/
}
int mul(int a,char b)
{
	int s=1; if(a<0) a=-a,s=-1;
	int bb=1;
	if(b=='i') bb=2;
	if(b=='j') bb=3;
	if(b=='k') bb=4;
	int ret=tab[a][bb];
	return ret*s;
}

int sol()
{
int ret=0;
int cal=1;
int t=0;
//printf("got %d\n",len);
while(cal!=i && t<len)
{
	cal=mul(cal,st[t]); t++;
//	printf("got \n");
}	

if(t==len) return 0; 
cal=1;
while(cal!=j && t<len)
{
	cal=mul(cal,st[t]); t++;
}	

if(t==len) return 0;
cal=1;
while(t<len)
{
	cal=mul(cal,st[t]); t++;
}
if(cal!=k) return 0;
return 1;
}

int main()
{
	int ntc; scanf("%d",&ntc);
	pre();
	for(int tc=1;tc<=ntc;tc++)
	{
		printf("Case #%d: ",tc);
		scanf("%lld %lld",&L,&X);
		scanf("%s",&ch);
		int tm=X,ttt=0;l=L;
		if(X>12)
		{
			tm=12;
			ttt=(X-12)%4;
			tm+=ttt;		
			len=L*tm;
		}
	else len=X*L;
		//printf("here  %d %d\n",l,len);
		for(int a=0;a<=tm;a++)
		{
			for(int b=0;b<l;b++)
			st[a*l + b]=ch[b];
		}
		st[len]='\0';
		
		int a=sol();
		if(a) printf("YES\n"); else printf("NO\n");
		
		
	}
}
