#include<stdio.h>

int a[111][111], n, m;
int rmin[111], rmax[111], cmin[111], cmax[111];
int T;

int Go(void)
{
	int l1, l2;

	for(l1=0;l1<n;l1++) for(l2=0;l2<m;l2++)
	{
		if(a[l1][l2] < rmax[l1] && a[l1][l2] < cmax[l2])
		{
			return 0;
		}
	}
	return 1;
}

int main(void)
{
	int l1, l2, l0;
	
	scanf("%d",&T);
	for(l0=1;l0<=T;l0++)
	{
		scanf("%d %d",&n,&m);
		for(l1=0;l1<n||l1<m;l1++)
		{
			rmin[l1]=cmin[l1] = 1111;
			rmax[l1]=cmax[l1] = -1111;
		}
		for(l1=0;l1<n;l1++) for(l2=0;l2<m;l2++)
		{
			scanf("%d",&a[l1][l2]);
			if(a[l1][l2] < rmin[l1]) rmin[l1]=a[l1][l2];
			if(a[l1][l2] < cmin[l2]) cmin[l2]=a[l1][l2];
			if(a[l1][l2] > rmax[l1]) rmax[l1]=a[l1][l2];
			if(a[l1][l2] > cmax[l2]) cmax[l2]=a[l1][l2];
		}
		if(Go()) printf("Case #%d: YES\n",l0);
		else printf("Case #%d: NO\n",l0);
	}

	return 0;
}
