#include <stdio.h>
int ch[26];
int change()
{
	ch[0]=121;
	ch[1]=104;
	ch[2]=101;
	ch[3]=115;
	ch[4]=111;
	ch[5]=99;
	ch[6]=118;
	ch[7]=120;
	ch[8]=100;
	ch[9]=117;
	ch[10]=105;
	ch[11]=103;
	ch[12]=108;
	ch[13]=98;
	ch[14]=107;
	ch[15]=114;
	ch[16]=122;
	ch[17]=116;
	ch[18]=110;
	ch[19]=119;
	ch[20]=106;
	ch[21]=112;
	ch[22]=102;
	ch[23]=109;
	ch[24]=97;
	ch[25]=113;
	return 0;
}
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("output.out","w",stdout);
	int i,j,z,t;
	char g[101];
	change();
	scanf("%d",&t);
	gets(g);
	for(z=1;z<=t;z++)
	{
		printf("Case #%d: ",z);
		for(i=0;i<100;i++)
		{
			g[i]=0;
		}
		gets(g);
		for(i=0;i<100;i++)
		{
			j=(int)g[i];
			if(j==0)
			{
				break;
			}
			else if(g[i]==' ')
			{
				printf("%c",g[i]);
			}
			else
			{
				printf("%c",(char)ch[j-97]);
			}
		}
		printf("\n");
	}
	return 0;
}