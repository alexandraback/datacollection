#include <stdio.h>
#include <string.h>

int main()
{
	int ncas;
	scanf("%d",&ncas);
	for(int t=1;t<=ncas;t++)
	{
		int y = 0;
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=a;i<=b;i++)
			for(int j=i+1;j<=b;j++)
			{
				char si[5],sj[5];
				sprintf(si,"%d",i);
				sprintf(sj,"%d",j);
				int slen = strlen(si);
				if(slen != strlen(sj)) continue;
				
				bool same = false;
				for(int j=1;j<slen;j++)
				{
					int k;
					for(k=0;k<slen;k++) if(si[k] != sj[(k+j)%slen]) break;
					if(k==slen) same = true;
				}
				if(same) y++;
			}
		printf("Case #%d: %d\n",t,y);
	}
	return 0;
}
