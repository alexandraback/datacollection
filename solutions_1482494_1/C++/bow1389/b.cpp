#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;

int a[1005],b[1005],flag[1005];
int main()
{
	int t;
	scanf("%d",&t);
	for(int it=0;it<t;it++)
	{
		int n;
		scanf("%d",&n);
		memset(flag,0,sizeof(flag));
		int jum = 0;
		for(int i=0;i<n;i++)scanf("%d %d",&a[i],&b[i]);
		int star = 0;
		int tot = 0;
		int bisa = 1;
		while(jum!=n && bisa == 1)
		{
			int pos1,pos2,pos3;
			bisa =0;
			pos1=-1;
			pos2=-1;
			pos3=-1;
			for(int i=0;i<n;i++)
			{
				if(a[i]<=star&&flag[i]==0)
				{
					if(pos1==-1)pos1=i;
					else if(pos1!=-1 && b[pos1]<b[i])pos1=i;
				}
				if(b[i]<=star&&flag[i]==0)pos2=i;
				if(b[i]<=star&&flag[i]==1)pos3=i;
			}
			if(pos2!=-1)
			{
				star+=2;
				tot+=1;
				flag[pos2]=2;
				jum+=1;
				bisa = 1;
			//	printf("%d ",pos2);
			//	puts("pos2");
				
			}
			else if(pos3!=-1)
			{
				star+=1;
				tot+=1;
				flag[pos3]=2;
				jum+=1;
				bisa = 1;
				//	printf("%d ",pos3);
			//	puts("pos3");
			}
			else if(pos1!=-1)
			{
				star+=1;
				tot+=1;
				flag[pos1]=1;
				bisa = 1;
				//	printf("%d ",pos1);
			//	puts("pos1");
			}
			
		}
		if(jum==n)printf("Case #%d: %d\n",it+1,tot);
		else printf("Case #%d: Too Bad\n",it+1);
	}
	return 0;
}
