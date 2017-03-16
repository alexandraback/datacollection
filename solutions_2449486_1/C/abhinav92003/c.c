#include<stdio.h>
int main()
{
	int t,T,n,m,i,j;
	scanf(" %d",&T);
	t=1;
	while(t<=T)
	{
		int a[100][100]={0};
		int rowl[100][2]={0};
		int coll[100][2]={0};
		printf("Case #%d: ",t);
		scanf(" %d %d",&n,&m);
		i=0;
		while(i<n)
		{
			j=0;
			while(j<m)
			{
				scanf(" %d",&a[i][j]);
				if(rowl[i][1]<a[i][j])
					rowl[i][1]=a[i][j];
				if(rowl[i][0]==0 || rowl[i][0]>a[i][j])
					rowl[i][0]=a[i][j];
				if(coll[j][1]<a[i][j])
					coll[j][1]=a[i][j];
				if(coll[j][0]==0 || coll[j][0]>a[i][j])
					coll[j][0]=a[i][j];
				j++;
			}
			i++;
		}
		i=0;
		while(i<n)
		{
			j=0;
			while(j<m)
			{
				if(!(rowl[i][1]==a[i][j] || coll[j][1]==a[i][j]))
				{
		//			printf("problem elem %d %d %d",i,j,a[i][j]);
					break;
				}
				j++;
			}
			if(j!=m)
				break;
			i++;
		}
		if(i!=n)
			puts("NO");
		else
			puts("YES");

		t++;
	}
	return 0;
}
