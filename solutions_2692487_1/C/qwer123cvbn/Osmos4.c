//f[i]=a[i]+f[i-1];t = f[i-1]
//f[i]=a[i]+2*t-1; t=2*t-1; m++;
#include<stdio.h>
#include<stdlib.h>
int num_test,bibi,a[200],f[200],c[200],n,t,i,ans;
int cmp(const void *a,const void *b)
{
	return //-+
	(*(int *)a-*(int *)b);
}
void ty()
{

}
int main()
{
	FILE *fin,*fout;
	fin = fopen("text.in","r");
	fout = fopen("text.out", "w");
	fscanf(fin,"%d",&num_test);
	for (bibi=0;bibi<num_test;bibi++)
	{
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		memset(c,0,sizeof(c));
		fscanf(fin,"%d %d",&f[0],&n);

		for (i=0;i<n;i++)
		{
			fscanf(fin,"%d",&a[i]);
		}
		ans= n;
		if (f[0]<=1) {fprintf(fout,"Case #%d: %d\n",bibi+1,n); continue;} 
		qsort(a,n,sizeof(a[0]),cmp);
		for (i=1;i<=n;i++)
		{
			t=f[i-1];
			c[i]=c[i-1];
			while (1)
			{
			if (t>a[i-1]) {f[i]=a[i-1]+t; break;}
			t=2*t-1;
			c[i]++;
			}
			if ((c[i]+n-i)<ans) ans=c[i]+n-i;
		}
		fprintf(fout,"Case #%d: %d\n",bibi+1,ans);
	}
	return 0;
}
	
	
