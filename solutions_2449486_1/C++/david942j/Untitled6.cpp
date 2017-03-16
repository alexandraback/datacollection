//by david942j
#include <cstdio>
const int N=110;
int A[N][N];
int n,m;
bool checkele(int x,int y)
{
	bool f1=false,f2=false;
	for(int i=0;i<n;i++)
		if(A[i][y]>A[x][y])
			f1=true;
	for(int j=0;j<m;j++)
		if(A[x][j]>A[x][y])
			f2=true;
	if(f1 && f2)return false;
	return true;
}
bool check()
{
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(!checkele(i,j))
				return false;
	return true;
}
int main()
{
	int T,w=1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				scanf("%d",&A[i][j]);
		printf("Case #%d: ",w++);
		if(check())puts("YES");
		else puts("NO");
	}
	scanf(" ");
}
/*
10 10
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 2 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 2 1
1 1 1 1 1 1 1 1 1 1
*/
