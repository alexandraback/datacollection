#include<stdio.h>
char a[99][99];
bool trig;
bool process(int n,int m, int q)
{
	if(n>m){n^=m^=n^=m;trig^=true;}
	if(q==0)
	{
		if(n==1)
			return m==1;
		return true;
	}
	int i, j;
	if(q>=n)
	{
		if(trig)
		{
			for(i=0;i<n;i++)
				a[i][m-1]='*';
		}
		else
		{
			for(i=0;i<n;i++)
				a[m-1][i] = '*';
		}
		return process(n,m-1,q-n);
	}
	else
	{
		if(trig)
		{
			for(i=n-1;i>=2;i--)
				for(j=m-1;j>=2;j--)
					if(q)
					{
						q--;
						a[i][j]='*';
					}
		}
		else
		{
			for(i=m-1;i>=2;i--)
				for(j=n-1;j>=2;j--)
					if(q)
					{
						q--;
						a[i][j]='*';
					}
		}
		return q <= (n-2)*(m-2);
	}
}
bool process2(int n,int m, int q)
{
	int i, j;
	int k=0;
	for(i=n-1;i>=2;i--)
		for(j=m-1;j>=2;j--)
			if(q)
			{
				q--;
				k=1;
				a[i][j] = '*';
			}
	j=2;
	if(q%2==1 && k)
	{
		q++;k=0;
		a[2][2] = '.';
		j=3;
	}
	// 
	for(i=n-1;i>=j;i--)
		if(q>1)
		{
			a[i][0] = a[i][1] = '*';
			q-=2;
		}
	for(i=m-1;i>=j;i--)
		if(q>1)
		{
			a[0][i] = a[1][i] = '*';
			q-=2;
		}
	//
	if(q>0)
	{
		if(j==2)
		{
			if(q==3)return true;
		}
		else{
			if(q==8)return true;
		}
		return false;
	}
	return true;
}
int dx[8]={0,1,1,1,0,-1,-1,-1};
int dy[8]={1,1,0,-1,-1,-1,0,1};
int queue[10000][2];
int mask[99][99];
void test(int n,int m)
{
	int i, j;
	int si,sj;
	si=sj=0;
	int q,r;
	queue[0][0] = si;
	queue[0][1] = sj;
	int ti, tj;
	q=0;r=1;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			mask[i][j]=0;
	mask[0][0]=1;
	while(q<r)
	{
		si=queue[q][0];
		sj=queue[q][1];
		int k=0;
		for(i=0;i<8;i++)
		{
			ti = si+dx[i];
			tj = sj+dy[i];
			if(ti>=0 && ti<n)
				if(tj>=0 && tj<m)
					if(a[ti][tj] == '*')
						k++;
		}
		if(k==0)
		{
		for(i=0;i<8;i++)
		{
			ti = si+dx[i];
			tj = sj+dy[i];
			if(ti>=0 && ti<n)
				if(tj>=0 && tj<m)
				{
					if(mask[ti][tj]==0)
					{
					queue[r][0] = ti;
					queue[r][1] = tj;
					mask[ti][tj] = 1;
					r++;
					}
				}
		}
			
		}
		q++;
	}
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			if(mask[i][j] == 0 && a[i][j] == '.')
				printf("!\n");
}
int main()
{
	freopen("C-small-attempt2.in","rt",stdin);
	freopen("C-small-attempt2.out","wt",stdout);
	int t;
	scanf("%d",&t);
	int i, j, k;
	int tt=0;
	while(t--)
	{
		tt++;
		printf("Case #%d:\n",tt);
		int n, m, q;
		scanf("%d %d %d",&n,&m,&q);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				a[i][j]='.';
		a[0][0]='c';
		trig = true;
		bool res=true;
		if(n==1)
		{
			for(i=m-1;i>0;i--)
				if(q)
				{
					q--;
					a[0][i]='*';
				}
		}
		else if(m==1)
		{
			for(i=n-1;i>0;i--)
				if(q)
				{
					a[i][0]='*';
					q--;
				}
		}
		else
		{
			res = process2(n,m,q);
		}
		if(res)
		{
//			test(n,m);
			int i, j;
			for(i=0;i<n;i++,printf("\n"))
				for(j=0;j<m;j++)
					printf("%c",a[i][j]);
		}
		else
		{
			printf("Impossible\n");
		}
	}
}