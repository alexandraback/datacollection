#include <stdio.h>

const int maxn = 1010;

int score[maxn+1][3];
bool done[maxn+1][3];
int n,result,star,goal;

FILE *fin=fopen("B.in","r"),
	*fout=fopen("B.out","w");

void init()
{
	int i;
	fscanf(fin,"%d",&n);
	for (i=1; i<=n; ++i)
	{
		fscanf(fin,"%d%d",&score[i][1],&score[i][2]);
		done[i][1]=done[i][2]=false;
	}
}

int gain(int j,int i)
{
	if (i==1)
		return 1;
	else if (done[j][1])
		return 2;
	else return 3;
}

void work()
{
	int i,j,bi,bj;
	goal=n;
	star=0;
	result=0;
	while (goal)
	{
		bi=bj=-1;
		for (i=2; i>=1; --i)
			for (j=1; j<=n; ++j)
			{
				if (done[j][i])
					continue;
				if ((i==1)&&(done[j][2]))
					continue;
				if (score[j][i]<=star)
				{
					if (((bi==-1)&&(bj==-1))||(gain(j,i)>gain(bj,bi)))
					{
						bi=i;
						bj=j;
					}
					else if ((gain(j,i)==gain(bj,bi))&&(i==1)&&(bi==1))
							if (score[j][2]>score[bj][2])
							{
								bj=j;
								bi=i;
							}
				}
			}
		if (bi==-1)
			break;
		
        done[bj][bi]=true;
		 if (bi==2)
			 --goal;
		 if ((bi==1)||(done[bj][1]))
			 star+=1;
		 else star+=2;
		 ++result;

	}
}

void output()
{
	if (goal>0)
		fprintf(fout,"Too Bad\n");
	else fprintf(fout,"%d\n",result);
}

int main()
{
	int t,i;
	fscanf(fin,"%d",&t);
	for (i=1; i<=t; ++i)
	{
		fprintf(fout,"Case #%d: ",i);
		init();
		work();
		output();
	}
	fclose(fin);
	fclose(fout);
	return 0;
}