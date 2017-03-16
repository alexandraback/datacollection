#include <stdio.h>
#define N 105

int data[N][N];
int checkrow(int row,int m) {
	int j,d=data[row][0];
	for (j=0;j<m;j++)
		if (data[row][j]!=d)
			return 0;
	return 1;
}
int checkcol(int n,int col) {
	int i,d=data[0][col];
	for (i=0;i<n;i++)
		if (data[i][col]!=d)
			return 0;
	return 1;
}
int rowmax(int row,int m) {
	int max=0,j;
	for (j=0;j<m;j++)
		if (data[row][j]>max)
			max=data[row][j];
	return max;
}
int colmax(int n,int col) {
	int max=0,i;
	for (i=0;i<n;i++)
		if (data[i][col]>max)
			max=data[i][col];
	return max;
}
int check(int n,int m) {
	int i,j,rowstatus[N],colstatus[N],changeflag=1,max;
	for (i=0;i<n;i++)
		rowstatus[i]=checkrow(i,m);
	for (j=0;j<m;j++)
		colstatus[j]=checkcol(n,j);
	while (changeflag) {
		changeflag=0;
		for (i=0;i<n;i++) 
			if (!rowstatus[i]) {
				max=rowmax(i,m);
				for (j=0;j<m;j++)
					if (data[i][j]!=max&&!colstatus[j])
						break;
				if (j==m) {
					rowstatus[i]=1;
					changeflag=1;
				}
			}
		for (j=0;j<m;j++)
			if (!colstatus[j]) {
				max=colmax(n,j);
				for (i=0;i<n;i++)
					if (data[i][j]!=max&&!rowstatus[i])
						break;
				if (i==n) {
					colstatus[j]=1;
					changeflag=1;
				}
			}
	}

	for (i=0;i<n;i++)
		if (!rowstatus[i])
			return 0;
	for (j=0;j<m;j++)
		if (!colstatus[j])
			return 0;
	return 1;
}
int main() {
	freopen("d:\\c\\B-large.in","r",stdin);
	freopen("d:\\c\\B-large.out","w",stdout);
	int i,j,x,t,n,m;
	scanf("%d",&t);
	for (x=1;x<=t;x++) {
		scanf("%d%d",&n,&m);
		for (i=0;i<n;i++)
			for (j=0;j<m;j++)
				scanf("%d",&data[i][j]);
		printf("Case #%d: ",x);
		if (check(n,m))
			printf("YES");
		else
			printf("NO");
		if (x<t)
			printf("\n");
	}
	//while (1);
	return 0;
}

