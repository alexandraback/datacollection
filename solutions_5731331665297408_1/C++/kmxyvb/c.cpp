#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 60

int f[MAXN],x[MAXN*MAXN],y[MAXN*MAXN],T,
	b[MAXN],Seq[MAXN],Far[MAXN],
	ZIP[MAXN],_[MAXN],Min[MAXN],Stack[MAXN],
	n,m;
	
char s[MAXN][10];

bool cmp(int a,int b){return strcmp(s[a],s[b])<0;}

void IN(int a,int b){x[T]=f[a];y[T]=b;f[a]=T++;}

void GetMin(int l)
{
	Min[l]=-1;
	for(int k=f[l];k;k=x[k])
		if(!b[y[k]]&&(Min[l]==-1||_[y[k]]<_[Min[l]]))
			Min[l]=y[k];
}

int Find(int x){return Far[x]==x?x:Far[x]=Find(Far[x]);}

bool NotDfs()
{
	int i,k;
	for(i=1;i<=n;i++)if(b[i])Far[i]=Seq[0];else Far[i]=i;
	for(i=1;i<=n;i++)if(!b[i])
		for(k=f[i];k;k=x[k])
			if(Stack[y[k]]||!b[y[k]])
			{
				if(Find(i)!=Find(y[k]))
					Far[Far[y[k]]]=Far[i];
			}
	for(i=1;i<=n;i++)
		if(Find(i)!=Find(Seq[0]))
			return 0;
	return 1;
}

void Dfs(int l,int D)
{
	int i,j;
	if(!Stack[l])Stack[l]=1;
	Seq[D]=l;
	for(i=0;i<=D;i++)GetMin(Seq[i]);
if(l==3)
{
l=3;
}
	if(Min[l]==-1)
	{
		Stack[l]--;
		if(D)Dfs(Seq[D-1],D-1);
		return;
	}
	for(i=D-1;i>=0;i--)
	if(Min[Seq[i]]!=-1&&_[Min[Seq[i]]]<_[Min[l]])
	{
		for(j=i+1;j<=D;j++)Stack[Seq[j]]=0;
		if(NotDfs())
		{
			Dfs(Seq[i],i);
			return;
		}
	}
	b[Min[l]]=1;
	printf("%s",s[Min[l]]);
	Dfs(Min[l],D+1);
	Stack[l]--;
}

int main()
{
	int TestCase,Case,i,j,k;
	//freopen("c.in","rb",stdin);
	//freopen("c.out","wb",stdout);
	scanf("%d",&TestCase);
	for(Case=1;Case<=TestCase;Case++)
	{
		scanf("%d%d",&n,&m);
		memset(f,0,sizeof f);
		memset(b,0,sizeof b);
		memset(Stack,0,sizeof Stack);
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
		printf("Case #%d: ",Case);
		b[ZIP[0]]=1;
		printf("%s",s[ZIP[0]]);
		Dfs(ZIP[0],0);
		printf("\n");
for(i=1;i<=n;i++)
if(!b[i])
printf("NSKNOJJ\n");
	}
	return 0;
}
