#include<cstdio>
#include<algorithm>
using namespace std;
int sz;
double a[1005],b[10005];
int marka[1005],markb[1005];
int find_num(double z)
{
	for(int i=0;i<sz;i++)
	{
		if(b[i]>z&&markb[i]==0) 
			{   markb[i]=1;
				return i;
			}
	}
   for(int i=0;i<sz;i++)
   {
   	if(markb[i]==0) return i;
   }
	
	
}

int find_large(double z)
{     
	for(int i=0;i<sz;i++)
   {
   	if(markb[i]==0&&z>b[i]) 
	   { markb[i]=1;
	   return i;
		}
   }

		for(int i=sz-1;i>=0;i--)
	{   //printf("in  %lf  %lf  %d\n",b[i],z,markb[i]);
		if(b[i]>z && markb[i]==0) 
			{   markb[i]=1;
				return i;
			}
	}
   
}
int main()
{
	int ntc;
	scanf("%d",&ntc);
	for(int tc=1;tc<=ntc;tc++)
	{  printf("Case #%d: ",tc);
			for(int i=0;i<1005;i++) marka[i]=0,markb[i]=0;
		
		scanf("%d",&sz);
		for(int i=0;i<sz;i++) scanf("%lf",&a[i]);
		for(int i=0;i<sz;i++) scanf("%lf",&b[i]);
		sort(a,a+sz);
		sort(b,b+sz);
		int ans1=0,ans2=0;
		for(int i=0;i<sz;i++)
		{
			int res=find_num(a[i]);
			if(b[res]<a[i]) ans1++;
		}
		
		for(int i=0;i<1005;i++) marka[i]=0,markb[i]=0;
		for(int i=0;i<sz;i++)
		{
			int res=find_large(a[i]);
			if(b[res]<a[i]) ans2++;
	
		}
			printf("%d %d\n",ans2,ans1);
			
	}
	
}
