#include<stdio.h>

int main(int argc,char *argv[])
{
	FILE *fp,*fp1;
	int T,ite;
	int N,S,p,r=0;
	int i,total,count;
	int s_l,ws_l;
	fp=fopen(argv[1],"r");
	fp1=fopen("output.txt","w");
	fscanf(fp,"%d",&T);
	for(ite=1;ite<=T;ite++)
	{	r=0;
		fscanf(fp,"%d%d%d",&N,&S,&p);
		s_l=3*p-4;
		if(s_l<=0)
			s_l=p;
		ws_l=3*p-2;
		if(ws_l<=0)
			ws_l=p;
		for(i=0;i<N;i++)
		{
			fscanf(fp,"%d",&total);

			if(total>=ws_l)
				r++;
			else if(total>=s_l)
			{
				if(S>0)
				{
					S--;
					r++;
				}
			}
		}
		fprintf(fp1,"Case #%d: %d\n",ite,r);
	}
	return 1;
}
