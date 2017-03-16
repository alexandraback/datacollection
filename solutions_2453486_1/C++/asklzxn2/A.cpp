#include<cstdio>
int T,Case,i,j,flag;
char A[4][4],B[4];
bool Work()
{
	int i,F;
	F=1;
	for(i=0;i<4;++i)
		if(B[i]!='X'&&B[i]!='T')
			F=0;
	if(F)
	{
		printf("X won\n");
		return 1;
	}
	F=1;
	for(i=0;i<4;++i)
		if(B[i]!='O'&&B[i]!='T')
			F=0;
	if(F)
	{
		printf("O won\n");
		return 1;
	}
	return 0;
}
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	for(scanf("%d",&T);T--;)
	{
		++Case;
		for(i=0;i<4;++i) scanf("%s",A[i]);
		printf("Case #%d: ",Case);
		flag=1;
		for(i=0;i<4;++i)
			for(j=0;j<4;++j)
				if(A[i][j]=='.')
					flag=0;
		for(i=0;i<4;++i)
		{
			for(j=0;j<4;++j) B[j]=A[i][j];
			if(Work()) flag=2;
			if(flag==2) break;
			for(j=0;j<4;++j) B[j]=A[j][i];
			if(Work()) flag=2;
			if(flag==2) break;
		}
		if(flag!=2)
		{
			for(i=0;i<4;++i) B[i]=A[i][i];
			if(Work()) flag=2;
		}
		if(flag!=2)
		{
			for(i=0;i<4;++i) B[i]=A[i][3-i];
			if(Work()) flag=2;
		}
		if(flag==1) printf("Draw\n");
		if(flag==0) printf("Game has not completed\n");
	}
	return 0;
}
