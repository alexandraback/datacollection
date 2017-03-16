#include<cstdio>
#include<algorithm>
int p[1010];
int main()
{
		int T,n;
		FILE *in=fopen("in.txt","r");
		FILE *out=fopen("out.txt","w");
		fscanf(in,"%d",&T);
		for(int t=1;t<=T;t++)
		{
				fscanf(in,"%d",&n);
				for(int i=0;i<n;i++) fscanf(in,"%d",&p[i]);
				std::sort(p,p+n);
				int max=p[n-1];
				int ans=2147483647;
				for(int cut=1;cut<=max;cut++)
				{
						int tmp=0; 
						for(int i=0;i<n;i++)
						{
								if(p[i]<=cut) continue;
								int s=p[i]/cut;
								if(p[i]%cut!=0) s++;
								s--;
								tmp+=s;
						}
						tmp+=cut;
						if(ans>tmp) ans=tmp;
				}
				fprintf(out,"Case #%d: %d\n",t,ans);
		}
}
