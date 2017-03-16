#include<cstdio>
#include<algorithm>
using namespace std;
int ar[1004];
int fun(int a,int b)
{	
if(a<=b) return 0;
int ret=a/b;
if(a%b==0) ret--;

return ret;
}
int main()
{
	int ntc; scanf("%d",&ntc);
	for(int tc=1;tc<=ntc;tc++)
	{
		printf("Case #%d: ",tc);
		int D; scanf("%d",&D);
		for(int i=0;i<D;i++) scanf("%d",&ar[i]);
		sort(ar,ar+D);
		
		int ans=10000;
		for(int i=1;i<=1001;i++)
		{ 
			int aa=i;
			for(int j=0;j<D;j++)
			{  if(ar[j]<=i) continue;
		         aa+=fun(ar[j],i);         
			}
			if(aa<ans) ans=aa;
		}
		printf("%d\n",ans);
		
	}
}
