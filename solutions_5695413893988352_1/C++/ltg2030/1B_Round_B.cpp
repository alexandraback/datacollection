#include<stdio.h>
#include<string.h>

long long ans;
char ansa[25];
char ansb[25];

int n;
char a[25];
char b[25];

long long abs(long long x)
{
	if(x>0)
		return x;
	return -x;
}

void recall(int lev,int checker)
{
	if(lev==n+1)
	{
		int i;
		long long x=0,y=0;
		long long xx=0, yy=0;
		for(i=1;i<=n;i++)
		{
			x*=10;
			y*=10;
			x+=a[i]-'0';
			y+=b[i]-'0';
		}
		if(ans>abs(x-y))
		{
			ans=abs(x-y);
			for(i=1;i<=n;i++)
			{
				ansa[i]=a[i];
				ansb[i]=b[i];
			}
		}
		else if(ans==abs(x-y))
		{
			for(i=1;i<=n;i++)
			{
				xx*=10;
				yy*=10;
				xx+=ansa[i]-'0';
				yy+=ansb[i]-'0';
			}
			if(x<xx || y<yy)
			{
				for(i=1;i<=n;i++)
				{
					ansa[i]=a[i];
					ansb[i]=b[i];
				}
			}
		}
		return;
	}
	if(checker==0) // a[1~lev-1] == b[1~lev-1]
	{
		if(a[lev]=='?')
		{
			if(b[lev]=='?')
			{
				a[lev]='0';
				b[lev]='0';
				recall(lev+1,0);
				a[lev]='1';
				b[lev]='0';
				recall(lev+1,1);
				a[lev]='0';
				b[lev]='1';
				recall(lev+1,2);
				a[lev]='?';
				b[lev]='?';
			}
			else
			{
				a[lev]=b[lev];
				recall(lev+1,0);
				if(b[lev]!='9')
				{
					a[lev]=b[lev]+1;
					recall(lev+1,1);
				}
				if(b[lev]!='0')
				{
					a[lev]=b[lev]-1;
					recall(lev+1,2);
				}
				a[lev]='?';
			}
		}
		else
		{
			if(b[lev]=='?')
			{
				b[lev]=a[lev];
				recall(lev+1,0);
				if(a[lev]!='9')
				{
					b[lev]=a[lev]+1;
					recall(lev+1,2);
				}
				if(a[lev]!='0')
				{
					b[lev]=a[lev]-1;
					recall(lev+1,1);
				}
				b[lev]='?';
			}
			else
			{
				if(a[lev]==b[lev])
					recall(lev+1,0);
				if(a[lev]>b[lev])
					recall(lev+1,1);
				if(a[lev]<b[lev])
					recall(lev+1,2);
			}
		}
	}
	else if(checker==1) // a[1~lev-1] > b[1~lev-1]
	{
		int aflag=0, bflag=0;
		if(a[lev]=='?')
		{
			a[lev]='0';
			aflag=1;
		}
		if(b[lev]=='?')
		{
			b[lev]='9';
			bflag=1;
		}
		recall(lev+1,1);
		if(aflag)
			a[lev]='?';
		if(bflag)
			b[lev]='?';
	}
	else if(checker==2)
	{
		int aflag=0, bflag=0;
		if(a[lev]=='?')
		{
			a[lev]='9';
			aflag=1;
		}
		if(b[lev]=='?')
		{
			b[lev]='0';
			bflag=1;
		}
		recall(lev+1,2);
		if(aflag)
			a[lev]='?';
		if(bflag)
			b[lev]='?';
	}
}

int main(void)
{
	int pp,ppp,i;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&ppp);
	for(pp=1;pp<=ppp;pp++)
	{
		scanf("%s",&a[1]);
		scanf("%s",&b[1]);
		n=strlen(&a[1]);
		for(i=1;i<=n+1;i++)
			ansa[i]=ansb[i]=0;
		ans=999999999999999999LL;
		recall(1,0);
		printf("Case #%d: %s %s\n",pp,&ansa[1],&ansb[1]);
	}
}
