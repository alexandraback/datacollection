#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

struct queueinfo
{
	__int64 x;
	__int64 num;
	__int64 en;
};

queueinfo temp,tempin;
//int incnt,outcnt;
char chk[12][8][1002];
queue<queueinfo> qu;
/*
void push(queueinfo x)
{
	queue[incnt++]=x;
	if(incnt==10000002)
		incnt=0;
}
queueinfo pop()
{
	queueinfo x = queue[outcnt++];
	if(outcnt==10000002)
		outcnt=0;
	return x;
}
*/

int main()
{
	__int64 t,tcase,n,i,j,z;
	__int64 e,r,val[10002],re,maxe;

	FILE *in,*out;
	in=fopen("B-small-attempt5.in","r");
	out=fopen("output.txt","w");

	fscanf(in,"%I64d",&tcase);
	for(t=0;t<tcase;t++)
	{
		if(!qu.empty())
		{
			while(!qu.empty())
				qu.pop();
		}
		fscanf(in,"%I64d",&e);
		fscanf(in,"%I64d",&r);
		fscanf(in,"%I64d",&n);

		for(i=0;i<12;i++)
			for(z=0;z<8;z++)
				for(j=0;j<1002;j++)
					chk[i][z][j]=0;

		maxe=e;
		for(i=0;i<n;i++)
			fscanf(in,"%I64d",&val[i]);

		for(i=0;i<=e;i++)
		{
			temp.x=1;
			temp.num = val[0]*i;
			temp.en = e - i + r;
			if(temp.en > maxe) temp.en = maxe;
			qu.push(temp);
		}
		re = 0;
		while(1)
		{
			if(qu.empty())
				break;
			temp = qu.front();
			qu.pop();

			if(temp.x==n)
			{
				if(re<temp.num)
					re = temp.num;
				continue;
			}
			else
			{
				tempin = temp;
				if(temp.x == n-1)
				{
					tempin.num += val[tempin.x]*tempin.en;
					if(tempin.en > maxe) tempin.en = maxe;
					tempin.x++;
					qu.push(tempin);
				}
				else
				{
					for(i=0;i<=temp.en;i++)
					{
						tempin.num = temp.num + val[temp.x]*i;
						tempin.en = temp.en - i + r;
						if(tempin.en > maxe) tempin.en = maxe;
						tempin.x = temp.x+1;
						if(chk[tempin.x][tempin.en][tempin.num]==0)
						{
							chk[tempin.x][tempin.en][tempin.num]=1;
							qu.push(tempin);
						}
					}
				}
			}
		}
		fprintf(out,"Case #%I64d: %I64d\n",t+1,re);
	}

	return 0;
}