#include<cstdio>
#include<cstring>
int J, P, S;
void tmain()
{
	int K;
	scanf("%d%d%d%d",&J,&P,&S,&K);
	int XX=J*P*S;
	int maxv=0;
	int maxi=0;
	for(int i=1;i<(1<<XX);i++)
	{
		int qq= __builtin_popcount(i);
		if(qq<=maxv) continue;
		int aa[3][3][3];
		memset(aa,0,sizeof(aa));
		for(int j=0; j<XX;j++)
		{
			if(!((1<<j)&i)) continue;
			int AA=j%S;
			int BB=j/S%P;
			int CC=j/P/S;
			aa[0][AA][BB]++;
			aa[1][BB][CC]++;
			aa[2][CC][AA]++;
		}
		bool fuck=false;
		
		for(int ii=0; ii<3;ii++) for(int j=0; j<3;j ++) for(int k=0; k<3; k++)
		{
			if(aa[ii][j][k]>K)
			{
				fuck=true;
				goto nya;
			}
		}
		nya:
		if(fuck) continue;
		maxv=qq;
		maxi=i;
	}
	printf("%d\n",maxv);
	for(int j=0; j<XX;j++)
	{
		if(!((1<<j)&maxi)) continue;
		int AA=j%S;
		int BB=j/S%P;
		int CC=j/P/S;
		printf("%d %d %d\n",CC+1,BB+1,AA+1);
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1; i<=t; i++)
	{
		printf("Case #%d: ",i);
		tmain();
	}
}
