#include<cstdio>
char x[1010];
int main()
{
		int T,S_max;
		FILE *in=fopen("in.txt","r");
		FILE *out=fopen("out.txt","w");
		fscanf(in,"%d",&T);
		for(int t=1;t<=T;t++)
		{
				fscanf(in,"%d%s",&S_max,x);
				int num=0,ans=0;
				for(int i=0;i<=S_max;i++)
				{
						if(num<i) 
						{
								ans+=(i-num);
								num=i;
						}
						num+=(x[i]-48); 
				}
				fprintf(out,"Case #%d: %d\n",t,ans);
		}
}
