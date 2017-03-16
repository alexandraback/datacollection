#include<cstdio>

int a[10][10],R,n,_f,__f,Pre,Suc;

char s[11000];

int F(char x)
{
	if(x=='i')return 1;
	if(x=='j')return 2;
	return 3;
}

int main()
{
	int i,j,k,_,Case,TestCase,;
//	freopen("c.in","rb",stdin);
//	freopen("c.out","wb",stdout);
	a[0][0]=0;
	a[0][1]=1;
	a[0][2]=2;
	a[0][3]=3;
	a[1][0]=1;
	a[1][1]=4;
	a[1][2]=3;
	a[1][3]=6;
	a[2][0]=2;
	a[2][1]=7;
	a[2][2]=4;
	a[2][3]=1;
	a[3][0]=3;
	a[3][1]=2;
	a[3][2]=5;
	a[3][3]=4;
	
	for(i=0;i<8;i++)
		for(j=0;j<8;j++)
		{
			_=(i>>2)+(j>>2);
			a[i][j]=a[i&3][j&3];
			if(_&1)a[i][j]^=4;
		}
	scanf("%d",&TestCase);
	for(Case=1;Case<=TestCase;Case++)
	{
		scanf("%d%d",&n,&R);
		scanf("%s",s);
		_f=__f=0;
		for(i=0;i<n;i++)
			_f=a[_f][F(s[i])];
		for(i=0;i<(R%4);i++)
			__f=a[__f][_f];
		if(__f!=4)
		{
			printf("Case #%d: NO\n",Case);
			continue;
		}
		Pre=-1;
		for(_f=k=0;k<4&&k<R;k++)
		{
			for(i=0;i<n;i++)
			{
				_f=a[_f][F(s[i])];
				if(_f==1)break;
			}
			if(i<n)
			{
				Pre=k*n+i+1;
				break;
			}
		}
		if(Pre==-1)
		{
			printf("Case #%d: NO\n",Case);
			continue;
		}
		Suc=-1;
		for(_f=k=0;k<4&&k<R;k++)
		{
			for(i=n-1;i>=0;i--)
			{
				_f=a[F(s[i])][_f];
				if(_f==3)break;
			}
			if(i>=0)
			{
				Suc=k*n+n-i;
				break;
			}
		}
		if(Suc==-1||Pre+Suc>=n*R)
		{
			printf("Case #%d: NO\n",Case);
			continue;
		}
		printf("Case #%d: YES\n",Case);
	}
	return 0;
}
