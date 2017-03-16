#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
	int t,tcase;
	int n,s,p,num[102];
	int div[102][3],chk[102];
	int i,j,z,re;

	FILE *in,*out;
	in=fopen("B-small-attempt1.in","r");
	out=fopen("output.txt","w");
	
	fscanf(in,"%d",&tcase);
	for(t=0;t<tcase;t++)
	{
		fscanf(in,"%d",&n);
		fscanf(in,"%d",&s);
		fscanf(in,"%d",&p);

		for(i=0;i<n;i++)
		{
			fscanf(in,"%d",&num[i]);
			if(num[i]%3==0)
			{
				div[i][0]=div[i][1]=div[i][2]=num[i]/3;
				if(div[i][0]>0)
				{
					div[i][0]--;
					div[i][2]++;
				}
			}
			else
			{
				div[i][0]=div[i][1]=(int)(num[i]/3);
				div[i][2]=num[i]-(div[i][0]*2);
				if(div[i][2]-div[i][0]==1 && div[i][0]>0)
				{
					div[i][0]--;
					div[i][1]++;
				}
			}
		}

		j=0;
		for(i=0;i<n;i++)
		{
			if(div[i][2]-div[i][0]==2)
				j++;
		}
		re=0;
		if(j==s)
		{
			for(i=0;i<n;i++)
			{
				if(div[i][2]>=p)
					re++;
			}
		}
		else if(j>s)
		{
			for(i=0;i<n;i++)
			{
				if(div[i][2]-div[i][0]==2 && div[i][2]-1>=p)
				{
					if(div[i][1]>div[i][0] && div[i][2]>0)
					{
						div[i][2]--;
						div[i][0]++;
						j--;
					}
					else if(div[i][1]==div[i][0] && div[i][2]>0)
					{
						div[i][2]--;
						div[i][1]++;
						j--;
					}

				}
				else if(div[i][2]-div[i][0] && div[i][2]==div[i][1] && div[i][2]>=p && div[i][1]>0)
				{
					div[i][1]--;
					div[i][0]++;
					j--;
				}
				else if(div[i][2]-div[i][0]==2 && div[i][2]<p)
				{
					if(div[i][1]>div[i][0] && div[i][2]>0)
					{
						div[i][2]--;
						div[i][0]++;
						j--;
					}
					else if(div[i][1]==div[i][0] && div[i][2]>0)
					{
						div[i][2]--;
						div[i][1]++;
						j--;
					}
					else if(div[i][2]==div[i][1] && div[i][1]>0)
					{
						div[i][1]--;
						div[i][0]++;
					}
				}
				if(j==s)
					break;
			}
			if(j>s)
			{
				for(i=0;i<n;i++)
				{
					if(div[i][2]-div[i][0]==2)
					{
						if(div[i][1]>div[i][0] && div[i][2]>0)
						{
							div[i][2]--;
							div[i][0]++;
							j--;
						}
						else if(div[i][1]==div[i][0] && div[i][2]>0)
						{
							div[i][2]--;
							div[i][1]++;
							j--;
						}
						else if(div[i][2]==div[i][1] && div[i][1]>0)
						{
							div[i][1]--;
							div[i][0]++;
						}
					}
					if(j==s)
						break;
				}
			}
			for(i=0;i<n;i++)
			{
				if(div[i][2]>=p)
					re++;
			}
		}
		fprintf(out,"Case #%d: %d\n",t+1,re);
	}

	return 0;
}