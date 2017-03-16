#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int a,b;
float p[100005];
int main()
{
	int t;
	scanf("%d",&t);
	for(int it=0;it<t;it++)
	{
		scanf("%d %d",&a,&b);
		for(int i=0;i<a;i++)scanf("%f",&p[i]);
		float t[4],sisa;
	
		for(int i=0;i<4;i++)t[i]=1;
		for(int i=0;i<a;i++)t[0]*=p[i];
		
		
		for(int i=0;i<a-1;i++)t[1]*=p[i];
		t[1]*=(1-p[a-1]);
	
		if(a>=2)
		{
			for(int i=0;i<a-2;i++)t[2]*=p[i];
			t[2]*=(1-p[a-2]);
			t[2]*=p[a-1];
		
			for(int i=0;i<a-2;i++)t[3]*=p[i];
			t[3]*=(1-p[a-2]);
			t[3]*=(1-p[a-1]);
			
		}
		else t[2]=t[3]=0;
		
		int dpn[4],blkg[4];
		dpn[0] = b-a+1;
		blkg[0] = dpn[0]+b+1;
		dpn[1]=dpn[0]+2;
		blkg[1]=dpn[1]+b+1;
		dpn[2] = dpn[1]+2;
		blkg[2]=dpn[2]+b+1;
		dpn[3]=blkg[3]=b+2;
		
	//	for(int i=0;i<4;i++)printf("%d %d\n",dpn[i],blkg[i]);
		
		float mini=10000000;
		float r[4];
		sisa = 1-t[0];
		r[0]=t[0]*dpn[0]+sisa*blkg[0];
		mini = min(mini,r[0]);
		sisa = 1-t[0]-t[1];
		r[1]=(t[0]+t[1])*dpn[1]+(sisa)*blkg[1];
		mini = min(mini,r[1]);
		sisa = 1-t[0]-t[1]-t[2]-t[3];
		r[2]=(t[0]+t[1]+t[2]+t[3])*dpn[2]+sisa*blkg[2];
		mini = min(mini,r[2]);
		r[3]=dpn[3];
		mini = min(mini,r[3]);
	//	for(int i=0;i<4;i++)printf("%f %d %f\n",t[i],i,r[i]);
		
		
		printf("Case #%d: %f\n",it+1,mini);
	}
	return 0;
}
