#include<stdio.h>
int main()
{
	FILE *ifp, *ofp;
	ofp = fopen("/home/dead/Desktop/fashRun4.out","w");
	ifp = fopen("/home/dead/Desktop/C-small-attempt4.in", "r");	
	int t, i, k, a, b, e, l, tmp, ptr=0, count=0;
	int c[3]={0};
	int d[3]={0};
	fscanf(ifp,"%d", &t);
	for(i=0; i<t; i++)
	{
		fscanf(ifp,"%d%d%d%d", &d[0], &d[1], &d[2], &k);		// 0=j, 1=p, 2=s;
		fprintf(ofp,"Case #%d: ", i+1);
		tmp=0;
		if(d[2]<=k)	fprintf(ofp,"%d\n", d[0]*d[1]*d[2]);
		else 		fprintf(ofp,"%d\n", d[0]*d[1]*k);
		if(d[2]<=k)	
		{
			for(a=1; a<=d[0]; a++)
			{
				for(b=1; b<=d[1]; b++)
				{
					for(e=1; e<=d[2] ; e++)
						fprintf(ofp,"%d %d %d\n", a,b,e);
				}
			}
		}
		else
		{
			for(a=1; a<=d[0]; a++)
			{
				for(b=1; b<=d[1]; b++)
				{
					while(tmp<k)
					{
						if(c[ptr]<k)	
						{
							fprintf(ofp,"%d %d %d\n", a,b,ptr+1);
							c[ptr]++;	tmp++;	count=0;	
						}
						else count++;
						ptr++;
						if(ptr==d[2]) ptr=0;
						if(count==d[2])	break;
					}
					tmp=0;	
					//if(ptr==d[2]) break;
				}
				c[0]=c[1]=c[2]=0;
				ptr=0;
			}
		}
	}
	fclose(ifp);
	fclose(ofp);
	return 0;
}
