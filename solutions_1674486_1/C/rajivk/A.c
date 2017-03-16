#include<stdio.h>
int array[1001][1001], arI[1001], M[1001], I[1001][11], flag1[1001], n, flag;
void recur(int s)
{
	if(flag)
		return;
	int i, j;
	for(i=1;i<=M[s];i++)
		array[s][I[s][i]]=1;
	for(i=1;i<=M[s];i++)
	{
		if(!flag1[I[s][i]])
			recur(I[s][i]);
		for(j=1;j<=n;j++)
		{
			if(array[I[s][i]][j])
			{
				if(array[s][j])
					flag=1;
				else
					array[s][j]=1;
			}
		}
	}
	flag1[s]=1;
}

int main()
{
	int i, j, k, t, f, T;
	scanf("%d", &T);
	for(t=0;t<T;t++)
	{
		flag=0;
		scanf("%d", &n);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				array[i][j]=0;
			flag1[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d", M+i);
			for(j=1;j<=M[i];j++)
				scanf("%d", &I[i][j]);
		}
		for(i=1;i<=n;i++)
			if(!flag1[i])
				recur(i);
		if(flag)
			printf("Case #%d: Yes\n", t+1);
		else
			printf("Case #%d: No\n", t+1);
	}
}
