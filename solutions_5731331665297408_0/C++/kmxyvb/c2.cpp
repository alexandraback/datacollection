#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 60

int f[MAXN],x[MAXN*MAXN],y[MAXN*MAXN],T,
	b[MAXN],Seq[MAXN],Ans,
	ZIP[MAXN],_[MAXN],
	n,m;
	
char s[MAXN][10];

bool cmp(int a,int b){return strcmp(s[a],s[b])<0;}

void IN(int a,int b){x[T]=f[a];y[T]=b;f[a]=T++;}

bool Check()
{
	int i,t,k,s[100];
	t=0;
	s[t++]=Seq[0];
if(Seq[0]==5&&Seq[1]==2&&Seq[2]==1&&Seq[3]==4)
{
Seq[0]=5;
}
	for(i=1;i<n;i++)
	{
		for(k=f[s[t-1]];k;k=x[k])
			if(y[k]==Seq[i])
				break;
		if(k)
		{
			s[t++]=Seq[i];
			continue;
		}
		t--;
		i--;
		if(!t)return 0;
	}
	return 1;
}

void Dfs(int D)
{
	if(D==n)
	{
		if(Check())Ans=1;
		return;
	}
	for(int i=0;i<n;i++)
		if(!b[i])
		{
			b[i]=1;
			Seq[D]=ZIP[i];
			Dfs(D+1);
			b[i]=0;
			if(Ans==1)return;
		}
}

int main()
{
	int TestCase,Case,i,j,k;
//	freopen("c.in","rb",stdin);
//	freopen("c2.out","wb",stdout);
	scanf("%d",&TestCase);
	for(Case=1;Case<=TestCase;Case++)
	{
		scanf("%d%d",&n,&m);
		memset(f,0,sizeof f);
		memset(b,0,sizeof b);
		T=2;
		for(i=1;i<=n;i++)
			scanf("%s",s+i);
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&j,&k);
			IN(j,k);
			IN(k,j);
		}
		for(i=0;i<n;i++)ZIP[i]=i+1;
		std::sort(ZIP,ZIP+n,cmp);
		for(i=0;i<n;i++)_[ZIP[i]]=i;
		Dfs(0);
		Ans=0;
		printf("Case #%d: ",Case);
		for(i=0;i<n;i++)printf("%s",s[Seq[i]]);
		printf("\n");
	}
	return 0;
}
