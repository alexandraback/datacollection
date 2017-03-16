#include <stdio.h>
int n,m;
int a[4][4]={{0,1,2,3},{1,4,3,6},{2,7,4,1},{3,2,5,4}};
int s[10002];
int r0,i0,r1,i1;

int Dijkstra(int x)
{
	int sign=0;
	int value=0;
	int i,j;
	for (j=r0,i=i0;j<r1 || (j==r1 && i<=i1);)
	{
		value=a[value][s[i]];
		sign^=value/4;
		value=value%4;

		//printf("%d %d \n",sign,value);

		i++;
		if (i==m) {i=0;j++;}

		if (sign==0 && value==x) 
		{
			r1=j;i1=i; return 1;
		} 
	}
	return 0;


}



int main()
{
	int T,k,i,j,max,min;
	char c;
	freopen("in.txt", "r", stdin);
	scanf("%d", &T);
	freopen("Result.txt", "w", stdout);

	for(k = 1; k <= T; k++) 
	{

		scanf("%d %d\n", &m,&n);
		//printf("mn=%d %d\n",m,n);
		for (i=0;i<m;i++)
		{
			scanf("%c",&c);
			if (c=='1') s[i]=0;
			if (c=='i') s[i]=1;
			if (c=='j') s[i]=2;
			if (c=='k') s[i]=3;
			//printf("c=%d\n",s[i]);
		}



		int r=n;
		if (r>4) r=4;
		r0=1;i0=0;r1=r;i1=m-1;
		if (Dijkstra(1)==0 || r1>n)
		{
			printf("Case #%d: NO\n", k);
			continue;
		}


		r0=r1;i0=i1;

		if ((r1+4)>n)  
		{
			r1=n;
			i1=m-1;
		}
		else
		{
			r1=r0+4;
			i1=i0;
		}

		if (Dijkstra(2)==0 || r1>n)
		{
			printf("Case #%d: NO\n", k);
			continue;
		}


		r0=r1;i0=i1;

		if ((r1+4)>n)  
		{
			r1=n;
			i1=m-1;
		}
		else
		{
			r1=r0+4;
			i1=i0;
		}

		if (Dijkstra(3)==0) 
		{
			printf("Case #%d: NO\n", k);
			continue;
		}

		r0=r1;i0=i1;
		r1=n;
		if (r0<=n) {r1=(n-r0)%4 + r0; i1=m-1;}
		int sign=0;
		int value=0;
		int i,j;
		for (j=r0,i=i0;j<=r1;)
		{
			value=a[value][s[i]];
			sign^=value/4;
			value=value%4;

			i++;
			if (i==m) {i=0;j++;}
		}

		if (sign==0 && value ==0) 
			printf("Case #%d: YES\n", k);
		else
			printf("Case #%d: NO\n", k);

	}
}