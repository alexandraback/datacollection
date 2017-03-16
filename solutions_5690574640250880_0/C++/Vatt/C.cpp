#include <stdio.h>
int t;
int m,r,c,nub;
char ans[55][55];
bool tran,mark;
int main(int argc, char *argv[])
{
	scanf("%d",&t);
	for(int rr=1;rr<=t;rr++)
	{
		scanf("%d %d %d",&r,&c,&m);
		printf("Case #%d:\n",rr);
		mark=0;
		nub=0;
		m=r*c-m;
		if(m==1)
		{
			for(int i=1;i<=r;i++)
			{
				for(int j=1;j<=c;j++)
				{
					if(i==1 && j==1)
					{
						printf("c");
					}
					else printf("*");
				}
				printf("\n");
			}
		}
		else if(r==1)
		{
			for(int i=1;i<=c;i++)
			{
				if(i==1) printf("c");
				else if(i<=m) printf(".");
				else printf("*");
			}
			printf("\n");
		}
		else if(c==1)
		{
			for(int i=1;i<=r;i++)
			{
				if(i==1) printf("c\n");
				else if(i<=m) printf(".\n");
				else printf("*\n");
			}
		}
		else if(m==r*c)
		{
			for(int i=1;i<=r;i++)
			{
				for(int j=1;j<=c;j++)
				{
					if(i==1 && j==1)
					{
						printf("c");
					}
					else printf(".");
				}
				printf("\n");
			}
		}
		else if(m<=3 || m==5 || m==7) {
			printf("Impossible\n");
		}
		else if((r==2 || c==2) && (m&1)) {
			printf("Impossible\n");
		}
		else {
			tran=0;
			if(r>c) {
				r^=c;
				c^=r;
				r^=c;
				tran =1;
			}
			for(int i=1;i<=r;i++)
			{
				for(int j=1;j<=c;j++)
				{
					ans[i][j]='*';
				}
			}
			if(m<=2*c) {
				if(m&1) {
					if(r==2) {
						mark=1;
					}
					else {
						ans[1][1]='.';
						ans[1][2]='.';
						ans[1][3]='.';
						ans[2][1]='.';
						ans[2][2]='.';
						ans[2][3]='.';
						ans[3][1]='.';
						ans[3][2]='.';
						ans[3][3]='.';
						nub=9;
						for(int i=4;nub!=m;i++) {
							ans[1][i]='.';
							nub++;
							ans[2][i]='.';
							nub++;
						}
					}
				}
				else {
					for(int i=1;nub!=m;i++) {
						ans[1][i]='.';
						nub++;
						ans[2][i]='.';
						nub++;
					}
				}
			}
			else
			{
				int p;
				int nub=0;
				for(p=1;p*c<=m;p++) {
					for(int j=1;j<=c;j++) {
						ans[p][j]='.';
						nub++;
					}
				}
				if(nub+1==m) {
					if(p==3) {
						ans[p][1]='.';
						ans[p][2]='.';
						ans[p][3]='.';
						ans[p-1][c]='*';
						ans[p-2][c]='*';
					}
					else {
						ans[p][1]='.';
						ans[p][2]='.';
						ans[p-1][c]='*';
					}
				}
				else
				{
					for(int i=1;nub!=m;i++) {
						ans[p][i]='.';
						nub++;
					}
				}
			}
			ans[1][1]='c';
			if(mark) {
				printf("Impossible\n");
			}
			else if(tran) {
				for(int i=1;i<=c;i++)
				{
					for(int j=1;j<=r;j++)
					{
						printf("%c",ans[j][i]);
					}
					printf("\n");
				}
			}
			else
			{
				for(int i=1;i<=r;i++)
				{
					for(int j=1;j<=c;j++)
					{
						printf("%c",ans[i][j]);
					}
					printf("\n");
				}
			}
		}
	}
	return 0;
}
